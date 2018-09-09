#include <algorithm>
#include <iostream>

void PrintMatrixClockwisely(int** numbers, int columns, int rows) {
    if (numbers == nullptr || columns <= 0 || rows <= 0)
        return;
    int num = std::min(columns, rows) & 0x1 ? std::min(columns, rows) / 2 + 1 : std::min(columns, rows) / 2;

    for (int i = 0; i < num; i++)
        PrintMatrixInCircle(numbers, columns, rows, i);
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start) {
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    for (int i = start; i <= endX; i++) {
        int number = numbers[start][i];
        std::cout << number << ' ';
    }

    if (start < endY) {
        for (int i = start + 1; i <= endY; i++) {
            int number = numbers[i][endX];
            std::cout << number << ' ';
        }
    }

    if (start < endX && start < endY) {
        for (int i = endX - 1; i >= start; i--) {
            int number = numbers[endY][i];
            std::cout << number << ' ';
        }
    }

    if (start < endY && start < endY - 1) {
        for (int i = endY - 1; i >= start + 1; i--) {
            int number = numbers[i][start];
            std::cout << number << ' ';
        }
    }
}