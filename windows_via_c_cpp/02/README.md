## c++ 11 标准
wchar_t: 宽字符类型
```cpp
L"我是宽字符"
```
char16_t: 16位Unicode字符
```cpp
u"我是16位Unicode字符"
```
char32_t: 32位Unicode字符
```cpp
U"我是32位Unicode字符"
```
## Windows API
#### Windows系统函数与Unicode
Windows2000以后, 调用Windows函数并给它传递一个ANSI字符串, 系统会先把字符串转换成Unicode, 然后再传递给操作系统  
如果希望函数返回ANSI字符串, 系统会先把Unicode字符串转换成ANSI字符串, 然后将结果返回给程序
#### _UNICODE/UNICODE
_UNICODE宏用于C运行期头文件  
UNICODE宏用于Windows头文件
#### Windows API ANSI/Unicode版本
* ANSI版本  
"string.h"中定义的strcpy, strchr, strcat, strlen等函数, 不能正确处理Unicode字符串
* Unicode版本  
"string.h"中定义的wcscpy, wcschr, wcscat, wcslen等函数  
注意, 所有的Unicode函数均以wcs开头, wcs是宽字符串的英文缩写
#### "Tchar.h"
"Tchar.h"头文件包含了一组宏, 帮助创建ANSI/Unicode通用源代码文件
* _tcscpy等宏
"Tchar.h"中有一个宏称为_tcscpy, 如果在编译源代码时没有定义_UNICODE, 那么_tcscpy就会扩展为ANSI的strcpy函数; 如果定义了_UNICODE, _tcscpy将扩展为Unicode的wcscpy函数
```cpp
#define _tcscpy wcscpy
#define _tcscpy strcpy
```
* TCHAR
```cpp
typedef wchar_t TCHAR;
typedef char TCHAR;
```
* _TEXT
```cpp
#define _TEXT(x) L ## x
#define _TEXT(x) x
```
#### Windows定义的Unicode数据类型
WCHAR: Unicode字符  
PWSTR: 指向Unicode字符串的指针  
PCWSTR: 指向一个恒定的Unicode字符串的指针  
PTSTR/PCTSTR: 既可以指ANSI字符串, 也可以指Unicode字符串, 取决于是否定义了UNICODE宏