#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    using server = std::pair<long long, int>;
    std::priority_queue<server, std::vector<server>, std::greater<server>> data;
    for (int i=0; i<k; ++i) {
        data.push({0,i});
    }
    std::vector<long long> ans(n);
    for (int i=0; i<n; ++i){
        long long t, d;
        std::cin >> t >> d;
        std::pair<long long,int> best = data.top();
        data.pop();
        long long f = std::max(best.first, t) + d;
        ans[i] = f;
        data.push({f, best.second});
    }
    for (const auto num : ans) {
        std::cout << num << " ";
    }

}


// int main() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<std::deque<int>> data(k);
//     std::vector<int> ans;
//     for (size_t i=0; i<n; ++i) {
//         int t, d, num;
//         std::cin >> t >> d;
//         for (size_t j=0; j<k; ++j){
//             if (data[j].empty() || data[j].back() <= t) {
//                 data[j].push_back(t+d);
//                 ans.push_back(data[j].back());
//                 num = j+1;
//                 break;
//             }
//         }
//         std::cout << t + d << " " << num << "\n";
        
//     }
//     for (const auto& num : ans) {
//         std::cout << num << " ";
//     }
// }