#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

unordered_map<string, string> findChain (
    const unordered_map<string, vector<string>> &adjacentWords,
    const string &first, const string &second
) {
    unordered_map<string, string> previousWord;
    queue<string> q;

    q.push(first);

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        auto it = adjacentWords.find(current);

        const vector<string> &adj = it->second;
        for (const string &str : adj) {
            if (previousWord[str] == "") {
                previousWord[str] = current;
                q.push(str);
            }
        }
    }
    previousWord[first] = "";

    return previousWord;
}

vector<string> getChainFromPreviousMap(
    const unordered_map<string, string> &previous, const string &second
) {
    vector<string> result;
    auto &prev = const_cast<unordered_map<string, string> &>(previous);

    for (string current = second; current != ""; current = prev[current])
        result.push_back(current);
    
    reverse(begin(result), end(result));
    return result;
}