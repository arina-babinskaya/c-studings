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

    std::vector<std::vector<int>> graph(n+1);
    for (size_t i=0; i<m; ++i){
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<bool> used(n+1,false);
    std::vector<int> cop;
    int counter = 0, max_city = 0;


    for (int i=1; i<=n; ++i) {

        if (!(used[i])) {
            cop.clear();
            std::vector<int> temp = dfs(i, used, graph, cop);
            ++counter;
            if (temp.size() > max_city) { max_city = temp.size(); }
        }
    }
    
    std::cout << counter << "\n" << max_city << "\n";
}