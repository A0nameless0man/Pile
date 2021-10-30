import os
from pathlib import Path
from typing import Dict, List
import requests
from lxml import etree
import argparse
from retry import retry

class HTTPException(Exception):
    def __init__(self,args):
        self.args = args

@retry(HTTPException,delay=1,max_delay=30,backoff=2)
def deal_section(url:str)->Dict[str,str]:
    resp = requests.get(url)
    if not resp.status_code == 200:
        raise HTTPException("not resp.status_code == 200")
    html = resp.text
    dom = etree.HTML(html)
    images_url = dom.xpath("//img[@data-src]/@data-src")
    images_name = dom.xpath("//img[@data-src]/@alt")
    if len(images_name) != len(images_url):
        raise Exception("len(images_name) != len(images_url)")
    res = dict()
    for i in range(len(images_name)):
        res[images_name[i]] = images_url[i]
    return  res

@retry(HTTPException,delay=1,max_delay=30,backoff=2)
def deal_book(url:str)->Dict[str,str]:
    resp = requests.get(url)
    if not resp.status_code == 200:
        raise HTTPException("not resp.status_code == 200")
    html = resp.text
    dom = etree.HTML(html)
    section_url = dom.xpath("//option/@value")
    section_name = dom.xpath("//option/text()")
    if len(section_name) != len(section_url):
        raise Exception("len(section_name) != len(section_url)")
    res = dict()
    for i in range(len(section_name)):
        res[section_name[i].strip()] = section_url[i]
    return  res


@retry(HTTPException,delay=1,max_delay=30,backoff=2)
def download_images(url:str,path:str):
    dir = os.path.dirname(path)
    Path(dir).mkdir(parents = True,exist_ok=True)
    with open(path,"wb") as f:
        resp = requests.get(url)
        if not resp.status_code == 200:
            raise HTTPException("not resp.status_code == 200")
        f.write(resp.content)
        f.flush()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target",type=str)
    parser.add_argument("path",type=str)
    args = parser.parse_args()
    sections = deal_book(args.target)
    print(sections)
    for section in sections:
        print(section)
        images = deal_section(sections[section])
        print(images)
        for image in images:
            print(image)
            download_images(images[image],os.path.join(args.path,section,image+".jpg")) 

if __name__ == "__main__":
    main()