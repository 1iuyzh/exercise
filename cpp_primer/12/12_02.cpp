#include<initializer_list>
#include<memory>
#include<vector>
#include<string>

using std::initializer_list;
using std::shared_ptr;
using std::vector;
using std::string;
using std::make_shared;

class StrBlob {
public:
    StrBlob();
    StrBlob(initializer_list<string> il);
    // size()
    vector<string>::size_type size() const { return data->size(); }
    // empty()
    bool empty() const { return data->empty(); }
    // vector的push_back()返回void
    void push_back(const string &t) { data->push_back(t); }
private:
    shared_ptr<vector<string>> data;
};

// 初始值列表, make_shared<vector<string>>()返回一个指向默认初始化的vector<string>的shared_ptr
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {  }
// 用初始化列表il初始化vector<string>
// vector<string> vec(il);
StrBlob::StrBlob(initializer_list<string> il) : 
                data(make_shared<vector<string>>(il)) {  }