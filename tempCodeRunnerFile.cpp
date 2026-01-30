#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <utility>
#include <vector>

int main() {
    std::unordered_map<std::string, int> dir;
    std::string word;
    size_t m,n;
    std::cin >> m >> n;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> word;
        if (word.size() < n) {
            continue;
        } else if (word.size() == n) {
            ++dir[word];
        } else if (word.size() > n) {
            for (size_t j = 0; j+n-1 < word.size(); j++) {
                ++dir[word.substr(j, j + n)];
            }
        }
    }

    std::vector<std::pair<std::string, int>> sorted(dir.begin(), dir.end());
    std::sort(
        sorted.begin(),
        sorted.end(),
        [](const auto& p1, const auto& p2) {
            return std::tie(p1.second, p2.first) > std::tie(p2.second, p1.first);
        }
    );  

    for (const auto& [word, num] : sorted) {
        std::cout << word << " - " << num << "\n";
    }
}