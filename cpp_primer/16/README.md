## 16.17
class和typename在声明类型模板参数时可以互换  
在声明模板模板参数时只能用class  
当我们想告诉编译器一个名字表示一个类时, 只能用typename
## 16.18
```cpp
// a
template <typename T, U, typename V> void f1(T, U, V);
template <typename T, typename U, typename V> void f1(T, U, V);
// b
template <typename T> T f2 (int &T);
// c
inline template <typename T> T foo(T, unsigned int*);
template <typename T> inline T foo(T, unsigned int*);
// d
template <typename T> f4(T, T);
template <typename T> return_type f4(T, T);
// e
typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a); //Ctype覆盖之前的Ctype
```