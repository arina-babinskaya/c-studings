#include <iostream>
#include <algorithm>

long long GCD(long long a, long long b) {
    while(a > 0 && b > 0) {
        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return std::max(a,b);
}

long long LCM(long long a, long long b) {
    return (a*b)/GCD(a,b);
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << LCM(a,b);
}