#include <iostream>
#include <cmath>

// void fastf(int a, int b, int c) {
//     if (a == 0) {
//         if ((b == c*c && c >= 0) || (b == 0 && c == 0)) {
//             std::cout << "MANY SOLUTIONS\n";
//         } else { std::cout << "NO SOLUTION\n"; }
//     } else {
//         if (c >= 0) {
//             int x = c*c - b;
//             if (x % a == 0) { std::cout << x/a << "\n"; }
//             else { std::cout << "NO SOLUTION\n"; }
//         }
//         else { std::cout << "NO SOLUTION\n"; }
//     }
// }

// void slowf (double a, double b, double c) {
//     for (double x=-100; x <= 100; ++x) {
//         if (sqrt(a*x + b) == c) {
//             std::cout << x << "\n";
//         }
//     }
// }

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    // double aa = a, bb = b, cc = c;
    if (a == 0) {
        if ((b == c*c && c >= 0) || (b == 0 && c == 0)) {
            std::cout << "MANY SOLUTIONS\n";
        } else { std::cout << "NO SOLUTION\n"; }
    } else {
        if (c >= 0) {
            int x = c*c - b;
            if (x % a == 0) { std::cout << x/a << "\n"; }
            else { std::cout << "NO SOLUTION\n"; }
        }
        else { std::cout << "NO SOLUTION\n"; }
    }
    
}