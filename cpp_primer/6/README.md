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
## 6.19
```c++
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
//Questions
calc(23.4, 55.1); // illegal
count("abcda", 'a'); // legal
calc(66); // legal
sum(vec.begin(), vec.end(), 3.8); // legal
```
## 6.24
```c++
void print(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```
const int ia[10] is actually same as const int*  
```c++
void print(const int (&ia)[10]) {
    /*...*/
}
```
## 6.32
```c++
int &get(int *arry, int index) {
    return arry[index];
}
int main() {
    int ia[10];
    for (int i = 0; i != 10; i++)
        get(ia, i) = i;
}
```
legal
