#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> rep;
    int n;
    std::cin >> n;
    for (size_t i=0; i<n; ++i) {
        int k, num;
        std::cin >> k;
        for (size_t j=0; j!=k; ++j) {
            std::cin >> num;
            ++rep[num];
        } 
    }
    int c=0;
    for (const auto& [num, freq] : rep) {
        if (freq == n) {
            ++c;
        }
    }
    std::cout << c << "\n";
}