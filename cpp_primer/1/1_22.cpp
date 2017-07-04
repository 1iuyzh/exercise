#include <iostream>
#include "Sales_item.h"

int main(void) {
    int i = 0;
    Sales_item all;
    if (std::cin >> all) {
        Sales_item item;
        while (std::cin >> item)
            all += item;
    }
    std::cout << all << std::endl;
    return 0;
}