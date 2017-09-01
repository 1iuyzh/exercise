#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::map;

class IsInRange {
public:
    IsInRange(size_t lower, size_t upper) : _lower(lower), _upper(upper) { }
    bool operator()(const string &str) const {
        return str.size() >= _lower && str.size() <= _upper;
    }
    size_t lower_limit() const { return _lower; }
    size_t upper_limit() const { return _upper; }
private:
    size_t _lower;
    size_t _upper;
};

int main() {
    size_t lower = 1;
    auto uppers = { 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u };
    vector<IsInRange> predicates;
    for (auto upper : uppers)
        predicates.push_back(IsInRange(lower, upper));
    map<size_t, size_t> count_table;
    for (auto upper : uppers)
        count_table[upper] = 0;
    std::ifstream fin("../data/storyDataFile.txt");
    for (string word; fin >> word; )
        for (auto is_size_in_range : predicates)
            if (is_size_in_range(word))
                ++count_table[is_size_in_range.upper_limit()];
    
    for (auto pair : count_table)
        cout << "count in range [1, " << pair.first << "]: " << pair.second << endl;
    return 0;
}