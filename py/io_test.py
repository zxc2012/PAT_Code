#!/usr/bin/python
# -*- coding:UTF-8 -*-

a=[1,2,3]
b=[4,5,6]
c=tuple(b)
a.append(c)
print(a)

class Nstr(int):
    def __init__(self):
        if isinstance(arg,str):
            self.total=0
            for each in arg:
                self.total+=ord(each)
        else :
            print("error")

    