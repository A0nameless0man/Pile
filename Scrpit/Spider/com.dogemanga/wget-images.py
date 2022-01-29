import logging
import os
from pathlib import Path
from typing import Dict, List,  Optional, Tuple, Type
import requests
from lxml import etree
import argparse
from retry import retry
from multiprocessing import Pool, current_process
from multiprocessing.pool import MapResult, Pool as PoolType
from functools import partial
from tqdm import tqdm
from tqdm.contrib.logging import logging_redirect_tqdm


class HTTPException(Exception):
    def __init__(self, args):
        self.args = args


@retry(delay=1, max_delay=30, backoff=2, tries=30, logger=logging.getLogger('retry'))
def deal_section(url: str) -> Dict[str, str]:
    logger = logging.getLogger("deal_section")
    logger.info("Fetching image url from section url: %s" % url)
    resp = requests.get(url, timeout=(5, 10))
    if not resp.status_code == 200:
        raise HTTPException("not resp.status_code == 200")
    html = resp.text
    dom = etree.HTML(html)
    logger.info("Section html length: %d" % len(html))
    images_url = []
    images_name = []
    images_url.extend(dom.xpath("//img[@src and @site-page-index]/@src"))
    images_name.extend(dom.xpath("//img[@src and @site-page-index]/@alt"))
    images_url.extend(
        dom.xpath("//img[@data-src and @site-page-index]/@data-src"))
    images_name.extend(dom.xpath("//img[@data-src and @site-page-index]/@alt"))
    logger.info("Get %d images and %d url" %
                (len(images_name), len(images_url)))
    if len(images_name) != len(images_url):
        raise Exception("len(images_name) != len(images_url)")
    res = dict()
    for i in range(len(images_name)):
        res[images_name[i]] = images_url[i]
    return res


@retry(delay=1, max_delay=30, backoff=2, tries=30, logger=logging.getLogger('retry'))
def deal_book(url: str) -> Dict[str, str]:
    logger = logging.getLogger("deal_book")
    logger.info("Fetching book index from url: %s" % url)
    resp = requests.get(url, timeout=(5, 10))
    if not resp.status_code == 200:
        raise HTTPException("not resp.status_code == 200")
    html = resp.text
    logger.info("Book index html length: %d" % len(html))
    dom = etree.HTML(html)
    section_url = dom.xpath("//option/@value")
    section_name = dom.xpath("//option/text()")
    logger.info("Get %d sections and %d url" %
                (len(section_name), len(section_url)))
    if len(section_name) != len(section_url):
        raise Exception("len(section_name) != len(section_url)")
    res = dict()
    for i in range(len(section_name)):
        res[section_name[i].strip()] = section_url[i]
    return res


@retry(delay=1, max_delay=30, backoff=2, tries=30, logger=logging.getLogger('retry'))
def download_images(url: str, path: str):
    logger = logging.getLogger("download_images")
    logger.debug("Start Downloading images url %s to %s" % (url, path))
    dir = os.path.dirname(path)
    Path(dir).mkdir(parents=True, exist_ok=True)
    logger.debug("mkdir -P %s" % dir)
    with open(path, "wb") as f:
        resp = requests.get(url, timeout=(5, 10))
        if not resp.status_code == 200:
            raise HTTPException("not resp.status_code == 200")
        logger.debug("Image size = %d" % len(resp.content))
        f.write(resp.content)
        f.flush()
    return


@retry(delay=1, max_delay=30, backoff=2, tries=30, logger=logging.getLogger('retry'))
def download_section(path: str, name: str, url: str):
    logger = logging.getLogger("download_section")
    logger.info("Start Downloading section url %s to %s" % (name, path))
    Path(path).mkdir(parents=True, exist_ok=True)
    images = deal_section(url)
    n = current_process()._identity[0]
    for image in tqdm(images, "%d : %s" % (n, os.path.join(os.path.basename(path), name)), leave=False, position=n+2):
        logger.info("Downloading %s / %s", name, image)
        download_images(images[image], os.path.join(path, name, image+".jpg"))
        logger.info("Finished %s / %s", name, image)
    logger.info("Finish Downloading section url %s to %s" % (name, path))
    return


