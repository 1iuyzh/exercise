print(ord('A'))
print(ord('中'))
print(chr(66))
print(chr(25991))   # 显示乱码
print('\u4e2d\u6587')
s = 'ABC'
b = s.encode('utf-8')
print(b)
print(b.decode('utf-8'))
s = '中文'
b = s.encode('utf-8')
print(b)
print(b.decode('utf-8'))
print(len('ABC'))
print(len('中文'))