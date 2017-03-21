```c
// const
int i = 42;
const int ci = i; // legal
int j = ci; // legal
// const and reference
const int ci = 42;
int &r1 = ci; // illegal
int i = 42;
const int &r2 = i; // legal
// const and pointer
const int ci = 42;
int *p1 = &ci; // illegal
int i = 42;
const int *p2 = &i; // legal
```
## 2.3
32  
2^32-32  
32  
-32  
0  
0  
## 2.5
```c++
'a', L'a', "a", L"a"
10, 10u, 10L, 10uL, 012, 0xC
3.14, 3.14f, 3.14L
10, 10u, 10., 10e-2
```
(a) char, wchar_t  
(b) int, unsigned, long, unsigned long, oct, hex  
(c) double, float, long double  
(d) int, unsigned, double, double  
## 2.6
```c++
int month = 9, day = 7;
int month = 09, day = 07;
```
"int month = 09" is invalid  
## 2.9
```c++
std::cin >> int input_value;
int i = { 3.14 };
double salary = wage = 9999.99;
int i = 3.14;
```
(a) invalid  
(b) valid  
(c) invalid
```c++
double wage;
double salary = wage = 9999.99;
```
(d) valid and i = 3  
## 2.10
```c++
std::string global_str;
int global_int;
int main() {
    int local_int;
    std::string local_str;
}
```
global_str ""  
global_int 0  
local_int undefined  
local_str ""  
PS: local_str is a local variable which is uninitialized, but it has a value that is defined by the class  
## 2.11
```c++
extern int ix = 1024;   // definition 定义
int iy; // definition 定义
extern int iz;  // declaration 声明
```
## 2.13
```c++
int i = 42;
int main() {
    int i = 100;
    int j = i;
}
```
j = 100  
## 2.14
```c++
int i = 100, sum = 0;
for (int i = 0; i != 10; i++)
    sum += i;
std::cout << i << ' ' << sum << std::endl;
```
legal  
100 45  
## 2.15
```c++
int ival = 1.01;
int &rval1 = 1.01;
int &rval2 = ival;
int &rval3;
```
(a) valid  
(b) invalid  
(c) valid  
(d) invalid  
## 2.16
```c++
int i = 0, &r1 = i; double d = 0, &r2 = d;
r2 = 3.14159;
r2 = r1;
i = r2;
r1 = d;
```
(a) valid and d=3.14159  
(b) valid and d=0.0  
(c) valid  
(d) valid  
## 2.17
10 10  
## 2.19
引用必须初始化  
引用只能绑定到对象上, 引用不是对象, 所以不能定义引用的引用  
引用只是为对象起了一个别名, 可以用引用来赋值, 被赋值, 初始化等  
## 2.20
```c++
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```
i = i * i;  
## 2.21
```c++
int i = 0;
double *dp = &i;
int *ip = i;
int *p = &i;
```
(a) illegal  
(b) illegal  
(c) legel  
## 2.25
```c++
int *ip, i, &r = i;
int i, *ip = 0;
int *ip, ip2;
```
(a) ip is a pointer to int, i is an int, r is a reference to int i  
(b) i is an int, ip is a null pointer
(c) ip is a pointer to int, ip2 is an int  
## 2.27
```c++
int i = -1, &r = 0; // illegal, r must refer to an object
int *const p2 = &i2; // legal
const int i = -1, &r = 0; // legal
const int *const p3 = &i2; // legal
const int *p1 = &i2; // legal
const int &const r2; // illegal r2 is a reference that cannot be const
const int i2 = i, &r = i; // legal
```
## 2.28
```c++
int i, *const cp; // illegal, cp must initialize
int *p1, *const p2; // illegal, p2 must initialize
const int ic, &r = ic; // illegal, ic must initialize
const int *const p3; // illegal, p3 must initialize
const int *p; // legal, p is a pointer to const int
```
## 2.29
```c++
i = ic; // legal
p1 = p3; // illegal, p3 is a pointer to const int
p1 = &ic; // illegal, ic is a const int, p1 is a pointer to int
p3 = &ic; // illegal, p3 is a const pointer, "const int *const p3 = &ic" is legal
p2 = p1; // illegal, p2 is a const pointer
ic = *p3; // illegal, ic is a const int
```
## 2.30
```c++
const int v2 = 0; // v2 is top-level const
int v1 = v2; // v1 is a int
int *p1 = &v1, &r1 = v1; // p1 is a pointer, r1 is a reference
const int *p2 = &v2, *const p3 = &i, &r2 = v2; // p2 is low-level const, p3 is both top-level and low-level const, r2 is low-level const
```
## 2.31
```c++
r1 = v2; // legal, r1 refer to v1, v1 is an int, v2 is top-level const
p1 = p2; // illegal, p1 is a pointer to int, p2 is low-level const
p2 = p1; // legal
p1 = p3; // illegal
p2 = p3; // legal, both p2 and p3 are low-level const
```
## 2.33
```c++
int i = 0, &r = i;
auto a = r; // a is an int
const int ci = i, &cr = ci;
auto b = ci; // b is an int, ignore ci's top-level const
auto c = cr; // c is an int, cr is ci's alias
auto d = &i; // d is a pointer to int
auto e = &ci; // e is a pointer to const int
auto &g = ci; // g is a reference to const int
auto &h = 42; // error: h is not a reference to const
const auto &j = 42; // j is a reference to 42
auto k = ci, &l = i; // k is an int, l is a reference to int
auto &m = ci, *p = &ci; // m is a reference to const int, p is a pointer to const int
auto &n = i, *p2 = &ci; // error: n is a reference to int, p2 is a pointer to const int
```
```c++
a = 42; // legal. a is an int
b = 42; // legal, b is an int
c = 42; // legal, c is an int
d = 42; // illegal, d is a pointer to int, *p = 42
e = 42; // illegal, e is a pointer to const int, e = &42
g = 42; // illegal. g is a reference to const int
```
## 2.35
```c++
const int i = 42;
auto j = i; // j is an int
const auto &k = i; // k is a reference to const int
auto *p = &i; // p is a pointer to const int
const auto j2 = i, &k2 = i; // j2 is a const int, k2 is a reference to const int
```
## 2.36
```c++
int a = 3, b = 4;
decltype(a) c = a; // c is an int, c = 3
decltype((b)) d = a; // d is a reference to int, int &d = a
++c;
++d;
```
a = 4  
b = 4  
c = 4  
d = 4  
## 2.37
```c++
int a = 3, b = 4;
dectype(a) c = a;
decltype(a = b) d = a;
```
c is an int, c = 3  
d is an reference to int a  
## 2.38
auto:  
auto会忽略初始值的顶层const, 保留底层const, 如果希望auto是顶层const, 需要使用const auto  
auto &会保留初始值的顶层const, 得到的引用是底层const  
const auto &可以绑定字面值  
decltype():  
decltype()内是一个变量, 返回变量的类型, 包括顶层const和引用  
如果decltype()内是解指针、(变量)、赋值表达式时, 将得到引用类型  
