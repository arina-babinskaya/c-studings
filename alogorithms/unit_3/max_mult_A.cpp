// #include <iostream>
// #include <queue>
// #include <random>
// #include <vector>

// int MaxMultQueue(int n, std::vector<int> d) {
//     std::priority_queue<int> data;
//     for (size_t i=0; i<n; ++i) {
//         data.push(d[i]);
//     }
//     int max1 = data.top();
//     data.pop();
//     int max2 = data.top();
//     return max1*max2;
// }

// int MaxMultUs(int n, std::vector<int> d) {
//     int max1=-100000, max2=-100000;
//     for (size_t i=0; i<n; ++i) {
//         if (d[i] > max1) {
//             max2 = max1;
//             max1 = d[i];
//         } else if (d[i] > max2) {
//             max2 = d[i];
//         }
//     }
//     return max1*max2;
// }

// void StressTest() {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(2, 2000000);
//     std::uniform_int_distribution<> dist(0, 2000000);
//     std::vector<int> data;

//     int it=0;
//     while (it < 1000) {
//         ++it;
//         int n = dis(gen);
//         for (size_t i=0; i<n; ++i) {
//             int num = dist(gen);
//             data.push_back(num);
//         }
//         auto res1 = MaxMultQueue(n, data);
//         auto res2 = MaxMultUs(n, data);
//         if (res1 != res2) {
//             std::cout << "Wrong answer: " << res1 << " " << res2 << "\n";
//             return;
//         } else {
//             std::cout << "OK\n"; 
//         }

//     }
// }

// int main() {
//     StressTest();
//     return 0;
// }


#include <iostream>
#include <vector>

long long MaxMultUs(long long n, std::vector<long long> d) {
    long long max1=-100000, max2=-100000;
    for (size_t i=0; i<n; ++i) {
        if (d[i] > max1) {
            max2 = max1;
            max1 = d[i];
        } else if (d[i] > max2) {
            max2 = d[i];
        }
    }
    return max1*max2;
}

int main() {
    long long n;
    std::vector<long long> data;
    std::cin >> n;
    for (size_t i=0; i<n; ++i) {
        long long num;
        std::cin >> num;
        data.push_back(num);
    }
    std::cout << MaxMultUs(n, data) << "\n";
}