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
    std::pair<int, int> ans;
    for (size_t i=0; i<40; ++i) {
        int a = Fibbonachi(i);
        if (a >n) {
            ans.first = Fibbonachi(i-2);
            ans.second = Fibbonachi(i-1);
            break;
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