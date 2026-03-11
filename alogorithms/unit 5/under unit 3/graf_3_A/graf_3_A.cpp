// #include <iostream>
// #include <vector>
// #include <algorithm>

// int dfs_m(const std::vector<std::vector<int>>& graf, int vertex, std::vector<int>& used, std::vector<int>& depth, std::vector<bool>& used_depth, bool& cycle) {
//     used[vertex] = 1;
//     int mm = 0;

//     for (auto to : graf[vertex]) {
//         if (used[to] == 1) {
//             cycle = true;
//             return 0;
//         }
//         if (used[to] == 0) {
//             if (cycle) {
//                 return 0;
//             }
//             mm = std::max(dfs_m(graf, to, used, depth, used_depth, cycle), mm);
//         }
//     }

//     depth[vertex] = mm + 1;
//     if (used_depth[depth[vertex]]) {
//         cycle = true;
//         return 0;
//     }
//     used_depth[depth[vertex]] = true;
//     used[vertex] = 2;

//     return depth[vertex];
// }

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> graf(n);
//     for (size_t i=0; i<m; ++i) {
//         int v1, v2, t;
//         std::cin >> v1 >> v2 >> t;
//         --v1;
//         --v2;
//         if (t == 2) {
//             graf[v2].push_back(v1);
//         } else if (t == 1) {
//             graf[v1].push_back(v2);
//         }
//     }

//     std::vector<int> used(n,0), depth(n, 0);
//     std::vector<bool> used_depth(n+1, false);
//     bool cycle = false;
//     for (size_t i=0; i < n; ++i) {
//         if (used[i] == 0) {
//             dfs_m(graf, i, used, depth, used_depth, cycle);
//         }
//     }

//     bool ok = true;

//     for (int i=1; i<n && ok; ++i) {
//         if (used_depth[i] == 0){
//             ok = false;
//         }
//     }

//     if ( (ok && !cycle) || n == 1) {
//         std::cout << "YES\n";
//     } else {
//         std::cout << "NO\n";
//     }
// }


#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graf(n);
    std::vector<int> indeg(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v, t;
        std::cin >> u >> v >> t;
        --u;
        --v;

        if (t == 1) { 
            graf[u].push_back(v);
            indeg[v]++;
        } else {
            graf[v].push_back(u);
            indeg[u]++;
        }
    }

    std::queue<int> q;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    int processed = 0;

    while (!q.empty()) {
        if (q.size() > 1) {
            std::cout << "NO\n";
            return 0;
        }

        int v = q.front();
        q.pop();
        processed++;

        for (int to : graf[v]) {
            if (--indeg[to] == 0)
                q.push(to);
        }
    }

    if (processed == n)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}
