#!/usr/bin/env python
import hello

a= 0xf1245ab3341ff3461818881767676819ee 
b= 0xffa24387539639853800bbecbcb494990

print('a in hex =', hex(a))
print('b in hex =', hex(b))
print('a+b in hex =', hex(a+b))
print('a-b in hex =', hex(a-b))
print('a*b in hex =', hex(a*b))
print('a/b in hex =', hex(a//b))
print('a%b in hex =', hex(a%b))

hello.hello()
