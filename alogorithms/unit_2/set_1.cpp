#include <iostream>
#include <unordered_set>

int main() {
    int q ;
    std::unordered_set<int> data;
    int command, num;

    std::cin >> q;
    for (size_t i=0; i<q; ++i) {
        std::cin >> command >> num;
        if (command == 1) {
            data.insert(num);
        } else if (command == 2) {
            if (data.find(num) != data.end()) {
                std::cout << "1";
            } else {
                std::cout << "0";
            }
        }
    }
}
