#include <iostream>

bool equal(double, double);
double PowerWithUnsignedExponent(double, unsigned int);

double Power(double base, int exponent) {
    if (equal(base, 0.0) && exponent < 0) {
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
        absExponent = (unsigned int)(-exponent);
    
    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;
    
    return result;
}

bool equal(double num1, double num2) {
    if ((num1 - num2) > -0.0000001 && (num1 - num2) < 0.0000001)
        return true;
    else
        return false;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1 == 1)
        result *= base;
    
    return result;
}

int main() {
    std::cout << Power(-2, -2) << std::endl;
    std::cout << Power(0, -2) << std::endl;
    return 0;
}