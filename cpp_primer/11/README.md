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