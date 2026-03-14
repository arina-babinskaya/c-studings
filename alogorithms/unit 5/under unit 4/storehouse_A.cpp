#include <iostream>
#include <vector>


std::vector<int> dfs(int v, std::vector<bool>& used, const std::vector<std::vector<int>>& graph, std::vector<int>& cop) {
    used[v] = true;
    cop.push_back(v);
    for (int to : graph[v]) {
        if (!used[to]) {
            dfs(to, used, graph, cop);
        }
    }
    return cop;
}


int main() {
    int n, m;
    std::cin >> n >> m;

    if (m < n-2) {
        std::cout << "NO\n";
    } else {
        std::vector<std::vector<int>> graph(n+1);
        for (size_t i=0; i<m; ++i){
            int u, v;
            std::cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        std::vector<bool> used(n+1,false);
        std::vector<int> cop;
        int c = 0;

        for (int i=1; i<=n; ++i) {

            if (!(used[i])) {
                cop.clear();
                dfs(i, used, graph, cop);
                ++ c;
            }
        }
        if (c == 1) {
            std::cout << "YES\n";
        } else { std::cout << "NO\n"; }


    }
}