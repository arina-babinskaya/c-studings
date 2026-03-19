#include <iostream>
#include <algorithm>

int main() {
    int p, v, q, m;
    std::cin >> p >> v >> q >> m;

    long long l1 = p - v;
    long long r1 = p + v;
    long long l2 = q - m;
    long long r2 =q + m;

    long long len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;

    if (r1 < l2 || r2 < l1) {
        std::cout << len1 + len2 << "\n";
    } else {
        long long left = std::max(l1, l2);
        long long right = std::min(r1, r2);
        long long len = right - left + 1;
        
        std::cout << len1 + len2 - len << "\n";
    }
}