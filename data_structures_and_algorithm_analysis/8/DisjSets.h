#ifndef __DISJ_SETS__
#define __DISJ_SETS__

#include<vector>
using std::vector;

class DisjSets {
public:
    explicit DisjSets(int numElements);

    int find(int x);
    void unionSets(int root1, int root2);

private:
    vector<int> s;
};

DisjSets::DisjSets(int numElements) : s(numElements, -1) {}

int DisjSets::find(int x) {
    if (s[x] < 0)
        return x;
    else
        return s[x] = find(s[x]); // 路径压缩
}

void DisjSets::unionSets(int root1, int root2) {
    if (s[root2] < s[root1]) // root2更深
        s[root1] = root2;
    else {
        if (s[root1] == s[root2]) // 深度相同, 更新高度
            --s[root1];
        s[root2] =root1; // root1为新的根
    }
}

#endif