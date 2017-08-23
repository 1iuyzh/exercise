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
using std::weak_ptr;
using std::vector;
using std::string;
using std::make_shared;

class StrBlobPtr;
class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    // 将StrBlobPtr声明为友元类
    friend class StrBlobPtr;
    StrBlobPtr begin();
    StrBlobPtr end();
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

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, vector<string>::size_type sz = 0) : wptr(a.data), curr(sz) { }
    // 自定义操作符
    bool operator != (const StrBlobPtr& p) { return p.curr != curr; }
    string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
private:
    weak_ptr<vector<string>> wptr;
    vector<string>::size_type curr;
    // 检查成功, 返回一个指向vector<string>的shared_ptr
    shared_ptr<vector<string>> check(vector<string>::size_type, const string &) const;
};
shared_ptr<vector<string>> StrBlobPtr::check(vector<string>::size_type i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
StrBlobPtr StrBlob::begin() { 
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

int main() {
    // test
    StrBlob b({"Alpha", "Beta", "Delta"});
    for (StrBlobPtr p = b.begin(); p != b.end(); p = p.incr())
        cout << p.deref() << ' ';
    cout << endl;
    return 0;
}