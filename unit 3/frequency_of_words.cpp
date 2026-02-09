#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>

int main() {
    size_t k;
    std::cin >> k;
    std::string word;
    std::unordered_map<std::string, int> words;
    while (std::cin >> word) {
        ++words[word];
    }

    std::vector<std::pair<std::string,int>> v(words.begin(), words.end());

    std::partial_sort(
        v.begin(),
        v.begin() + std::min(v.size(), k),
        v.end(),
        [](const auto& p1, const auto& p2) { return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first); }
    );

    for (size_t i=0; i < k && i < v.size(); ++i) {
        auto [word, freq] = v[i];
        std::cout << word << "\t" << freq << "\n";
    }
}