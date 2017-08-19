#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include <initializer_list>

using std::cin; using std::cout; using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::string;
using std::initializer_list;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //添加和删除元素
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    //元素访问
    string& front();
    string& back();
private:
    shared_ptr<vector<string>> data;
    //如果data[i]不合法, 抛出一个异常
    void check(size_type i, const string &msg) const;
};