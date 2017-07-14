## 7.8
read函数需要修改Sales_data对象的数据成员  
print函数不需要修改Sales_data对象的数据成员
## 7.14
```c++
Sales_data() : bookNo(""), units_sold(0), revenue(0) {}
```
## 7.16
在类的定义中对于访问说明符出现的位置和次数没有限定
## 7.17
第一个访问说明符之前的成员默认访问权限不同
## 7.44
不合法，因为只有一个接受int的构造函数，没有默认构造函数
## 7.45
合法
## 7.48
什么也不会发生
## 7.49
(a) 正确  
(b) 错误，改成
```c++
Sales_data &combine(const Sales_data&)
```
(c) 错误，成员函数不能声明成const