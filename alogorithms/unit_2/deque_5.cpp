#include <iostream>
#include <deque>


int main() {
    int n;
    std::cin >> n;
    std::deque<long long> warriors;
    for (int i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        warriors.push_back(a);
    }
    
    while (warriors.size() > 2) {
        long long w1 = warriors.back();   
        long long w2 = warriors[0];       
        long long w3 = warriors[1];       
        
        if (w1 < w2 && w1 < w3) {
            warriors.pop_back();
            if (w2 < w3 && warriors.size() != 2) {
                warriors.push_back(w2);
                warriors.pop_front();

            }
        } else if (w2 < w1 && w2 < w3) {
            warriors.pop_front();
            if (w1 > w3 && warriors.size() != 2) {
                warriors.push_front(w1);
                warriors.pop_back();
            }
        } else {
            warriors.erase(warriors.begin() + 1);
            if (w2 < w1 && warriors.size() != 2) {
                warriors.push_front(w1);
                warriors.pop_back();
            }
        }
    }
    
    std::cout << warriors[0] << " " << warriors[1] << "\n";
}
