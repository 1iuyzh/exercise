## 11.9
```cpp
std::map<std::string, std::list<std::size_t>> m;
```
## 11.11
```cpp
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}
multiset<Sales_data, bool (*)(const Sales_data&, Sales_data const&)> bookstore(compareIsbn);
```
## 11.15
```cpp
map<int, vector<int>> m;
m.mapped_type; //vector<int>
m.key_type; //int
m.value_type; //pair<const int, vector<int>>
```
## 11.17
```cpp
copy(v.begin(), v.end(), inserter(c, c.end())); //legal
copy(v.begin(), v.end(), back_inserter(c)); //illegal, no 'push_back()' in set
copy(c.begin(), c.end(), inserter(v, v.end())); //legal
copy(c.begin(), c.end(), back_inserter(v)); //legal
```
## 11.18
std::map<std::string, size_t>::const_iterator
## 11.21
```cpp
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```
```cpp
while (cin >> word) {
    auto p = word_count.insert({word, 0}); //p is a pair
    p.first->second++; //size_t++
}
```