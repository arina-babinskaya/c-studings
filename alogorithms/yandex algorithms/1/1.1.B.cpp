// #include <iostream>

// int main() {
//     int k1, p1, n1, m, k2, p2, n2, block;
//     std::cin >> k1 >> m >> k2 >> p2 >> n2;


//     block = k2 / n2;
//     if (k2 % n2 != 0) { ++block; }
//     n1 = k1 / block;
//     if (k1 % block != 0) { ++n1; }
//     p1 = p2;

//     std::cout << n1 << "\n";
    
//     while (n1 > m) {
//         ++p1;
//         n1 -= m;
//     }

//     std::cout << p1 << " " << n1 << "\n";
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int k1, p1, n1, m, k2, p2, n2;
    std::cin >> k1 >> m >> k2 >> p2 >> n2;

    std::set<int> pp1, pn1;


    for (int x = 1; x <= std::max(k1, k2); ++x) {

        int cp2 = (k2 - 1) / (m * x) + 1;
        int cn2 = ((k2 - 1) % (m * x)) / x + 1;
        
        if (cp2 == p2 && cn2 == n2) {

            int cp1 = (k1 - 1) / (m * x) + 1;
            int cn1 = ((k1 - 1) % (m * x)) / x + 1;
            
            pp1.insert(cp1);
            pn1.insert(cn1);
        }
    }
    
    int resultP1, resultN1;
    
    if (pp1.empty() || pn1.empty()) {
        std::cout << "-1 -1" << "\n";
        return 0;
    }
    
    if (pp1.size() == 1) {
        resultP1 = *pp1.begin();
    } else {
        resultP1 = 0;
    }
    
    if (pn1.size() == 1) {
        resultN1 = *pn1.begin();
    } else {
        resultN1 = 0;
    }
    
    std::cout << resultP1 << " " << resultN1 << "\n";
}