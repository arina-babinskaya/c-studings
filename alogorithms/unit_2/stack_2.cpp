#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> data;
    std::vector<int> ans;
    for (size_t i=0; i<n; ++i) {
        int num;
        std::cin >> num;
        data.push_back(num);
        if (i == 0) {
            ans.push_back(0);
        } else {
            int maxc=0;

            for (size_t j=0; j<i; ++j) {
                int cur = 0;
                bool valid = true;
                for (size_t z=j; z<i; ++z) {
                    if (data[z] < data[i]){
                        cur++;
                    } else {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    maxc = std::max(maxc, cur);
                }
            }
            ans.push_back(maxc);
        }
    }
    for (const auto& n : ans) {
        std::cout << n << " ";
    }
}


