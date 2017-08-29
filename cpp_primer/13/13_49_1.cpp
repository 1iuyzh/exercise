// 为StrVec添加移动构造函数和移动赋值运算符
#include<iostream>
#include<memory>
#include<string>
#include<utility>   // std::move
#include<initializer_list>

using std::cin; using std::cout; using std::endl;
using std::allocator;
using std::string;
using std::pair;
using std::uninitialized_copy;
using std::initializer_list;

// vector<string>的简化版本
class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { } // 默认初始化allocator
    StrVec(initializer_list<string>);
    StrVec(const StrVec&);  // 拷贝构造函数
    StrVec(StrVec&&) noexcept;       // 移动构造函数
    StrVec& operator=(const StrVec&);   // 拷贝赋值运算符
    StrVec& operator=(StrVec&&) noexcept;        // 移动赋值运算符
    ~StrVec();  // 析构函数

    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
    
    void reserve(size_t new_cap);
    void resize(size_t n);
    void resize(size_t n, const string&);

private:
    void chk_n_alloc();
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void alloc_n_move(size_t new_cap);
    void free();
    void reallocate();

private:
    allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;
};
void StrVec::chk_n_alloc() {    // StrVec是否有空间容纳新元素, 否则调用reallocate
    if (size() == capacity())
        reallocate();
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}   // 分配内存, 并拷贝给定范围的元素, 返回pair, first指向首元素, second指向尾后
void StrVec::alloc_n_move(size_t new_cap) { // 将StrVec移动到大小为new_cap的新空间内
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}
void StrVec::free() {   // 根据elements, first_free, cap释放allocator分配的内存
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
void StrVec::reallocate() { // 分配一个更大的内存, 释放旧内存
    // 新内存空间的大小
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}
void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
void StrVec::reserve(size_t new_cap) {    // 分配至少能容纳n个元素的空间
    // 只有当需要的内存空间大于当前容量时, reserve调用才会改变vector的容量
    if (new_cap > capacity())
        alloc_n_move(new_cap);
}
void StrVec::resize(size_t n) {
    resize(n, string());    // 新元素进行值初始化
}
void StrVec::resize(size_t n, const string &str) {
    if (n > size()) {
        if (n > capacity())
            reserve(n * 2);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, str);
    } else if (n < size()) {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    }
}
StrVec::StrVec(initializer_list<string> il) {
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
}
StrVec::StrVec(const StrVec &s) {   // 拷贝构造函数
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = first_free;
}
StrVec::StrVec(StrVec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
    rhs.elements = nullptr;
    rhs.first_free = nullptr;
    rhs.cap = nullptr;
}
StrVec& StrVec::operator=(const StrVec &rhs) {  // 拷贝赋值运算符
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = first_free;
    return *this;
}
StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.elements;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
StrVec::~StrVec() {
    free();
}
//test
int main() {
    StrVec vec({"Alpha", "Beta"});
    StrVec svec;
    svec = vec;
    //cout << *svec.begin() << endl;
    svec.push_back("Delta");
    for (auto p = svec.begin(); p != svec.end(); p++)
        cout << *p << ' ';
    cout << endl;
    cout << "size: " << svec.size() << endl;
    cout << "capacity: " << svec.capacity() << endl;
    svec.push_back("Alpha");
    svec.push_back("Beta");
    cout << "size: " << svec.size() << endl;
    cout << "capacity: " << svec.capacity() << endl;
    svec.reserve(6);
    cout << "size: " << svec.size() << endl;
    cout << "capacity: " << svec.capacity() << endl;
    svec.reserve(16);
    cout << "size: " << svec.size() << endl;
    cout << "capacity: " << svec.capacity() << endl;
    svec.resize(4);
    cout << "size: " << svec.size() << endl;
    cout << "capacity: " << svec.capacity() << endl;
    svec.resize(6, "Demo");
    cout << "size: " << svec.size() << endl;
    cout << "capacity: " << svec.capacity() << endl;
    for (auto p = svec.begin(); p != svec.end(); p++)
        cout << *p << ' ';
    cout << endl;
    return 0;
}