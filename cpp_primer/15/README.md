## 15.4
(a) illegal  
(b) legal  
(c) illegal
## 15.13
```cpp
class base() {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) override { print(os); os << ' ' << i; }
private:
    int i;
};
```
## 15.14
```cpp
base bobj;
base *bp1 = &bobj;
base &br1 = bobj;
derived dobj;
base *bp2 = &dobj;
base &br2 = dobj;
bobj.print();   // base::print()
dobj.print();   // derived::print()
bp1->name();    // bp1->base::name()
bp2->name();    // bp2->base::name()
br1.print();    // br1.base::print()
br2.print();    // br2.derived::print()
)
```
## 15.18
```cpp
Base *p = &d1;  // d1类型是Pub_Derv
// 合法, Pub_Derv是Base的公有继承
p = &d2;        // d2类型是Priv_Derv
// 不合法, Priv_Derv是Base的私有继承
p = &d3;        // d3类型是Prot_Derv
// 不合法, 必须是公有继承的派生类, 其向基类的转换可访问
p = &dd1;       // dd1类型是Derived_from_Public, Derived_from_Public是Pub_Derv的公有继承
// 合法
p = &dd2;       // dd2类型是Derived_from_Private, Derived_from_Private是Priv_Derv的公有继承
// 不合法
p = &dd3;       // dd3类型是Derived_from_Protected, 是Prot_Derv的公有继承
// 不合法
```
## 15.19
```cpp
void memfcn(Base &b) { b = *this; }
```
不管以什么方式继承, 派生类的成员函数和友元都能使用派生类到基类的转换  
Pub_Derv: legal  
Priv_Derv: legal  
Prot_Derv: legal  
如果D继承B的方式是公有的或受保护的, 则D的派生类的成员和友元可以使用D向B的类型转换  
Derived_from_Public: legal  
Derived_from_Private: illegal  
Derived_from_Protected: legal
