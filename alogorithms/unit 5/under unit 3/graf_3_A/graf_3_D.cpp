#include <iostream>
#include <queue>
#include <vector>
#include <string>

std::string bfsWithoutKey(
    const std::vector<std::vector<char>>& lad,
    std::pair<int,int> start,
    std::pair<int,int> finish
){
    int n = lad.size();
    int m = lad[0].size();

    std::vector<int> dr = {-1,0,1,0};
    std::vector<int> dc = {0,1,0,-1};
    std::vector<char> dn = {'U','R','D','L'};

    std::queue<std::pair<int,int>> q;

    std::vector<std::vector<bool>> vis(n,std::vector<bool>(m,false));
    std::vector<std::vector<std::string>> path(n,std::vector<std::string>(m,""));

    q.push(start);
    vis[start.first][start.second] = true;

    while(!q.empty()){

        auto [r,c] = q.front();
        q.pop();

        if(r == finish.first && c == finish.second){
            return path[r][c];
        }

        for(int d=0; d<4; d++){

            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;

            char cell = lad[nr][nc];

            if(cell == '#') continue;
            if(cell == 'D') continue;   

            if(!vis[nr][nc]){

                vis[nr][nc] = true;
                path[nr][nc] = path[r][c] + dn[d];
                q.push({nr,nc});
            }
        }
    }

    return "";
}




struct State {
    int r, c;
    bool key;
};


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> lad(n, std::vector<char>(m,'0'));
    std::pair<int, int> start, finish;

    for (size_t i=0; i<n; ++i) {
        std::string s;
        std::cin >> s;
        for (size_t j=0; j<m; ++j) {
            lad[i][j] = s[j];
            if (s[j] == 'S') {
                start = {i,j};
            } else if (s[j] == 'F') {
                finish = {i,j};
            }
        }
    }

    std::string res1 = bfsWithoutKey(lad, start, finish);
    if (res1 != "") {
        std::cout << res1.size() << "\n";
        std::cout << res1 << "\n";
    } else {
        std::queue<State> q;
        std::vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
        std::vector<char> dn = {'U', 'R', 'D', 'L'};

        std::vector<std::vector<std::vector<bool>>> vis(
            n, std::vector<std::vector<bool>>(m, std::vector<bool>(2, false))
        );

        std::vector<std::vector<std::vector<std::string>>> path(
            n, std::vector<std::vector<std::string>>(m, std::vector<std::string>(2, ""))
        );

        q.push({start.first,start.second,false});
        vis[start.first][start.second][0] = true;

        bool found = false;
        std::string result;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            bool key = cur.key;
            
            if (r == finish.first && c == finish.second) {
                found = true;
                result=path[r][c][key];
                break;
            }

            for (size_t shift=0; shift<4; ++shift) {
                int new_r = r + dr[shift];
                int new_c = c + dc[shift];

                if(new_r<0 || new_r>=n || new_c<0 || new_c>=m) continue;
                if(lad[new_r][new_c]=='#') continue;
                if(lad[new_r][new_c]=='D' && !key) continue;

                bool newKey=key;
                std::string newPath = path[r][c][key] + dn[shift];

                if(lad[new_r][new_c]=='K' && !key){
                    newKey=true;
                    newPath+='P';
                }

                if(!vis[new_r][new_c][newKey]){
                    vis[new_r][new_c][newKey]=true;
                    path[new_r][new_c][newKey]=newPath;
                    q.push({new_r,new_c,newKey});
                }
                
            }   
        }

        if (found) {
            std::cout << result.size() << "\n";
            std::cout << result << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }
}

    