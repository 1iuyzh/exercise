## 10.4
没有错误, double元素被转换为int再相加
## 10.7
(a)
```cpp
vector<int> vec; list<int> lst; int i;
while (cin >> i)
    lst.push_back(i);
vec.resize(lst.size());
copy(lst.begin(), lst.end(), vec.begin());
```
```cpp
vector<int> vec; list<int> lst; int i;
while (cin >> i)
    lst.push_back(i);
copy(lst.begin(), lst.end(), back_inserter(vec));
```
(b) 没有错误，但是vec.size()仍为0
```cpp
vector<int> vec;
vec.reserve(10);
fill_n(std::back_inserter(vec), 10, 0);
```
## 10.14
```cpp
[] (int i1, int i2) -> int { return i1 + i2 };
```
## 10.15
```cpp
[i1] (int i2) -> int { return i1 + i2 };
```
## 10.20
```cpp
count_if(words.cbegin(), words.cend(), [] (const string &word) -> bool { return word.size() > 6; });
```
## 10.21
```cpp
[&i] () -> bool { if(i) i--; else return --i ? fasle : true; };
```
## 10.24
```cpp
bind(check_size, _1, s1.size());
```
