#include <iostream>
#include <deque>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    std::deque<int> data;
    for (size_t i=0; i<q; ++i) {
        int command;
        std::cin >> command;
        if (command == 1) {
            int x;
            std::cin >> x;
            data.push_front(x);
        } else if (command == 2) {
            int x;
            std::cin >> x;
            data.push_back(x);
        } else if (command == 3 && !data.empty()) {
            data.pop_front();
        } else if (command == 4 && !data.empty()) {
            data.pop_back();
        }
        if (data.empty()) {
            std::cout << -1 << "\n";
        } else {
            std::cout << data.front() << " " << data.back() << "\n";
        }
    }
}