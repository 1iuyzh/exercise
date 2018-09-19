/*
 * 最小的k个数
 * O(nlogk)
 * 适合处理海量数据
 */
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

typedef std::multiset<int, std::greater<int>> Set;
typedef std::multiset<int, std::greater<int>>::iterator Iterator;
void GetLeastNumbers(const std::vector<int>& data, Set& leastNumbers, int k) {
    leastNumbers.clear();

    if (k < 1 ||data.size() < k)
        return;
    
    for (auto iter = data.begin(); iter != data.end(); ++iter) {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else {
            Iterator iterGreatest = leastNumbers.begin();
            if (*iter < *iterGreatest) {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}

int main() {
    std::vector<int> data{4, 5, 1, 6, 2, 7, 3};
    Set leastNumbers;
    GetLeastNumbers(data, leastNumbers, 4);
    for (auto iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        std::cout << *iter << ' ';
    return 0;
}