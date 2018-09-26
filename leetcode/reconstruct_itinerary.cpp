/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.

Example 1:
Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

Example 2:
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
But it is larger in lexical order.
*/

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <map>
#include <algorithm>
using std::vector;
using std::string;
using std::pair;
using std::unordered_map;
using std::map;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> graph;
        for (const auto &ticket : tickets) {
            ++graph[ticket.first][ticket.second];
        }
        const string from{"JFK"};
        vector<string> res{from};
        routerHelper(from, tickets.size(), graph, res);
        return res;
    }
private:
    bool routerHelper(const string& from, const int cnt,
    unordered_map<string, map<string, int>>& graph, vector<string>& res) {
        if (cnt == 0)
            return true;
        for (auto &to : graph[from]) {
            if (to.second) {
                --to.second;
                res.emplace_back(to.first);
                if (routerHelper(to.first, cnt - 1, graph, res))
                    return true;
                res.pop_back();
                ++to.second;
            }
        }
        return false;
    }
};