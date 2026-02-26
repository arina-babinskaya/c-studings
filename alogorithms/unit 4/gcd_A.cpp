#include <iostream>
#include <algorithm>

int GCD(int a, int b) {
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
    int a,b;
    std::cin >> a >> b;
    std::cout << GCD(a,b);
}