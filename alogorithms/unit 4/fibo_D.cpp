#include <iostream>

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

int LastDigOfSum(int n) {
    int ans = LastFibo((n+2)%60);
    if (ans == 0) {
        return 9;
    } else {
        return ans-1;
    }
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << LastDigOfSum(n) << "\n";
}