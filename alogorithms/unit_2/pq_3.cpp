#include <iostream>
#include <queue>

int main() {
    long long n, k;
    std::cin >> n >> k;
    std::priority_queue<long long> data;
    long long sum = 0;
    for (size_t i=0; i<n; ++i) {
        int num;
        std::cin >> num;
        data.push(num);
    }
    for (size_t i=0; i<k; ++i) {
        if (sum + data.top() > sum) {
            sum += data.top();
            data.pop();
        } else {
            break;
        }
    }
    std::cout << sum << "\n";
}