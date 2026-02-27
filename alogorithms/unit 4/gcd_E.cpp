#include <iostream>
#include <algorithm>
#include <cstdlib>

int GCD(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while(a > 0 && b > 0) {
        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return std::max(a,b);
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (c %  GCD(a,b) == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}