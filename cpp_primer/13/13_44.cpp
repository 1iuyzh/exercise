#include<iostream>
#include<memory>
#include<utility>
#include<initializer_list>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::allocator;
using std::pair;
using std::uninitialized_copy;
using std::initializer_list;
using std::string;

// string简化版本
class String {
public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) { } // 默认构造函数
    String(const char*);    // 接受C风格字符串指针
    String(const String&);  // 拷贝构造函数
    String& operator=(const String&);   // 拷贝赋值运算符
    ~String();  // 析构函数

    void push_back(const char&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() const { return elements; }
    char* end() const { return first_free; }

    void reserve(size_t new_cap);
    void resize(size_t n);
    void resize(size_t n, const char&);

private:
    char *elements;
    char *first_free;
    char *cap;
    allocator<char> alloc;

private:
    void chk_n_alloc();
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void alloc_n_move(size_t new_cap);
    void free();
    void reallocate();
};
String::String(const char *rhs) {
    auto p = rhs;
    while (*p != '\0')
        p++;
    auto data = alloc_n_copy(rhs, p);
    elements = data.first;
    first_free = data.second;
    cap = first_free;
}
String::String(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    elements = data.first;
    first_free = data.second;
    cap = data.second;
}
String& String::operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = first_free;
    return *this;
}
String::~String() {
    free();
}
void String::push_back(const char &c) {
    chk_n_alloc();
    alloc.construct(first_free++, c);
}
void String::reserve(size_t new_cap) {
    if (new_cap > capacity())
        alloc_n_move(new_cap);
}
void String::resize(size_t n) {
    resize(n, 0);
}
void String::resize(size_t n, const char &c) {
    if (n > size()) {
        if (n > capacity())
            reserve(n * 2);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, c);
    } else if (n < size()) {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    }
}
void String::chk_n_alloc() {
    if (size() == capacity())
        reallocate();
}
pair<char*, char*> String::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
void String::alloc_n_move(size_t new_cap) {
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
void String::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
void String::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

int main() {
    String Str("Alpha");
    for (auto p = Str.begin(); p != Str.end(); p++)
        cout << *p;
    cout << endl;
    return 0;
}