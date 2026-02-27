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
    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long long norm1 = GCD(a,b), norm2 = GCD(c,d);
    a /= norm1;
    b /= norm1;
    c /= norm2;
    d /= norm2;
    long long den = LCM(b, d);
    long long num = a*(den/b) + c*(den/d);
    long long norm3 = GCD(num,den);
    num /= norm3;
    den /= norm3;
    std::cout << num << " " << den << "\n";
}