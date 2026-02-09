#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int,size_t>> data;
    for (size_t i=0; i<n; ++i) {
        int num;
        std::cin >> num;
        data.push_back({num, i+1});
    }

    sort(data.begin(), data.end());

    std::pair<size_t, size_t> ans1 = {0,0}, ans2 = {0,0};
    for (size_t i=0; i<n; ++i) {
        for (size_t j=n; j > i; --j) {
            if (data[i].second < data[j].second) {
                ans1 = {data[i].second, data[j].second};
            }
        }
    }
    for (size_t i=n; i>0; --i) {
        for (size_t j=0; j<i; ++i) {
            if (data[i].second < data[j].second) {
                ans1 = {data[i].second, data[j].second};
            }
        }
    }
    std::cout << ans1.first << " " << ans1.second << "\n";
    std::cout << ans2.first << " " << ans2.second;
}

