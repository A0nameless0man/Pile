import logging
import os
from pathlib import Path
from typing import Dict,  Optional, Tuple
import requests
from lxml import etree
import argparse
from retry import retry
from multiprocessing import Pool
from functools import partial


class HTTPException(Exception):
    def __init__(self, args):
        self.args = args


@retry(delay=1, max_delay=30, backoff=2, tries=30, logger=logging.getLogger('retry'))
def deal_section(url: str) -> Dict[str, str]:
    logger = logging.getLogger("deal_section")
    logger.info("Fetching image url from section url: %s" % url)
    resp = requests.get(url)
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
    resp = requests.get(url)
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
        resp = requests.get(url)
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
    for image in images:
        logger.info("Downloading %s / %s", name, image)
        download_images(images[image], os.path.join(path, name, image+".jpg"))
    logger.info("Finish Downloading section url %s to %s" % (name, path))
    return


def download_section_s(path: str, x: Tuple[str, str]):
    return download_section(path, x[0], x[1])


def main():
    logging.basicConfig(
        level=logging.INFO, format="%(asctime)s %(levelname)s %(name)s %(message)s")
    logger = logging.getLogger()
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str)
    parser.add_argument("path", type=str)
    args = parser.parse_args()
    sections = deal_book(args.target)
    path = args.path
    # for section in sections:
    #     logger.info("Downloading %s",section)
    #     images = deal_section(sections[section])
    #     for image in images:
    #         logger.info("Downloading %s / %s",section,image)
    #         download_images(images[image],os.path.join(args.path,section,image+".jpg"))
    with Pool(16) as pool:
        pool.map(partial(download_section_s, path), sections.items())


if __name__ == "__main__":
    main()

"""
python3 ~/git-repos/github.com/A0nameless0man/Pile/Scrpit/Spider/com.dogemanga/wget-images.py "https://dogemanga.com/m/%E5%B0%8F%E6%A1%83%E5%B0%8F%E6%85%84-Love-Love%E7%89%A9%E8%AA%9E/b1I4KAah" /mnt/c/Users/HuGuang/Downloads/小桃小栗LoveLove物语
python3 ~/git-repos/github.com/A0nameless0man/Pile/Scrpit/Spider/com.dogemanga/wget-images.py "https://dogemanga.com/m/%E6%90%96%E6%9B%B3%E7%99%BE%E5%90%88/ezAev-ZJ" /mnt/c/Users/HuGuang/Downloads/搖曳百合
python3 ~/git-repos/github.com/A0nameless0man/Pile/Scrpit/Spider/com.dogemanga/wget-images.py "https://dogemanga.com/m/%E6%98%9F%E6%9C%9F%E4%B8%80%E7%9A%84%E4%B8%B0%E6%BB%A1/UlpyE4NI" /mnt/c/Users/HuGuang/Downloads/星期一的丰满

"""
