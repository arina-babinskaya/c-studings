#include <iostream>

int LastFibo(int n) {
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

int main() {
    int n;
    std::cin >> n;
    std::cout << LastFibo(n);
}