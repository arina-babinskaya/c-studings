#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> pole(n+1, std::vector<char>(m+1, '#'));
    for (size_t i=0; i<n; ++i) {
        for (size_t j=0; j<m; ++j) {
            std::cin >> pole[i][j];
        }
    }

    long long ans = 0;

    //go horizontal
    for (size_t i=0; i<n; ++i) {
        for (size_t j=0; j<m; ++j) {
            if (pole[i][j] == '.' && pole[i][j+1] == '.') {
                ++ans;
            }
        }
    }

    for (size_t j=0; j<m; ++j) {
        for (size_t i=0; i<n; ++i) {
            if (pole[i][j] == '.' && pole[i+1][j] == '.') {
                ++ans;
            }
        } 
    }

    std::cout << ans << "\n";
}