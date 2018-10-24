#include <iostream>
#include <cstring>

bool Increment(char *);
void PrintNumber(char *);

void Print1ToMaxOfNDigits(int n) {
    if (n <= 0)
        return;
    
    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!Increment(number))
        PrintNumber(number);
    
    delete [] number;
}

bool Increment(char *number) {
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = std::strlen(number);
    for (int i = nLength - 1; i >= 0; i--) {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;
        if (nSum >= 10) {
            if (i == 0)
                isOverflow = true;
            else {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

void PrintNumber(char* number) {
    int nLength = std::strlen(number);
    
    int i = 0;
    while (number[i] == '0')
        i++;
    
    while (i < nLength) {
        std::cout << number[i];
        i++;
    }
    std::cout << std::endl;
}

int main() {
    Print1ToMaxOfNDigits(3);
    return 0;
}