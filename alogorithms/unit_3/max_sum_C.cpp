// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstdlib>

// long long MaxMultUs(long long n, std::vector<long long> d) {
//     long long max1=d[0], max2=d[1], max3=d[2];
//     if (max2 > max1) { std::swap(max1, max2); }
//     if (max3 > max2) { std::swap(max3, max2); }
//     for (size_t i=3; i<n; ++i) {
//         if (d[i] > max1 || (max2 < 0 && d[i] <<)) {
//             max3 = max2;
//             max2 = max1;
//             max1 = d[i];
//         } else if (d[i] > max2) {
//             max3 = max2;
//             max2 = d[i];
//         } else if (d[i] > max3) {
//             max3 = d[i];
//         }
//     }
//     return max1*max2*max3;
// }

// int main() {
//     long long n;
//     std::vector<long long> data;
//     std::cin >> n;
//     for (size_t i=0; i<n; ++i) {
//         long long num;
//         std::cin >> num;
//         data.push_back(num);
//     }
//     std::cout << MaxMultUs(n, data) << "\n";
// }





#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    long long p1 = a[n-1] * a[n-2] * a[n-3];
    long long p2 = a[0] * a[1] * a[n-1];    

    std::cout << std::max(p1, p2) << "\n";
}


