#include<iostream>
#include<memory>
#include<string>
#include<utility>
#include<initializer_list>
#include<algorithm>
#include<numeric>

using std::cin; using std::cout; using std::endl;
using std::allocator;
using std::string;
using std::pair;
using std::uninitialized_copy;
using std::initializer_list;

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(initializer_list<string>);
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();

    void push_back(const string&);
    void push_back(string&&);
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
void StrVec::chk_n_alloc() {
    if (size() == capacity())
        reallocate();
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::alloc_n_move(size_t new_cap) {
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
void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}
void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
void StrVec::push_back(string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}
void StrVec::reserve(size_t new_cap) {
    if (new_cap > capacity())
        alloc_n_move(new_cap);
}
void StrVec::resize(size_t n) {
    resize(n, string());
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
StrVec::StrVec(const StrVec &s) {
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
StrVec& StrVec::operator=(const StrVec &rhs) {
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
bool operator==(const StrVec &lhs, const StrVec &rhs) {
    return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

int main() {
    StrVec svec1({"Alpha", "Beta", "Delta"});
    StrVec svec2 = svec1;
    cout << (svec1 == svec2) << endl;
    return 0;
}