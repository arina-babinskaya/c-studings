#include <iostream>
#include <vector>

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graf1(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> graf2(n, std::vector<int>(n, 0));
    for (size_t r=0; r<m; ++r) {
        int c;
        std::cin >> c;
        std::vector<int> temp(c);
        for (size_t j=0; j<c; ++j) {
            int num;
            std::cin >> temp[j];
            --temp[j];
        }
        
        for (int i = 0; i < c - 1; i++) {
            int u = temp[i], v = temp[i + 1];
            graf1[u][v] = 1;
            graf1[v][u] = 1;
        }

        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++) {
                if (i != j) {
                    graf2[temp[i]][temp[j]] = 1;
                }
            }
        }
    }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << graf1[i][j];
            if (j < n - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << graf2[i][j];
            if (j < n - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}