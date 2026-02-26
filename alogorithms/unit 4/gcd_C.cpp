// #include <iostream>
// #include <utility>
// #include <algorithm>
// #include <random>


// int Fibbonachi(int n) {
//     if (n <= 1) {
//         return n;
//     }
//     int previous=0, current=1, old;
//     for (size_t i=0; i<n-1; ++i) {
//         old = previous;
//         previous = current;
//         current = old + previous;
//     }
//     return current;
// }


// std::pair<int,int> MaxStep(int n) {
//     std::pair<int, int> ans = {0,0};
//     if (n != 0) {
//         for (size_t i=0; i<40; ++i) {
//             int a = Fibbonachi(i);
//             if (a >n) {
//                 ans.first = Fibbonachi(i-2);
//                 ans.second = Fibbonachi(i-1);
//                 break;
//             }
//         }
//     }
//     return ans;
// }

// int main() {
//     int n;
//     std::cin >> n;
//     auto ans = MaxStep(n);
//     std::cout << ans.first << " " << ans.second << "\n";
// }


// /*
// 6765 = 3 5 11 41
// 4181 = 37 113
// */


// int MaxStepCounter(int a, int b, int c) {
//     if (a == 0 || b == 0) {
//         return c;
//     }
//     ++c;
//     return  MaxStepCounter(b, a%b, c);
    
// }

// int MaxStepSlow(int n) {
//     int num1=0, num2=0, c=0, m=0;
//     if (n != 0) {
//         for (size_t i=0; i<=n; ++i) {
//             for (size_t j=i+1; j<=n; ++j) {
//                 int ans = MaxStepCounter(i,j,c);
//                 if (ans > m) {
//                     m = ans;
//                     num1 = std::min(i,j);
//                     num2 = std::max(i,j);
//                 }
//             }
//         } 
//     }
//     std::cout << num1 << " " << num2 << "\n";
//     // std::cout << num1 << " " << num2 << " " << m << "\n";
// }




// int main() {
//     long long n;
//     std::cin >> n;
    
//     // Находим два последних числа Фибоначчи ≤ n
//     long long a = 1, b = 1;
//     while (b <= n) {
//         long long next = a + b;
//         if (next > n) break;
//         a = b;
//         b = next;
//     }
    
//     std::cout << a << " " << b << "\n";
// }



#include <iostream>
#include <utility>

int Fibbonachi(int n) {
    if (n <= 1) {
        return n;
    }
    int previous=0, current=1, old;
    for (size_t i=0; i<n-1; ++i) {
        old = previous;
        previous = current;
        current = old + previous;
    }
    return current;
}


std::pair<int,int> MaxStep(int n) {
    std::pair<int, int> ans = {0,0};
    if (n != 0) {
        for (size_t i=1; i<60; ++i) {
            int a = Fibbonachi(i);
            if (a >n) {
                ans.first = Fibbonachi(i-2);
                ans.second = Fibbonachi(i-1);
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    auto ans = MaxStep(n);
    std::cout << ans.first << " " << ans.second << "\n";

}