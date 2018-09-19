/*
 * 逆序对
 * O(nlogn)
 */
#include <iostream>
#include <memory>

int InversePairs(int*, int);
int InversePairsCore(int*, int*, int, int);

int main() {
    int data[4] = {7, 5, 6, 4};
    std::cout << InversePairs(data, 4) << std::endl;
    return 0;
}

int InversePairs(int* data, int length) {
    if (data == nullptr || length < 0)
        return 0;
    
    std::shared_ptr<int> sp(new int[length], [](int* p) {delete [] p;});
    auto copy = sp.get();

    for (int i = 0; i < length; ++i)
        copy[i] = data[i];
    
    int count = InversePairsCore(data, copy, 0, length - 1);
    
    return count;
}

int InversePairsCore(int* data, int* copy, int start, int end) {
    if (start == end) {
        copy[start] = data[start];
        return 0;
    }

    int length = (end - start) / 2;
    int left = InversePairsCore(copy, data, start, start + length);
    int right = InversePairsCore(copy, data, start + length + 1, end);

    //i初始化为前半段最后一个数字的下标
    int i = start + length;
    //j初始化为后半段最后一个数字的下标
    int j = end;

    int indexCopy = end;
    int count = 0;
    while (i >= start && j >= start + length + 1) {
        if (data[i] > data[j]) {
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        }
        else {
            copy[indexCopy--] = data[j--];
        }
    }

    for (; i >= start; --i)
        copy[indexCopy--] = data[i];
    for (; j >= start + length + 1; --j)
        copy[indexCopy--] = data[j];
    
    return left + right + count;
}