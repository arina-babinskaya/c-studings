#include <iostream>
#include <queue>
#include <vector>

int main() {
    long long n, m;
    std::cin >> n >> m;
    using message = std::vector<long long>;
    std::priority_queue<message, std::vector<message>, std::greater<message>> data;
    std::vector<long long> ans;
    for (size_t i=0; i<n; ++i) {
        int id, p, s;
        std::cin >> id >> p >> s;
        data.push({s, id, p});
    }

    for (size_t i=0; i<m; ++i) {
        message cur = data.top();
        data.pop();
        std::cout << cur[1] << "\n";
        cur[0] += cur[2];
        data.push(cur);
    }
}