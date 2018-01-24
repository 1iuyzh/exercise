思考:  
1. Windows API是怎么用C++实现的
2. 如何用C++与系统函数进行交互
## c++ 11 标准
#### 字符类型
* wchar_t  
宽字符类型
```cpp
L"我是宽字符"
```
* char16_t  
16位Unicode字符
```cpp
u"我是16位Unicode字符"
```
* char32_t  
32位Unicode字符
```cpp
U"我是32位Unicode字符"
```
#### C++字符串方法ANSI/Unicode版本
* ANSI版本  
"string.h"中定义的strcpy, strchr, strcat, strlen等函数, 不能正确处理Unicode字符串
* Unicode版本  
"string.h"中定义的wcscpy, wcschr, wcscat, wcslen等函数  
注意, 所有的Unicode函数均以wcs开头, wcs是宽字符串的英文缩写
## Windows系统函数
Windows2000以后, 调用Windows函数并给它传递一个ANSI字符串, 系统会先把字符串转换成Unicode, 然后再传递给操作系统  
如果希望函数返回ANSI字符串, 系统会先把Unicode字符串转换成ANSI字符串, 然后将结果返回给程序
## Windows头文件
#### _UNICODE/UNICODE
_UNICODE和UNICODE最好同时定义
#### "tchar.h"
"Tchar.h"头文件包含了一组宏, 帮助创建ANSI/Unicode通用源代码文件
* _tcscpy等宏  
"Tchar.h"中有一个宏称为_tcscpy, 如果在编译源代码时没有定义_UNICODE, 那么_tcscpy就会扩展为ANSI的strcpy函数; 如果定义了_UNICODE, _tcscpy将扩展为Unicode的wcscpy函数
```cpp
#ifdef _UNICODE
#define _tcscpy wcscpy
#else
#define _tcscpy strcpy
#endif
```
* TCHAR
```cpp
#ifdef _UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif
```
* _TEXT()  
等价于_T()
```cpp
#ifdef _UNICODE
#define _TEXT(x) L ## x
#else
#define _TEXT(x) x
#endif
```
#### “winnt.h"
Windows头文件定义的Unicode数据类型
* WCHAR  
Unicode字符
```cpp
typedef wchar_t WCHAR;
```
* PWSTR  
指向Unicode字符串的指针
```cpp
typedef WCHAR *PWSTR;
```
* PCWSTR  
指向一个常量Unicode字符串的指针
```cpp
typedef CONST WCHAR *PCWSTR;
```
* PTSTR/PCTSTR  
ANSI/Unicode通用数据类型
```cpp
#ifdef UNICODE
typedef LPWSTR PTSTR;
typedef LPCWSTR PCTSTR;
#else
typedef LPSTR PTSTR;
typedef LPCSTR PCTSTR;
#endif
```
#### "wtypes.h"
句柄是Windows用来标识被应用程序所建立或使用的对象的唯一整数, 句柄不是指针, 不能直接读取数据
```cpp
typedef void *HWND;
typedef void *HMENU;
typedef void *HACCEL;
typedef void *HBRUSH;
typedef void *HFONT;
typedef void *HDC;
typedef void *HICON;
typedef void *HRGN;
typedef void *HMONITOR;
```
#### "winuser.h"
* CreateWindowEx()有两个版本, 一个接受Unicode字符串, 另一个接受ANSI字符串
```cpp
HWND WINAPI CreateWindowExW(
    DWORD dwExStyle,        //窗口的扩展风格
    PCWSTR pClassName,      //指向注册类名的指针
    PCWSTR pWindowName,     //指向窗口名称的指针
    DWORD dwStyle,          //窗口风格
    int X,                  //窗口的水平位置
    int Y,                  //窗口的垂直位置
    int nWidth,             //窗口的宽度
    int nHeight,            //窗口的高度
    HWND hWindParent,       //父窗口的句柄
    HMENU hMenu,            //菜单的句柄或是子窗口的标识符
    HINSTANCE hInstance,    //应用程序实例的句柄
    PVOID pParam            //指向窗口的创建数据
);
HWND WINAPI CreateWindowExA(
    DWORD dwExStyle,
    PCSTR pClassName,
    PCSTR pWindowName,
    DWORD dwStyle,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    HWND hWindParent,
    HMENU hMenu,
    HINSTANCE hInstance,
    PVOID pParam
)
#ifdef UNICODE
#define CreateWindowEx CreateWindowExW
#else
#define CreateWindowEx CreateWindowExA
#endif
```
#### 过时的Windows函数
Windows　API中的某些函数, 比如WinExec和OpenFile等, 不接受Unicode字符串, 应该避免使用  
对应的, 建议使用CreateProcess和CreateFile函数来代替, 从系统内部讲, 老的函数完全可以调用新的函数
#### Windows字符串函数
Windows提供了一组范围很广的字符串操作函数, 作为操作系统的一个组成部分  
尽管这些函数与C++标准库里的字符串函数(如strcpy和wcscpy)很相似, 但是仍建议使用操作系统函数  
* "ShlWApi.h"  
StrCat, StrChr, StrCmp, StrCpy等  
如前所述, 这些函数既有ANSI版本, 也有Unicode版本, 例如StrCatA和StrCatW