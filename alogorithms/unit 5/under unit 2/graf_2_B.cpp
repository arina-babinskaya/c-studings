#include <iostream>
#include <vector>
#include <string>


int main() {
    int n, m, r, c, q, counter=0, direction=0;
    std::string ss;
    std::vector<int> row = {-1, 0, 1, 0}, col = {0, 1, 0, -1};
    std::cin >> n >> m;
    std::vector<std::vector<int>> room(n, std::vector<int>(m,0));
    for (size_t i=0; i<n; ++i) {
        for (size_t j=0; j<m; ++j) {
            char s;
            std::cin >> s;
            if (s == '#') { room[i][j] = -1; }
            else { room[i][j] = 0; }
        }
    }
    std::cin >> r >> c;
    --r; --c;
    room[r][c] = 1;
    ++counter;
    std::cin >> q >> ss;
    for (const char command : ss) {
        if (command == 'R') {
            direction = (direction + 1) % 4;
        } else if (command == 'L') {
            direction = (direction + 3) % 4;
        } else if (command == 'M') {
            int new_r = r + row[direction];
            int new_c = c + col[direction];
            
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && room[new_r][new_c] != -1) {
                r = new_r;
                c = new_c;
                if (room[r][c] == 0) { 
                    room[r][c] = 1;
                    ++counter;
                }
            }
        }
    }
    std::cout << counter << "\n";
}