/*
Given a list of words, we may encode it by writing a reference string S and a list of indexes A.
For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].
Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.
What is the length of the shortest reference string S possible that encodes the given words?

Example:
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].

Note:
1 <= words.length <= 2000.
1 <= words[i].length <= 7.
Each word has only lowercase letters.
*/

#include<vector>
#include<string>
#include<map>
using std::vector;
using std::string;
using std::map;

class Solution {
private:
    struct tireNode {
        tireNode() = default;
        map<char, tireNode *> child;
    };

public:
    int minimumLengthEncoding(vector<string> &words) {
        tireNode *root = new tireNode();
        map<tireNode *, int> nodes;

        for (int i = 0; i < words.size(); ++i) {
            tireNode *cur = root;
            for (int j = words[i].size() - 1; j >= 0; --j) {
                if (cur->child.find(words[i][j]) == cur->child.end())
                    cur->child[words[i][j]] = new tireNode();
                cur = cur->child[words[i][j]];
            }
            nodes[cur] = i;
        }

        int num = 0;
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            if (it->first->child.empty())
                num += words[it->second].size() + 1;
        }
        
        return num;
    }
};