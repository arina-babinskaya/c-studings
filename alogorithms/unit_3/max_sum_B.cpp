#include <iostream>
#include <vector>
#include <algorithm>



long long MaxMultUs(long long n, std::vector<long long> d) {
    long long max1=d[0], max2=d[1], c = 0;
    if (max2 > max1) { 
        std::swap(max2, max1); 
        ++c;
    }
    for (size_t i=2; i<=n; ++i) {
        if (d[i] > max1) {
            max2 = max1;
            max1 = d[i];
        } else if (d[i] > max2) {
            max2 = d[i];
            ++c;
        }
        ++c;
    }
    return c;
}

int main() {
    long long n;
    std::vector<long long> data;
    std::cin >> n;
    data.push_back(n);
    for (long long i=1; i<n; ++i) {
        data.push_back(i);
    }
    auto res = MaxMultUs(n, data);
    if (res > 1.5 * n) {
        std::cout << "Yes" << "\n";
        for (const auto& n : data) { std::cout << n << " "; }
        std::cout << "\n";
    } else {
        std::cout << "No" << "\n";
    }

}
    