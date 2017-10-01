#include<iostream>
#include<vector>
#include<list>
#include<string>
#include"Blob.h"
#include"BlobPtr.h"

int main() {
    Blob<std::string> b = { "aa", "bb", "cc" };
    std::cout << b.back() << std::endl;
    BlobPtr<std::string> bp(b);
    std::cout << *bp++ << std::endl;
    std::cout << *bp << std::endl;
    return 0;
}