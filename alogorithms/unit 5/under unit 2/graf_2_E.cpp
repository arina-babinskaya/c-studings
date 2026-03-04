#include <iostream>
#include <vector>


int main() {
    int n, num;
    std::cin >> n;
    std::vector<std::vector<int>> achivka(n, std::vector<int>(n,0));
    for (size_t i=0; i<n; ++i) {
        for (size_t j=0; j<n; ++j) {
            std::cin >> num;
            achivka[i][j] = num;
        }
    }
    std::cout << "\n";

    for (size_t i=0; i<n; ++i) {
        for (size_t j=i+1; j<n; ++j) {
            if (achivka[i][j] == 0) {
                for (size_t k=i+1; k<n; ++k) {
                    if (achivka[i][k] == 1 && achivka[k][j] == 1) {
                        achivka[i][j] = 1;
                        achivka[j][i] = 1;
                        break;
                    }
                }
            }
        }
    }

    for (size_t i=0; i<n; ++i) {
        for (size_t j=0; j<n; ++j) {
            std::cout << achivka[i][j] << " ";
        }
        std::cout << "\n";
    }
}