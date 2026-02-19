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

    long long ans1 = a[n-1] * a[n-2] * a[n-3] * a[n-4];
    long long ans2 = a[0] * a[1] * a[n-1] * a[n-2];    
    long long ans3 = a[0] * a[1] * a[2] * a[3];   

    if (ans1 >= ans2 && ans1 > ans3) {
        std::cout << ans1 << "\n";
    } else if (ans2 > ans1 && ans2 > ans3) {
        std::cout << ans2 << "\n";
    } else {
        std::cout << ans3 << "\n";
    }
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <random>

// long long MFFast(int n, std::vector<long long> a) {
//     std::sort(a.begin(), a.end());

//     long long ans1 = a[n-1] * a[n-2] * a[n-3] * a[n-4];
//     long long ans2 = a[0] * a[1] * a[n-1] * a[n-2];    
//     long long ans3 = a[0] * a[1] * a[2] * a[3]; 
//     long long ans4 = a[0] * a[1] * a[n-3] * a[n-2];  

//     return std::max({ans1, ans2, ans3, ans4});
// }

// long long MFSlow(int n, std::vector<long long> a) {
//     long long maxx = a[0] * a[1] * a[2] * a[3];
//     for (size_t i=0; i<n-3; ++i) {
//         for (size_t j=i; j<n-2; ++j) {
//             for (size_t k=j; k<n-1; ++k) {
//                 for (size_t t=k; t<n; ++t){
//                     long long res = a[i] * a[j] * a[k] * a[t];
//                     maxx = std::max(maxx, res);
//                 }
//             }
//         }
//     }
//     return maxx;
// }

// void StressTest() {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(4, 10);
//     std::uniform_int_distribution<> dist(-10, 10);
//     std::vector<long long> data;

//     int it=0;
//     while (it != 100) {
//         ++it;
//         int n = dis(gen);
//         for (size_t i=0; i<n; ++i) {
//             long long num = dist(gen);
//             data.push_back(num);
//         }
//         auto res1 = MFFast(n, data);
//         auto res2 = MFSlow(n, data);
//         if (res1 != res2) {
//             std::cout << "Wrong answer: " << res1 << " " << res2 << "\n";
//             for (const auto& t : data) { std::cout << t << " "; }
//             return;
//         } else {
//             std::cout << "OK\n"; 
//         }

//     }
// }

// int main() {
//     StressTest();
// }