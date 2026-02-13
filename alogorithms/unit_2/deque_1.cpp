#include <iostream>
#include <deque>


int main() {
    int q;
    std::cin >> q;
    std::deque<int> data;
    for (size_t i=0; i<q; ++i) {
        int command;
        std::cin >> command;
        if (command == 1) {
            int x;
            std::cin >> x;
            data.push_back(x);
        } else if (command == 2) {
            data.pop_front();
        }
        if (data.empty()) {
            std::cout << -1 << "\n";
        } else {
            std::cout << data.front() << "\n";
        }
    }
}