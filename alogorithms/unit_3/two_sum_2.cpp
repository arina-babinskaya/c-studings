#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int n, m;
    std::vector<int> a, b;
    std::cin >> n;
    for (size_t i=0; i<=n; ++i) {
        int num;
        std::cin >> num;
        a.push_back(num);
    }

    std::cin >> m;
    for (size_t i=0; i<=m; ++i) {
        int num;
        std::cin >> num;
        b.push_back(num);
    }

    std::cout << std::max(n,m) << "\n";
    int ia=0, ib=0;
    while (n>=0 && m>=0) {
        if (n == m) {
            std::cout << a[ia] + b[ib] << " ";
            --n;
            --m;
            ++ia;
            ++ib;
        } else if(n > m) {
            std::cout << a[ia] << " ";
            --n;
            ++ia;
        } else if(n < m) {
            std::cout << b[ib] << " ";
            --m;
            ++ib;
        }
    }
}