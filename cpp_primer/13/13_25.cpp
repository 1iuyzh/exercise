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
    // 拷贝构造函数, 类值拷贝shared_ptr
    StrBlob(const StrBlob &s) : data(make_shared<vector<string>>(*s.data)) { }
    // 拷贝赋值运算符
    StrBlob& operator=(const StrBlob &rhs) {
        // 自赋值
        data = make_shared<vector<string>>(*rhs.data);
        return *this;
    }
    // shared_ptr在销毁后会自己调用析构函数, 因此不需要定义析构函数释放内存
    vector<string>::size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;
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

int main() {
    // test
    StrBlob a({ "Alpha", "Beta", "Delta" });
    StrBlob b = a;
    StrBlob c;
    cout << a.back() << endl;
    cout << b.back() << endl;
    cout << "size of c: " << c.size() << endl;
    c = b;
    cout << "size of c: " << c.size() << endl;
    cout << c.front() << endl;
    return 0;
}