#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> vec1;
    vec1.reserve(n);
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        vec1.push_back(num);
    }

    auto iter = std::unique(vec1.begin(), vec1.end());
    vec1.erase(iter, vec1.end());

    for (int i = 0; i < k; ++i) {
        int num;
        std::cin >> num;
        
        auto it1 = std::lower_bound(vec1.begin(), vec1.end(), num);
        if (it1 == vec1.end()) {
            std::cout << vec1.back() << "\n";
        } else if (it1 == vec1.begin()) {
            std::cout << *it1 << "\n";
        } else {
            auto it2 = std::prev(it1); 
            if (*it1 == *it2) {
                std::cout << *it1 << "\n";
            } else if (std::abs(num - *it1) == std::abs(num - *it2)) {
                std::cout << *it2 << "\n";
            } else if (std::abs(num - *it1) < std::abs(num - *it2)) {
                std::cout << *it1 << "\n";
            } else if (std::abs(num - *it1) > std::abs(num - *it2)) {
                std::cout << *it2 << "\n";
            }
        }

    }
}
// std::cout << num << ": " << *it1 << *it2 << " ";

// 6 11 1 1 4 4 8 120 1 2 3 4 5 6 7 8 63 64 65 
// 5 5 1 3 5 7 9 2 4 8 1 6 
// 10 10 -5 1 1 3 5 5 8 12 13 16 0 3 7 -17 23 11 0 11 15 7 

// 6 11 1 1 4 8 119 120 1 2 3 4 5 6 7 8 63 64 120