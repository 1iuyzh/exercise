## 9.1
(a) list  
(b) deque  
(c) vector
## 9.2
std::list<std::deque<int>> v;
## 9.4
```cpp
bool f1(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value) {
    while (begin != end) {
        if (*begin == value)
            return true;
        begin++;
    }
    return false;
}
```
## 9.5
```cpp
auto f2(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value) {
    while (begin != end) {
        if (*begin == value)
            return begin;
        begin++;
    }
    return end;
}
```
## 9.7
vector<int>::size_type
## 9.8
list<string>::iterator  
list<string>::const_iterator
## 9.9
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```
it1: vector<int>::iterator  
it2: vector<int>::const_iterator  
it3: vector<int>::const_iteraotr  
it4: vector<int>::const_iterator
## 9.12
迭代器对: 允许类型转换, 可以范围拷贝  
容器: 不允许类型转换, 全部拷贝
## 9.28
```cpp
void f1(forward_list<string> &flst, string const &s1, string const &s2) {
    auto prev = flst.before_begin();
    for (auto curr = flst.begin(); curr != flst.end(); prev = curr++) {
        if (*curr == s1) {
            flst.insert_after(curr, s2);
            return;
        }
    }
    flst.insert_after(prev, s2);
}
```
## 9.30
默认构造
