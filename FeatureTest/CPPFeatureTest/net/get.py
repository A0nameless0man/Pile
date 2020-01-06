import requests
import re
import sys
from pprint import pformat, pprint
from os.path import exists


def build_payload(user, passwd):
    return {'Login.Token1': user, 'Login.Token2': passwd, 'goto': 'balabala', 'gotoOnFail': 'balabala'}

def get(user = "",passwd = "" ):
    try:
        session = requests.session()

        resp = session.post(
            'http://my.nuist.edu.cn/userPasswordValidate.portal', data=build_payload(user, passwd))
        # print(resp)
        # print(resp.text)


        resp = session.get(
            'http://wlkt.nuist.edu.cn/(S(c3khz245zkj0t555tcnbnqip))/default_jz.aspx')
        # print(session.cookies)
        # print(resp.headers)
        # print(resp)
        # print(resp.text)
        # print(resp.url)

        wlkt_url = resp.url.split('))/')[0]+'))/Student/xsjbxx.aspx'
        # print(wlkt_url)

        resp = session.get(wlkt_url)
        # print(resp)
        resp.encoding = 'utf8'
        text = resp.text

        REGEX_STEP1 = '''学生基本信息查询[\s\S\n]+?(<tr[\s\S\n]+</tr>)'''
        text = re.findall(REGEX_STEP1, text)[0]
        REGEX_STEP2 = '''<td.+?>(?:<span.+?>)?(.+?)(?:</span>)?</td>'''
        td_list = re.findall(REGEX_STEP2, text)

        indices = {
            'id': 2,
            'name': 4,
            'major': 16,
            'college': 20,
            'class': 22
        }
        info = {k: td_list[v-1] for (k, v) in indices.items()}
    except:
        info = {
            'id': '',
            'name': '',
            'major': '',
            'college': '',
            'class': ''
        }
    return info


def main():
    inputFileName = "./account.txt"
    if exists(inputFileName):
        f = open(inputFileName)
        user = f.readline().strip()
        passwd = f.readline().strip()
    elif len(sys.argv) == 3:
        user = sys.argv[1]
        passwd = sys.argv[2]
    else:
        user = ''
        passwd = ''
    #print(user)
    #print(passwd)
    pprint(get(user,passwd))

if __name__ == "__main__":
    main()