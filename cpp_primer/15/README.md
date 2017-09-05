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