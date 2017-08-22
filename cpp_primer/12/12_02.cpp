#include<iostream>
#include<exception>
#include<initializer_list>
#include<memory>
#include<vector>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;
using std::vector;
using std::string;
using std::make_shared;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    // size()
    vector<string>::size_type size() const { return data->size(); }
    // empty()
    bool empty() const { return data->empty(); }
    // vector的push_back()返回void
    void push_back(const string &t) { data->push_back(t); }
    // 需要提前check()的操作
    void pop_back();
    // 不能在常量对象上调用非常量成员, 需要重载const版本
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;
private:
    shared_ptr<vector<string>> data;
    // push_back(), front(), back()访问元素前需要检查元素是否存在
    void check(size_type i, const string &msg) const;
};
// 初始值列表, make_shared<vector<string>>()返回一个指向默认初始化的vector<string>的shared_ptr
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {  }
// 用初始化列表il初始化vector<string>
// vector<string> vec(il);
StrBlob::StrBlob(initializer_list<string> il) : 
                data(make_shared<vector<string>>(il)) {  }
// check()函数, 接受一个string参数用于传递异常处理程序
void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    // vector<T>的front()和back()返回引用
    return data->front();
}
string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    // vector<T>的front()和back()返回引用
    return data->front();
}
const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

int main() {
    // test
    StrBlob b1;
    // initializer_list<T>必须在()中加上{}
    StrBlob b2({"Alpha", "Beta", "Gamma"});
    cout << "size of b1: " << b1.size() << endl;
    cout << "size of b2: " << b2.size() << endl;
    cout << "b1 is empty? " << b1.empty() << endl;
    cout << "b2 is empty? " << b2.empty() << endl;
    // out_of_range
    // cout << "b1's back: " << b1.back() << endl;
    // cout << "b2.back() " << b2.back() << endl;
    b1.push_back("Delta");
    b2.pop_back();
    cout << "b1.back() " << b1.back() << endl;
    cout << "b2.back() " << b2.back() << endl;
    const StrBlob b3({"Alpha", "Beta", "Gamma"});
    cout << "size of b3: " << b3.size() << endl;
    cout << "b3.back() " << b3.back() << endl;
    // const常量不能添加元素
    // b3.push_back("Delta");
    // cout << "b3's back: " << b3.back() << endl;
    return 0;
}