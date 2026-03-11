#include <iostream>
#include <vector>
#include <string> 
#include <cctype>  
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    std::vector<long long> answers;
    
    for (int test = 0; test < t; ++test) {
        int n, m, k, s;
        std::cin >> n >> m >> k >> s;
        
        std::vector<std::string> desktop(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> desktop[i];
        }
        
        std::vector<std::vector<std::pair<int, int>>> program_place(k + 1);
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                char ch = desktop[row][col];
                if (isdigit(ch)) {
                    int num = ch - '0';
                    if (num >= 1 && num <= k) {
                        program_place[num].emplace_back(row, col);
                    }
                }
            }
        }
        
        std::vector<std::vector<std::vector<std::pair<int, int>>>> window(k + 1);
        for (int prog = 1; prog <= k; ++prog) {
            if (program_place[prog].empty()) continue;
            
            auto [prog_row, prog_col] = program_place[prog][0];
            for (int row_off = 0; row_off < s; ++row_off) {
                for (int col_off = 0; col_off < s; ++col_off) {
                    int check_row = prog_row - row_off;
                    int check_col = prog_col - col_off;
                    
                    if (check_row < 0 || check_col < 0) continue; 
                    
                    bool all_in_window = true;
                    for (auto [x, y] : program_place[prog]) {
                        if (!(check_row <= x && x <= check_row + s - 1 &&
                              check_col <= y && y <= check_col + s - 1)) {
                            all_in_window = false;
                            break;
                        }
                    }
                    if (!all_in_window) continue;
                    
                    std::vector<std::pair<int, int>> temp;
                    bool valid = true;
                    for (int i = 0; i < s && valid; ++i) {
                        for (int j = 0; j < s; ++j) {
                            int pr = check_row + i;
                            int pc = check_col + j;
                            if (pr >= n || pc >= m || desktop[pr][pc] == '.') {
                                valid = false;
                                break;
                            }
                            temp.emplace_back(pr, pc);
                        }
                    }
                    if (valid) {
                        window[prog].push_back(std::move(temp));
                    }
                }
            }
        }
        
        long long this_result = 0;
        std::vector<std::string> stack = {"0"}; 
        
        while (!stack.empty()) {
            std::string path = stack.back();
            stack.pop_back();
            
            if (path.length() > k) {
                ++this_result;
                continue;
            }
            
            for (int num = 1; num <= k; ++num) {
                if (path.find(char('0' + num)) != std::string::npos) continue; 
                
                for (const auto& option : window[num]) {
                    bool suitable = true;
                    for (auto [r, c] : option) {
                        char cell = desktop[r][c];
                        if (cell != char('0' + num) && 
                            (cell >= '1' && cell <= '9' && path.find(cell) == std::string::npos)) {
                            suitable = false;
                            break;
                        }
                    }
                    if (suitable) {
                        stack.push_back(path + char('0' + num));
                    }
                }
            }
        }
        
        answers.push_back(this_result);
    }
    
    for (size_t i = 0; i < answers.size(); ++i) {
        std::cout << answers[i];
        if (i + 1 < answers.size()) std::cout << '\n';
    }
    return 0;
}
