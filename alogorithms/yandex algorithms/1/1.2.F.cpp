#include <iostream>


int main() {
    long long MAX = -10000000, MIN = 10000000;
    long long max1 = MAX, max2 = MAX, min1 = MIN, min2 = MIN, num;

    while (std::cin >> num) {
        if (num > max1 && num > 0) {
            max2 = max1;
            max1 = num;
        } else if (num >= max2 && num > 0) {
            max2 = num;
        } else if (num < min1 && num <= 0) {
            min2 = min1;
            min1 = num;
        } else if (num <= min2 && num <= 0) {
            min2 = num;
        }
    }

    long long mult1 = MAX, mult2 = MAX;
    if (max1 != MAX && max2 != MAX) { mult1 = max1 * max2; } 
    if (min1 != MIN && min2 != MIN) { mult2 = min1 * min2; } 

    if (mult1 == MAX && mult2 == MAX) {
        if (min1 != MIN) { std::cout << min1 << " "; }
        else if (min2 != MIN) { std::cout << min2 << " "; }

        if (max1 != MAX) { std::cout << max1 << " "; }
        else if (max2 != MAX) { std::cout << max2 << " "; }
    } else {
        if (mult1 > mult2) { std::cout << max2 << " " << max1 << "\n"; }
        else { std::cout << min1 << " " << min2 << "\n"; }
    }
}