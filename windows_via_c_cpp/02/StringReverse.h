#ifndef STRINGRESERVE
#define STRINGRESERVE

#include<tchar.h>
#include<windows.h>

#ifdef UNICODE
#define MyStringReverse MyStringReserveW
#else
#define MyStringReverse MyStringReserveA
#endif

BOOL MyStringReserveW(PWSTR pWideCharStr) {
    // Get a pointer to the last char in the string.
    PWSTR pEndOfStr = pWideCharStr + wcslen(pWideCharStr) - 1;
    wchar_t cCharT;
    // Repeat until we reach the center char in the string.
    while(pWideCharStr < pEndOfStr) {
        // Save a char in a temporary var.
        cCharT = *pWideCharStr;
        // Put the last char in the first char.
        *pWideCharStr = *pEndOfStr;
        // Put the temporary char in the last char.
        *pEndOfStr = cCharT;
        // Move in one char from the left.
        pWideCharStr++;
        // Move in one char from the right.
        pEndOfStr--;
    }
    // The string is reversed; return success.
    return (TRUE);
}

BOOL MyStringReserveA(PSTR pMultiByteStr) {
    PWSTR pWideCharStr;
    int nLenOfWideCharStr;
    BOOL fOk = FALSE;
    // Calculate the number of char needed to hold the wide-char version of the string.
    nLenOfWideCharStr = MultiByteToWideChar(CP_ACP, 0, pMultiByteStr, -1, NULL, 0);
    // Alloc memory from the process's default heap to accommodate the size of the wide-char string.
    // Don't forget that MultiByteToWideChar returns the number of char, not the numbers of bytes, so you must multiply by the size of a wide char.
    pWideCharStr = reinterpret_cast<PWSTR> (HeapAlloc(GetProcessHeap(), 0, nLenOfWideCharStr*sizeof(WCHAR)));
    if (pWideCharStr == nullptr)
        return (fOk);
    // Convert the multibyte string to a wide-char string.
    MultiByteToWideChar(CP_ACP, 0, pMultiByteStr, -1, pWideCharStr, nLenOfWideCharStr);
    // Call the wide-char vesion of this function to do the actual work.
    fOk = MyStringReserveW(pWideCharStr);
    if (fOk) {
        // Convert the wide-char string back to a multibyte string.
        WideCharToMultiByte(CP_ACP, 0, pWideCharStr, -1, pMultiByteStr, strlen(pMultiByteStr), NULL, NULL);
    }
    // Free the memory containing the wide-char string.
    HeapFree(GetProcessHeap(), 0, pWideCharStr);
    return (fOk);
}

#endif
