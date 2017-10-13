# -*- coding: utf-8 -*-
print(ord('A'))
print(ord('中'))
print(chr(66))
# print(chr(25991))   # 显示乱码
# print('\u4e2d\u6587')
s = 'ABC'
b = s.encode('utf-8')
print(b)
print(b.decode('utf-8'))
# s = '中文'
# b = s.encode('utf-8')
# print(b)
# print(b.decode('utf-8'))
print(len('ABC'))
print(len('中文'))

# 练习
s1 = 72
s2 = 85
r = 100 * (s2 - s1) / s1
print('%.1f%%' % r)