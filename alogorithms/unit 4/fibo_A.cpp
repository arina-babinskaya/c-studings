#include <iostream>
#include <vector>

long long Fibbonachi(int n) {
    if (n <= 1) {
        return n;
    }
    long long previous=0, current=1, old;
    for (size_t i=0; i<n-1; ++i) {
        old = previous;
        previous = current;
        current = old + previous;
    }
    return current;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << Fibbonachi(n);
}
