## 3.9
```c++
string s;
cout << s[0] << endl;
```
illegal, because s is empty  
## 3.11
```c++
const string s = "Keep out!";
for (auto &c : s) {/* ... */}
```
c is a reference to const char, which is low-level const  
## 3.12
```c++
vector<vector<int>> ivec; // legal
vector<string> svec = ivec; // illegal
vector<string> svec(10, "null"); // legal
```
## 3.14
```c++
vector<int> v1; // size:0, no value
vector<int> v2(10); // size:10, value:0
vector<int> v3(10, 42); // size:10, value:42
vector<int> v4{10}; // size:1, value:10
vector<int> v5{10, 42}; // size:2, value:10, 42
vector<string> v6{10}; // size:10, value:""
vector<string> v7{10, "hi}; // size:10, value:"hi"
```
## 3.27
```c++
unsigned buf_size = 1024;
int ia[buf_size]; // illegal, buf_size is not constant expression
int ia[4 * 7 - 14]; // legal
int ia[txt_size()]; // illegal, txt_size() is not constant expression
char st[11] = "fundamental"; // illegal, "fundamental"'s size is 12 not 11, '\0'
```
## 3.38
```c++
string sa[10]; // all elements are empty string
int ia[10]; // all elements are 0
int main() {
    string sa2[10]; // all elements are empty string
    int ia2[10]; // all elements are undefined
}
```