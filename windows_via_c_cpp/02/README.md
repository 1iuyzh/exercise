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
#### "ShlWApi.h"
Windows提供了一组范围很广的字符串操作函数: StrCat, StrChr, StrCmp, StrCpy等, 作为操作系统的一个组成部分  
尽管这些函数与C++标准库里的字符串函数(如strcpy和wcscpy)很相似, 但是仍建议使用操作系统函数  
如前所述, 这些函数既有ANSI版本, 也有Unicode版本, 例如StrCatA和StrCatW
#### 编写符合ANSI和Unicode的应用程序
例如函数通常希望你在字符中传递一个缓存的大小, 而不是字节, 这意味着你不应该传递sizeof(szBuffer), 而应该传递(sizeof(szBuffer)/sizeof(TCHAR)). 另外, 如果需要为字符串分配一个内存块, 并且拥有该字符串中的字符数目, 那么需要按字节来分配内存, 应该调用malloc(nCharacters*sizeof(TCHAR))
#### Windows字符串函数
* 一组对Unicode字符串进行操作的函数
```cpp
lstrcat     //将一个字符串置于另一个字符串的结尾处
lstrcmp     //对两个字符串进行区分大小写的比较
lstrcmpi    //对两个字符串进行不区分大小写的比较
lstrcpy     //将一个字符串拷贝到内存中的另一个位置
lstrlen     //返回字符串的长度(按字符数来计量)
```
这些函数根据是否定义UNICODE调用Unicode版本或ANSI版本  
例如, 如果定义了UNICODE, lstrcat扩展为lstrcatW, 如果没有定义UNICODE, lstrcat扩展为lstrcatA
* CompareString函数  
```cpp
int CompareString(
    LCID lcid,
    DWORD fdwStyle,
    PCWSTR pString1,
    int cch1,
    PCWSTR pString2,
    int cch2
);
```
lcid用于设定语言ID(LCID), 用来标识一种特定的语言, 通过调用GetThreadString()得到当前线程的语言设置
* CharLower和CharUpper函数
```cpp
PTSTR CharLower(PTSTR pszString);
PTSTR CharUpper(PTSTR pszString);
```
既可以转换单个字符, 也可以转换以0结尾的字符串
* IsCharAlpha, IsCharAlphaNumeric, IsCharLower, IsCharUpper  
```cpp
BOOL IsCharAlpha(TCHAR ch);
BOOL IsCharAlphaNumeric(TCHAR ch);
BOOL IsCharLower(TCHAR ch);
BOOL IsCharUpper(TCHAR ch);
```
* printf函数  
如果定义了_UNICODE, printf函数便希望所有字符和字符串参数代表Unicode字符和字符串  
如果没有定义_UNICODE, printf函数便希望传递的字符和字符串是ANSI字符和字符串
```cpp
sprintf()
swprintf()
```