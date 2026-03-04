#include <iostream>
#include <vector>


int mmaxi(const std::vector<int> d) {
    int m=-1;
    for (size_t i=0; i<d.size(); ++i) {
        if (d[i] > m) {
            m = d[i];
        }
    }
    return m;
}



int main() {
    int g, cur_n=0;
    std::cin >> g;
    std::vector<std::vector<int>> dep;
    for (size_t i=0; i<g; ++i) {
        int k;
        std::vector<int> temp;
        std::cin >> k;
        for (size_t j=0; j<k; ++j) {
            int num;
            std::cin >> num;
            temp.push_back(num);
        }
        int new_n = mmaxi(temp);
        if (new_n > cur_n) {
            cur_n = new_n;
            dep.resize(cur_n);
            for (size_t w=0; w<cur_n; ++w) {
                dep[w].resize(cur_n, 0);
            }
        }
        for (size_t x=1; x<k; ++x) {
            dep[temp[0]-1][temp[x]-1] = 1;
            dep[temp[x]-1][temp[0]-1] = -1;
        }
    }
    for (size_t i=0; i<cur_n; ++i) {
        for (size_t j=0; j<cur_n; ++j) {
            std::cout << dep[i][j] << " ";
        }
        std::cout << "\n";
    }
}