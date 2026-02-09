#include <iostream>
#include <set>
#include <vector>

int main() {
    std::set<int> a;
    int n;
    std::cin >> n;
    std::vector<int> ans;
    for (size_t i=0; i<n; ++i) {
        int num;
        std::cin >> num;
        a.insert(num);
        ans.push_back(*a.begin());
    }
    for (const auto& i : ans){
        std::cout << i << " ";
    }
}