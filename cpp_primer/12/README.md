## 12.1
```cpp
StrBlob b1;
{
    StrBlob b2 = { "a", "an", "the" };
    b1 = b2;
    b2.push_back("about");
}
```
b1包含4个元素  
b2被销毁, 但b2内的vector<string>和b1共享
## 12.3
不需要, 否则push_back()和pop_back()会尝试改变常量对象  
能不能加?
## 12.4
因为i的类型是vector<string>::size_type, 是unsigned的
## 12.8
```cpp
bool b() {
    int* p = new int;
    //...
    return p;
}
```
p被转换成bool类型, 意味着p指向的动态内存无法被释放
## 12.9
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<in>(100);
r2 = q2;
```
q指向的动态内存安全, r指向的动态内存发生泄漏  
r2和q2指向的动态内存安全, 没有内存泄漏
## 12.10
[code](12_10.cpp)
## 12.11
[code](12_11.cpp)
## 12.12
```cpp
auto p = new int();
auto sp = make_shared<int>();
process(sp); // legal, *sp is 0
process(new int()); // illegal, new int() can't convert to sp
process(p); // illegal
process(shared_ptr<int>(p)); // legal, but is a bad practice
```
## 12.13
sp指向的内存被提前释放
## 12.17
```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
IntP p0(ix); // int can not convert to unique_ptr
IntP p1(pi); // 可编译, 运行会报错, *pi不在动态内存内
IntP p2(pi2); // 可能会引发空悬指针, unique_ptr指针p2会释放pi2指向的内存
IntP p3(&ix); // 同2
IntP p4(new int(2048)); // legal
IntP p5(p2.get()); // 不合法, 两个unique_ptr指向同一块内存
```
## 12.25
```cpp
int *pa = new int[10];
```
delete [] pa;