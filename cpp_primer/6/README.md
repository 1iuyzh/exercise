## 6.6
parameter: local variable declared inside the function parameter list  
local parameter: variable defined inside a block  
local static variable: 局部静态对象在程序执行路径第一次经过对象定义语句时初始化, 并且直到程序终止才被销毁, 两次函数调用之间该对象仍存在  
## 6.16
```c++
bool is_empty(string &s) {
    return s.empty();
}
```
```c++
bool is_empty(const string &s) {
    return s.empty();
}
```