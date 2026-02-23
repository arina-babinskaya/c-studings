#include <iostream>

int PeriodFibo(int m) {
    if (m <= 1) {
        return m;
    }
    int curr=0, next=1, period=0, old;
    while (true) {
        old = next;
        next = (curr + next) % m;
        curr = old;
        ++period;
        if (curr == 0 && next == 1) {
            return period;
        }
    }
}

int LastFiboMod(long long n, int m) {
    if (n <= 1) {
        return n;
    }
    int old, prev=0, curr=1;
    for (size_t i=0; i<n-1; ++i) {
        old = prev;
        prev = curr;
        curr = (prev + old) % m;
    }
    return curr;
} 

int main() {
    long long n;
    int m;
    std::cin >> n >> m;
    int period = PeriodFibo(m);
    std::cout << LastFiboMod(n%period,m);
}