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


language = { ".cpp" : 1, ".c" : 2, ".java" : 3 };


def online_judge_login(username, password):
    cookiejar = cookielib.CookieJar();
    processor = urllib2.HTTPCookieProcessor(cookiejar);
    urllib2.install_opener(urllib2.build_opener(processor));

    path = "http://acm.xmu.edu.cn/login.server.php";
    data = "xjxfun=login&xjxr=%d&xjxargs[]=%s&xjxargs[]=%s" \
            % (int(time.time() * 1000), username, password);

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
        path = "http://acm.xmu.edu.cn/JudgeOnline/submithandle.php";
        path = "http://acm.xmu.edu.cn/submithandle.php";
        data = urllib.urlencode({"prob_ID" : splits[0],
                                 "language" : language.get(splits[1]),
                                 "source_code" : code});
        print data;
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
    username = "hello00";
    password = "123456";

    for i in range(len(sys.argv)):
        print sys.argv[i];

    if len(sys.argv) == 2:
        online_judge_login(username, password);
        online_judge_submit(sys.argv[1]);

    raw_input("Press enter to quit!");
