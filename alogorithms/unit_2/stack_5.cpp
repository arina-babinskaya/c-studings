#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::stack<int> data;
    for (size_t i=0; i<n; ++i) {
        int num;
        std::cin >> num;
        data.push(num);
    }
    
    size_t mmax=0;
    std::vector<int> ans;
    int cur = data.top();
    data.pop();
    ans.push_back(cur);
    int ind = cur % 2;
    std::cout << cur << " " << ind << "\n";
    


    for (size_t i=1; i<n; ++i) {
        int cur = data.top();         
        if (cur % 2 != ind) {
            ans.push_back(cur);
            ind = cur % 2;
        } else {
            mmax = std::max(mmax, ans.size());
            ans.clear();
            ans.push_back(cur);
        }
        data.pop();
    }
    std::cout << mmax - (mmax%2) << "\n";
}
