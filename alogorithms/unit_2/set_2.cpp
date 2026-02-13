#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> data;
    int n;
    std::cin >> n;
    for (size_t i=0; i<n; ++i) {
        int k, num;
        std::cin >> k;
        for (size_t j=0; j!=k; ++j) {
            std::cin >> num;
            data.insert(num);
        }
    }
    std::cout << data.size();
}