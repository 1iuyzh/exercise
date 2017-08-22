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
## 12