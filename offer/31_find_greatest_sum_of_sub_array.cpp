/*
 * 连续子数组的最大和
 * O(n)
 */
#include <iostream>

bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int*, int);

int main() {
    int Data[8] = {1, -2, 3, 10, -4, 7, 2, -5};
    std::cout << FindGreatestSumOfSubArray(Data, 8) << std::endl;
    return 0;
}

int FindGreatestSumOfSubArray(int* pData, int nLength) {
    if ((pData == nullptr) || (nLength <= 0)) {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = pData[0];
    for (int i = 0; i < nLength; ++i) {
        if (nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];
        if (nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }
    return nGreatestSum;
}