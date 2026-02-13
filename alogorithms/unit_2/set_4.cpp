#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<int, int> rep;
    std::vector<int> sizes;
    int n;
    std::cin >> n;
    for (size_t i=0; i<n; ++i) {
        int k, num;
        std::cin >> k;
        sizes.push_back(k);
        for (size_t j=0; j!=k; ++j) {
            std::cin >> num;
            ++rep[num];
        } 
    }
    int c=0;
    bool flag = true;
    for (const auto& [num, freq] : rep) {
        if (freq == n) {
            ++c;
        } else if (freq != 1) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "YES\n" << c << "\n";
        for (auto size : sizes) {
            std::cout << size - c << " ";
        }
    } else {
        std::cout << "NO\n";
    }
}