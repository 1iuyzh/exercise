#include<iostream>
#include<list>
#include<mutex>
#include<thread>
#include<vector>
#include<algorithm>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find) {
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

int main() {
    unsigned long const num_threads = std::thread::hardware_concurrency();
    
    std::vector<std::thread> threads(num_threads);

    for (unsigned long i = 0; i < num_threads; ++i)
        threads[i] = std::thread(add_to_list, i);
    
    for (auto it = some_list.begin(); it != some_list.end(); it++)
        std::cout << *it << std::endl;
    
    return 0;
}