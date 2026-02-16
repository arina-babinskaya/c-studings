#include <iostream>
#include <deque>
#include <string>
#include <vector>

int main() {
    std::string s;
    int n;
    std::deque<char> data;
    std::string ans;
    std::cin >> n >> s;
    for (char c : s) {
        data.push_back(c);
    }

    for (int i=0; i<n; ++i) {
        if (data.front() <= data.back()) {
            ans += data.front();
            data.pop_front();
        } else {
            ans += data.back();
            data.pop_back();
        }
    }
    std::cout << ans << "\n";
}