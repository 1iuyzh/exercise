#include<iostream>
#include<memory>
#include<string>
#include<utility>   // std::move

using std::cin; using std::cout; using std::endl;
using std::allocator;
using std::string;
using std::pair;
using std::uninitialized_copy;

// vector<string>的简化版本
class StrVec {
public:
    StrVec() : 
        elements(nullptr), first_free(nullptr), cap(nullptr) { } // allocator成员进行默认初始化
    StrVec(const StrVec&);  // 拷贝构造函数
    StrVec& operator=(const StrVec&);   // 拷贝赋值运算符
    ~StrVec();  // 析构函数
    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
private:
    allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;
    // 工具函数
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }   // 保证StrVec至少有容纳一个新元素的空间
    pair<string*, string*> alloc_n_copy(const string*, const string*);
        // 分配内存, 并拷贝一个给定范围的元素
    void free();    // 销毁元素并释放内存
    void reallocate();  // 在内存用完时分配新内存
};
void StrVec::push_back(const string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = first_free;
}
StrVec::~StrVec() {
    free();
}
StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = first_free;
    return *this;
}
void StrVec::reallocate() {
    // 新内存空间的大小
    auto newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;    // 新数组中下一个空闲位置
    auto elem = elements;   // 旧数组中下一位置
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

int main() {
    return 0;
}