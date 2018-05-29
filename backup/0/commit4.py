# -*- coding: utf-8 -*-
# -*- author: gzzhang -*-
# -*- create: 2015-3-17 -*-

import os;
import sys;
import time;
import socket;
import urllib;
import urllib2;
import cookielib;

def online_judge_submit(filepath):
    filename = os.path.split(filepath)[1];
    splits = os.path.splitext(filename);
    print splits;
    if ".cpp" != splits[1]:
        return;

    with open(filepath) as handle:
        code = handle.read();
        path = "http://acm.xmu.edu.cn/JudgeOnline/submithandle.php";
        path = "http://acm.xmu.edu.cn/submithandle.php";
        data = urllib.urlencode({"prob_ID" : splits[0],
                                 "language" : "1",
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
    for i in range(len(sys.argv)):
        print sys.argv[i];

    if len(sys.argv) != 2:
        sys.exit(0);
    
    cookiejar = cookielib.CookieJar();
    processor = urllib2.HTTPCookieProcessor(cookiejar);
    urllib2.install_opener(urllib2.build_opener(processor));

    path = "http://acm.xmu.edu.cn/JudgeOnline/vcode.php";
    try:
        socket.setdefaulttimeout(5);
        requ = urllib2.Request(path);
        resp = urllib2.urlopen(requ);
        info = resp.info();
        data = resp.read();

        print "len(data) =", len(data);
        save = "1.png";
        handle = open(save, "wb");
        handle.write(data);
        handle.flush();
        handle.close();
        code = raw_input("code: ");
        for index, cookie in enumerate(cookiejar):
            print index, cookie;
        print "";
        print "";

        username = "sxojure";
        password = "James.241178ZGZ";
        path = "http://acm.xmu.edu.cn/JudgeOnline/login.php";
        data = "user_id=%s&password=%s&vcode=%s&submit=Submit" % (username, password, code);
        print data;
        try:
            requ = urllib2.Request(path, data);
            requ.add_header('User-Agent', 'userAgentIE9');
            requ.add_header('Content-Type', 'application/x-www-form-urlencoded');
            requ.add_header('Cache-Control', 'no-cache');
            requ.add_header('Connection', 'Keep-Alive');
            requ.add_header('Accept', '*/*');
            resp = urllib2.urlopen(requ);
            info = resp.info();
            data = resp.read();
            print len(data);
            print "";
            print "";
            online_judge_submit(sys.argv[1]);
        except socket.timeout, e:
            print e;
        except urllib2.URLError, e:
            print e;
        except urllib2.HTTPError, e:
            print e;
    except socket.timeout, e:
        print e;
    except urllib2.URLError, e:
        print e;
    except urllib2.HTTPError, e:
        print e;
    raw_input("Press enter to quit!");
