#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> city(10);
    for (size_t i=0; i<10; ++i) {
        std::cin >> city[i];
    }
    int shop = -1, m = 0;
    std::vector<int> dist(10, 100);
    for (int i=0; i<10; ++i) {
        if (city[i] == 2) { shop = i; }
        if (city[i] == 1 && shop != -1) { 
            dist[i] = i - shop;
        }
    }
    shop = -1;
    for (int i=9; i >= 0; --i) {
        if (city[i] == 2) { shop = i; }
        if (city[i] == 1 && shop != -1) { 
            dist[i] = std::min(shop - i, dist[i]); 
        }
    }
    for (int i=0; i<10; ++i) {
        if (city[i] == 1) { m = std::max(dist[i], m); }
    }

    std::cout << m << "\n";
}

