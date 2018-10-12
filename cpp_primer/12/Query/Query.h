#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include <sstream>
#include <iostream>

using std::vector;
using std::string;
using std::ifstream;
using std::shared_ptr;
using std::map;
using std::set;
using std::istringstream;
using std::ostream;

class QueryResult;

class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file; // 输入文件
    // 每个单词到它所在的行号的集合的映射
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :
    sought(s), lines(p), file(f) {}
private:
    string sought; // 查询单词
    shared_ptr<set<line_no>> lines; // 出现的行号
    shared_ptr<vector<string>> file; // 输入文件
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            // 如果单词不在wm中, 以之为下标在wm中添加一项
            auto &lines = wm[word];
            if (!lines)   
                lines.reset(new set<line_no>); // 分配一个新的set
            lines->insert(n); // 将此行号插入set中
        }
    }
}