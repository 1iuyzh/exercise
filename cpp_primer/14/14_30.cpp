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
    typedef vector<string>::size_type size_type;
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);

public:
    StrBlob();
    StrBlob(initializer_list<string> il);
    StrBlobPtr begin();
    StrBlobPtr end();
    vector<string>::size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;
    string& operator[](size_t);
    const string& operator[](size_t) const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {  }
StrBlob::StrBlob(initializer_list<string> il) : 
                data(make_shared<vector<string>>(il)) {  }
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
    return data->front();
}
string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data < *rhs.data;
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return rhs < lhs;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs > rhs);
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs < rhs);
}
string& StrBlob::operator[](size_t n) {
    check(n, "out of range");
    return data->at(n);
}
const string& StrBlob::operator[](size_t n) const {
    check(n, "out of range");
    return data->at(n);
}

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, vector<string>::size_type sz = 0) : wptr(a.data), curr(sz) { }
    string& deref() const;
    StrBlobPtr& incr();
    string& operator[](size_t);
    const string& operator[](size_t) const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    string& operator*() const;
    string* operator->() const;

private:
    weak_ptr<vector<string>> wptr;
    vector<string>::size_type curr;
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
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr > rhs.curr;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr <= rhs.curr;
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr >= rhs.curr;
}
StrBlobPtr& StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr& StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}
StrBlobPtr StrBlobPtr::operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
}
StrBlobPtr StrBlobPtr::operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
}
string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
string& StrBlobPtr::operator[](size_t n) {
    auto p = check(n, "out of range");
    return p->at(n);
}
const string& StrBlobPtr::operator[](size_t n) const {
    auto p = check(n, "out of range");
    return p->at(n);
}
string& StrBlobPtr::operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
string* StrBlobPtr::operator->() const {
    return &(this->operator*());
}

int main() {
    StrBlob s({"Dell", "Ali", "MS"});
    StrBlobPtr p(s);
    cout << *p << endl;
    cout << p->size() << endl;
    return 0;
}