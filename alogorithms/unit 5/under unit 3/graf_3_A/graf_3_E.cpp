#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <tuple>

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

            if(cell == '#' || cell == 'A' || cell == 'B' || cell == 'C' || cell == 'D' || cell == 'E' || cell == 'G' || cell == 'H' || cell == 'I' || cell == 'J' || cell == 'K' ) continue;

            if(!vis[nr][nc]){

                vis[nr][nc] = true;
                path[nr][nc] = path[r][c] + dn[d];
                q.push({nr,nc});
            }
        }
    }

    return "";
}


bool vis[50][50][1 << 10] = {};
std::tuple<int, int, int> parent[50][50][1 << 10];
char move_action[50][50][1 << 10];




struct State {
    int r, c, mask;
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
    int k;
    std::cin >> k;
    std::unordered_map<char, int> key_to_id, door_to_id;
    for (int i = 0; i < k; i++) {
        char door, kkey;
        std::cin >> door >> kkey;
        key_to_id[kkey] = i;
        door_to_id[door] = i;
    }

    std::string res1 = bfsWithoutKey(lad, start, finish);
    if (res1 != "") {
        std::cout << res1.size() << "\n";
        std::cout << res1 << "\n";



    } else {

        std::queue<State> q;
        std::vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
        std::vector<char> dn = {'U', 'R', 'D', 'L'};

        q.push({start.first,start.second, 0});
        vis[start.first][start.second][0] = true;

        

        while (!q.empty()) {
            auto [r, c, mask] = q.front();
            q.pop();
            
            if (r == finish.first && c == finish.second) {
                std::string path;
                int cx = r, cy = c, cmask = mask;
                
                while (cx != start.first || cy != start.second || cmask != 0) {
                    path += move_action[cx][cy][cmask];
                    std::tie(cx, cy, cmask) = parent[cx][cy][cmask];
                }
                
                reverse(path.begin(), path.end());
                std::cout << path.size() << '\n' << path << '\n';
                return 0;
            }


            char cell = lad[r][c];
            if (key_to_id.count(cell)) {
                int key_id = key_to_id[cell];
                if (!(mask & (1 << key_id))) {
                    int new_mask = mask | (1 << key_id);
                    if (!vis[r][c][new_mask]) {
                        vis[r][c][new_mask] = true;
                        parent[r][c][new_mask] = {r, c, mask};
                        move_action[r][c][new_mask] = 'P';
                        q.push({r, c, new_mask});
                    }
                }
            }

            for (size_t shift=0; shift<4; ++shift) {
                int new_r = r + dr[shift];
                int new_c = c + dc[shift];

                if(new_r<0 || new_r>=n || new_c<0 || new_c>=m) continue;
                if(lad[new_r][new_c]=='#') continue;

                if(door_to_id.count(lad[new_r][new_c])) {
                    int door_id = door_to_id[lad[new_r][new_c]];
                    if (!(mask & (1 << door_id))) {
                        continue;
                    }
                }

                if(!vis[new_r][new_c][mask]){
                    vis[new_r][new_c][mask]=true;
                    parent[new_r][new_c][mask]={r,c,mask};
                    move_action[new_r][new_c][mask] = dn[shift];
                    q.push({new_r,new_c,mask});
                }
                
            }   
        }

        std::cout << -1 << "\n";
    }
}

