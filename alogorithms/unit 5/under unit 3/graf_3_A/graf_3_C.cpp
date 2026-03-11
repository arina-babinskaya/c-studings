#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> lad(n, std::vector<int>(m,0));
    std::pair<int, int> start, finish;
    std::queue<std::pair<int, int>> q;

    for (size_t i=0; i<n; ++i) {
        std::string s;
        std::cin >> s;
        for (size_t j=0; j<m; ++j) {
            if (s[j] == '#') {
                lad[i][j] = -1;
            } else if (s[j] == '.') {
                lad[i][j] = 0;
            } else if (s[j] == 'S') {
                start = {i,j};
            } else if (s[j] == 'F') {
                lad[i][j] = 0;
                finish = {i,j};
            }
        }
    }

    std::vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
    std::vector<char> dn = {'U', 'R', 'D', 'L'};
    
    q.push(start);
    lad[start.first][start.second] = 1;
    std::vector<std::vector<std::string>> path(n, std::vector<std::string>(m, ""));
    bool found = false;
    std::string result_path;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        if (r == finish.first && c == finish.second) {
            found = true;
            result_path = path[r][c];
            break;
        }

        for (size_t shift=0; shift<4; ++shift) {
            int new_r = r + dr[shift];
            int new_c = c + dc[shift];

            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && lad[new_r][new_c] != -1 && path[new_r][new_c].empty()) {
                lad[new_r][new_c] = -1;  
                path[new_r][new_c] = path[r][c] + dn[shift];
                q.push({new_r, new_c});
            }
        }   
    }

    if (found) {
        std::cout << result_path.size() << "\n";
        std::cout << result_path << "\n";
    } else {
        std::cout << -1 << "\n";
    }
}