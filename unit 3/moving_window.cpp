#include <iostream>
#include <string>
#include <set>
#include <queue>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::queue<int> seq;
    std::multiset<int> window;
    for (int i =1; i < n + 1; ++i){
        int el;
        std::cin >> el;
        seq.push(el);
        window.insert(el);

        if (i >= k) {
            std::cout << *window.begin() << "\n";
            auto it = window.find(seq.front());
            window.erase(it);
            seq.pop();
        }
    }

}