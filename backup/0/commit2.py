# -*- coding: utf-8 -*-
# -*- author: gzzhang -*-
# -*- create: 2015-2-27 -*-

import os;
import sys;
import time;
import socket;
import urllib;
import urllib2;
import cookielib;

from PIL import Image;
import pytesseract;

def online_judge_vcode():
    filepath = "vcode.gif";
    path = "http://acm.xmu.edu.cn/JudgeOnline/vcode.php";
    try:
        socket.setdefaulttimeout(5);
        requ = urllib2.Request(path);
        resp = urllib2.urlopen(requ);
        data = resp.read();
        print resp.info();
        print len(data);
        handle = open(filepath, "wb");
        handle.write(data);
        handle.flush();
        handle.close();
        image = Image.open(filepath);
        print (pytesseract.image_to_string(image));
    except socket.timeout, e:
        print e;
    except urllib2.URLError, e:
        print e;
    except urllib2.HTTPError, e:
        print e;

online_judge_vcode();
raw_input("Pause");
sys.exit(0);

language = { ".cpp" : 1, ".c" : 2, ".java" : 3 };


def online_judge_login(username, password):
    cookiejar = cookielib.CookieJar();
    processor = urllib2.HTTPCookieProcessor(cookiejar);
    urllib2.install_opener(urllib2.build_opener(processor));

    path = "http://acm.xmu.edu.cn/JudgeOnline/login.php";
    data = "user_id=%s&password=%s&vcode=%s&submit=Submit" % (username, password, code);

    try:
        requ = urllib2.Request(path, data);
        requ.add_header('User-Agent', 'userAgentIE9');
        requ.add_header('Content-Type', 'application/x-www-form-urlencoded');
        requ.add_header('Cache-Control', 'no-cache');
        requ.add_header('Connection', 'Keep-Alive');
        requ.add_header('Accept', '*/*');
        print urllib2.urlopen(requ).info();
        for index, cookie in enumerate(cookiejar):
            print index, cookie;
        print "";
        print "";
    except socket.timeout, e:
        print e;
    except urllib2.URLError, e:
        print e;
    except urllib2.HTTPError, e:
        print e;


def online_judge_submit(filepath):
    filename = os.path.split(filepath)[1];
    splits = os.path.splitext(filename);
    if not language.has_key(splits[1]):
        return;
    print splits;

    with open(filepath) as handle:
        code = handle.read();
        path = "http://acm.xmu.edu.cn/JudgeOnline/submit.php";
        data = urllib.urlencode({"id" : splits[0],
                                 "language" : "1",
                                 "source" : code});
        try:
            socket.setdefaulttimeout(5);
            requ = urllib2.Request(path, data);
            urllib2.urlopen(requ);
        except socket.timeout, e:
            print e;
        except urllib2.URLError, e:
            print e;
        except urllib2.HTTPError, e:
            print e;

if __name__ == "__main__":
    username = "sxojure";
    password = "James.241178ZGZ";

    for i in range(len(sys.argv)):
        print sys.argv[i];

    if len(sys.argv) == 2:
        online_judge_login(username, password);
        online_judge_submit(sys.argv[1]);

    raw_input("Press enter to quit!");
