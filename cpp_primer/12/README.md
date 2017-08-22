## 12.1
```cpp
StrBlob b1;
{
    StrBlob b2 = { "a", "an", "the" };
    b1 = b2;
    b2.push_back("about");
}
```
b1包含4个元素  
b2被销毁，但b2内的vector<string>和b1共享
##