## 13.1
第一个参数是自身类型的引用, 且任何额外参数都有默认值的构造函数, 是拷贝构造函数  
当发生拷贝初始化时, 调用拷贝构造函数  
在以下几种情况下, 发生拷贝初始化:  
1. 用 = 定义变量
2. 将一个对象作为实参传递给一个非引用类型的形参
3. 从一个返回类型为非引用类型的函数返回一个对象
4. 用花括号列表初始化一个数组中的元素或聚合类中的成员
## 13.2
```cpp
Sales_data::Sales_data(Sales_data rhs);
```
当一个Sales_data对象b对另一个对象a进行拷贝初始化时, 会调用a的拷贝构造函数, 由于形参rhs不是引用类型, 则需要b对rhs进行拷贝初始化, 进而会调用rhs的拷贝构造函数, 以此反复, 陷入死循环
## 13.3
当拷贝一个StrBlob时, shared_ptr的use_count()会加1  
当拷贝一个StrBlobPtr时, weak_ptr的use_count()不发生变化, 因为shared_ptr没有变化, weak_ptr的use_count()返回的是shared_ptr的数量
## 13.4
哪些地方使用了拷贝初始化
```cpp
Point global;
Point foo_bar(Point arg) { // 1
    Point local = arg; // 2
    Point *heap = new Point(global); // 3
    *heap = local; // 不是初始化
    Point pa[ 4 ] = { local, *heap }; // 4, 5
    return *heap; // 6
}
```
## 13.5
[code](13_05.h)
## 13.6
拷贝赋值运算符是重载运算符的一种, 用来控制对象的赋值  
拷贝赋值的时候使用  
通常情况下, 合成拷贝运算符会把右侧运算对象的每个非static成语赋予左侧运算对象的对应成员  
没有定义拷贝赋值运算符时, 编译器会生成一个合成拷贝赋值运算符
## 13.9
析构函数是类的一个成员函数, 在对象销毁时调用, 用来释放对象使用的资源
## 13.12
```cpp
bool fcn(const Sales_data *trans, Sales_data accum) {
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn(); // 3
    // 不包括trans
}
```
## 13.14
输出三个a的msyn成员值  
[code](13_17_1.cpp)
## 13.15
输出三个不同的数值  
[code](13_17_2.cpp)
## 13.16
也是三个不同的数值, 但与13.15结果不同, 原因是13.15中函数f()的形参在调用时执行了拷贝构造函数, 也就是说13.15中一共执行了5次拷贝初始化, 而13.16只执行了2次  
[code](13_17_3.cpp)
## 13.19
需要拷贝构造函数, 拷贝赋值运算符, 不需要析构函数  
[code](13_19.cpp)