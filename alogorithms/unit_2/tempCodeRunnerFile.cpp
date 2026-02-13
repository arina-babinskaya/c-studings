#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>

int main() {
    int n;
    std::unordered_map<int, int> data;
    std::cin >> n;
    for (size_t i=0; i<n; ++i) {
        int num;
        std::cin >> num;
        ++data[num];
    }



    std::set<int> ans;

    std::vector<std::pair<int, int>> vec(data.begin(), data.end());
    std::sort(vec.begin(), vec.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;  
        });

    // for (const auto& [num, freq] : vec) {
    //     std::cout << num << " " << freq << "\n";
    // }

    int c = 0;
    for (const auto& [num, freq] : vec) {
        ++c;
        ans.insert(num);
        if (c == 3) { break; }
    }

    for (const auto& num : ans) {
        std::cout << num << " ";
    }
}