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

if __name__ == "__main__":
    path = "http://acm.xmu.edu.cn/JudgeOnline/vcode.php";
    for i in range(10):
        try:
            socket.setdefaulttimeout(5);
            requ = urllib2.Request(path);
            resp = urllib2.urlopen(requ);
            info = resp.info();
            data = resp.read();
            print "len(data) =", len(data);
            save = "%d.png" % i;
            handle = open(save, "wb");
            handle.write(data);
            handle.flush();
            handle.close();
        except socket.timeout, e:
            print e;
        except urllib2.URLError, e:
            print e;
        except urllib2.HTTPError, e:
            print e;
