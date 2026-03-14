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
    int counter = 0, any_city;
    std::vector<std::pair<int, int>> to_build;


    for (int i=1; i<=n; ++i) {
        if (!(used[i])) {
            cop.clear();
            std::vector<int> temp = dfs(i, used, graph, cop);
            if (counter == 0) {
                any_city = temp[0];
            } else if (counter >= 1) {
                to_build.push_back({any_city, 0});
                any_city = temp[0];
                to_build[counter-1].second = any_city;
            }
            ++counter;
        }
    }

    std::cout << to_build.size() << "\n";
    for (auto [f, s] : to_build) { std::cout << f << " " << s << "\n"; }

}