#include <iostream>
#include <random>
#include <algorithm>

int LastFibo(long long n) {
    if (n <= 1) {
        return n;
    }
    int old, prev=0, curr=1;
    for (size_t i=0; i<n-1; ++i) {
        old = prev;
        prev = curr;
        curr = (prev + old) % 10;
    }
    return curr;
} 

int LastOfPartSum (int n, int m) {
    int sum = 0;
    int prev = LastFibo(m%60);
    sum = (sum + prev)%10;
    if (m == n) {
        return sum;
    }
    int curr= LastFibo((m+1)%60);
    sum = (sum + curr)%10;
    for (size_t i=m+1; i<n; ++i) {
        int next = (curr + prev) % 10;
        sum = (sum + next) % 10;
        prev = curr;
        curr = next;
    }
    return sum%10;
}


int LastOfPartSumSlow(int n, int m) {
    long long sum = 0;
    for (size_t i=m; i<n+1; ++i) {
        sum += LastFibo(i);
    }
    return sum%10;
}

// int main() {
//     int n, m;
//     std::cin >> m >> n;
//     std::cout << LastOfPartSum (n,m);
// }

int LastDigOfSum(int n) {
    int ans = LastFibo((n+2)%60);
    if (ans == 0) {
        return 9;
    } else {
        return ans-1;
    }
}


void StressTest() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);

    int it=0;
    while (it < 1000) {
        ++it;
        int n = dis(gen), m = dis(gen);
        auto mmin = std::min(n,m), mmax = std::max(n,m);
        auto res1 = LastOfPartSum(mmax, mmin);
        auto res2 = LastOfPartSumSlow(mmax, mmin);
        if (res1 != res2) {
            std::cout << it << " " << "Wrong answer: " << res1 << " " << res2 << "\n";
            std::cout << "Example: " << mmin << " " << mmax << "\n";
            return;
        } else {
            std::cout << "OK\n"; 
        }
    }
}

int main() {
    StressTest();
    return 0;
}