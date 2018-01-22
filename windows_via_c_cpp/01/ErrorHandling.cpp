#include<windows.h>
#include<winerror.h>
#include<iostream>
using namespace std;

int func(int m) {
    if (m == 0)
        SetLastError(ERROR_NOT_SUPPORTED);
    else
        return true;
    return false;
}

void PrintErrorDescription() {
    LPVOID lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        GetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        //(LPTSTR) &lpMsgBuf,
        //这里应该是老版本遗留的一个问题,形参类型虽然为LPTSTR,但是当FORMAT_MESSAGE_ALLOCATE_BUFFER置位时,LocalAlloc()分配的缓冲区地址需要放在指针变量lpMsgBuf内,所以实参传入指针的指针
        reinterpret_cast<LPTSTR> (&lpMsgBuf),
        0,
        NULL
    );
    cout << reinterpret_cast<LPTSTR> (lpMsgBuf);
    LocalFree(lpMsgBuf);
}

int main() {
    if (!func(0)) {
        //cout << GetLastError() << endl;
        PrintErrorDescription();
    }
    else
        cout << "is true" << endl;
    return 0;
}