def download_section_s(path: str, x: Tuple[str, str]):
    return download_section(path, x[0], x[1])


def download_book(url: str, path: str, pool: PoolType, force: bool = False):
    logger = logging.getLogger("download_book")
    sections = deal_book(url)
    if not force:
        logger.info("incremental download is enabled")
        for k in list(sections.keys()):
            dir = os.path.join(path, k)
            if os.path.exists(dir):
                logger.info("Section %s already exists, skipping", k)
                del sections[k]
    # for section in sections:
    #     logger.info("Downloading %s",section)
    #     images = deal_section(sections[section])
    #     for image in images:
    #         logger.info("Downloading %s / %s",section,image)
    #         download_images(images[image],os.path.join(args.path,section,image+".jpg"))
    return pool.map_async(partial(download_section_s, path), sorted(sections.items()))


def download_books(targets: Dict[str, str], path: str, pool: PoolType, force: bool = False):
    promises: List[MapResult[None]] = []
    for item in tqdm(targets, leave=None, position=0):
        promises.append(download_book(
            targets[item], os.path.join(path, item), pool, force))
    for p in promises:
        p.wait()


def main():
    with logging_redirect_tqdm():
        with Pool(16) as pool:
            target = {
                "小桃小栗LoveLove物语": "https://dogemanga.com/m/%E5%B0%8F%E6%A1%83%E5%B0%8F%E6%85%84-Love-Love%E7%89%A9%E8%AA%9E/b1I4KAah",
                "搖曳百合": "https://dogemanga.com/m/%E6%90%96%E6%9B%B3%E7%99%BE%E5%90%88/ezAev-ZJ",
                "星期一的丰满": "https://dogemanga.com/m/%E6%98%9F%E6%9C%9F%E4%B8%80%E7%9A%84%E4%B8%B0%E6%BB%A1/UlpyE4NI",
                "3月的狮子": "https://dogemanga.com/m/3%E6%9C%88%E7%9A%84%E7%8D%85%E5%AD%90/GLursg_Z",
                "3月的狮子-单行本": "https://dogemanga.com/m/3%E6%9C%88%E7%9A%84%E7%8D%85%E5%AD%90-%E5%96%AE%E8%A1%8C%E6%9C%AC/w5CcDgbK",
                "摇曳露营":"https://dogemanga.com/m/%E6%91%87%E6%9B%B3%E9%9C%B2%E8%90%A5%E2%96%B3/5oQBx6WE",
                "摇曳编程":"https://dogemanga.com/m/%E6%91%87%E6%9B%B3%E7%BC%96%E7%A8%8B/dNRgizry",
                "这个美术部有问题":"https://dogemanga.com/m/%E8%BF%99%E4%B8%AA%E7%BE%8E%E6%9C%AF%E9%83%A8%E6%9C%89%E9%97%AE%E9%A2%98%EF%BC%81/kuwO_rOk",
                "轻音部的百合日常":"https://dogemanga.com/m/%E8%BD%BB%E9%9F%B3%E9%83%A8%E7%9A%84%E7%99%BE%E5%90%88%E6%97%A5%E5%B8%B8/uEQ3Ce1I",
                "轻音少女":"https://dogemanga.com/m/%E8%BC%95%E9%9F%B3%E5%B0%91%E5%A5%B3/wtFRm4P-",
                "AZUCAT (轻音少女!)":"https://dogemanga.com/m/AZUCAT-%28%E8%BD%BB%E9%9F%B3%E5%B0%91%E5%A5%B3%21%29/Ji3RDHBZ",
                "妖精森林的小不点":"https://dogemanga.com/m/%E5%93%88%E5%BA%93%E6%A2%85%E4%BC%8A%E4%B8%8E%E8%9C%9C%E7%8F%82%E6%9E%90/6maMCU18"
            }
            logging.basicConfig(
                level=logging.INFO, format="%(asctime)s %(levelname)s %(name)s %(message)s")
            # logger = logging.getLogger()
            parser = argparse.ArgumentParser()
            parser.add_argument("path", type=str)
            parser.add_argument("--force", type=bool, default=False)
            args = parser.parse_args()
            path = args.path
            download_books(target, path, pool, args.force)


if __name__ == "__main__":
    main()
