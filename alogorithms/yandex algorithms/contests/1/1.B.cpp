#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> kvant;
    for (size_t i=0; i<n; ++i) {
        int l, r, x;
        std::cin >> l >> r >> x;
        ++r;
        if (r > kvant.size()) { kvant.resize(r, 0); }
        --l;
        --r;
        bool ind = true;
        for (size_t j=l; j<r; ++j) {
            if (ind) {
                kvant[j] += x;
                ind = false;
            } else {
                kvant[j] -= x;
                ind = true;
            }
        }
    }

    std::vector<int> z(m);
    for (size_t i=0; i<m; ++i) {
        int num;
        std::cin >> num;
        --num;
        z[i] = num;
    }

    for (size_t i=0; i<m; ++i) {
        if (z[i] > kvant.size()) {
            std::cout << 0 << "\n";
        } else {
            std::cout << kvant[z[i]] << "\n"; 
        }
        
    }
}