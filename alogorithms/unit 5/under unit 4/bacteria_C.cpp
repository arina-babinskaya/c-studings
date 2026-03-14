#include <iostream>
#include <vector>
#include <algorithm>


int dfs(int r, int c, std::vector<std::vector<bool>>& used,
    const std::vector<std::vector<int>>& graph, int& coloni,
    const std::vector<int>& dr, const std::vector<int>& dc) {
    used[r][c] = true;
    ++coloni;
    for (size_t shift=0; shift<4; ++shift) {
        int nr=r+dr[shift], nc=c+dc[shift];
        if (!(used[nr][nc]) && graph[nr][nc] != 0) {
            dfs(nr, nc, used, graph, coloni, dr, dc);
        }
    }
    return coloni;
}


int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n+2, std::vector<int>(m+2,0));
    int k = 1;
    for (size_t r=1; r<n+1; ++r){
        for (size_t c=1; c<m+1; ++c) {
            char el;
            std::cin >> el;

            if (el == '#') {
                graph[r][c] = k;
                ++k; 
            }    
        }
    }

    std::vector<std::vector<bool>> used(n+2, std::vector<bool>(m+2, false));
    std::vector<int> cop;
    int counter = 0, max_coloni = 0, coloni = 0;
    const std::vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};


    for (size_t r=1; r<n+1; ++r){
        for (size_t c=1; c<m+1; ++c) {
            if (!(used[r][c]) && graph[r][c] != 0) {
                coloni = 0;
                int temp_coloni = dfs(r, c, used, graph, coloni, dr, dc);
                max_coloni = std::max(max_coloni, coloni);
                ++counter;
            }
        }
    }

    std::cout << counter << "\n" << max_coloni << "\n";
}