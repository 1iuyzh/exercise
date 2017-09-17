#include<iostream>

using std::cin; using std::cout; using std::endl;

class Base {
public:
    virtual void fcn() {
        cout << "Base::fcn() virtual" << endl;
    }
};

class D1 : public Base {
public:
    void fcn() {
        cout << "D1::fcn() override" << endl;
    };
    virtual void f2() {
        cout << "D1::f2() virtual" << endl;
    }
};

class D2 : public D1 {
public:
    void fcn(int i = 0) {
        cout << "D2::fcn(int)" << endl;
    }
    void fcn() {
        cout << "D2::fcn() override" << endl;
    }
    void f2() {
        cout << "D2::f2() override" << endl;
    }
};

int main() {
    Base bobj; D1 d1obj; D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();

    D1 *d1p = &d1obj; D2 *d2p = &d2obj;
    //bp2->f2();
    d1p->f2();
    d2p->f2();

    return 0;
}