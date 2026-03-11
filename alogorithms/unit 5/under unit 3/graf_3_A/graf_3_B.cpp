#include <iostream>
#include <queue>
#include <vector>

int main() {
    int x, y;
    std::cin >> x >> y;

    if (x == y) {
        std::cout << 0 << "\n";
        return 0;
    }

    std::vector<int> dist(100001, -1);
    std::queue<int> vertex;

    dist[x] = 0;
    vertex.push(x);

    while (!vertex.empty()){
        int curr = vertex.front();
        vertex.pop();

        for (int c=0; c<=9; ++c) {
            if (curr + c <= 100000 && dist[curr + c] == -1) {
                dist[curr + c] = dist[curr] + 1;
                vertex.push(curr + c);
                if (curr + c == y) {
                    std::cout << dist[curr + c] << "\n";
                    return 0;
                }
            }

            if (curr - c >= 1 && dist[curr - c] == -1) {
                dist[curr - c] = dist[curr] + 1;
                vertex.push(curr - c);
                if (curr - c == y) {
                    std::cout << dist[curr - c] << "\n";
                    return 0;
                }
            }

            if (static_cast<long long>(curr) * c <= 100000 && dist[curr * c] == -1) {
                dist[curr * c] = dist[curr] + 1;
                vertex.push(curr * c);
                if (curr * c == y) {
                    std::cout << dist[curr * c] << "\n";
                    return 0;
                }
            }
        }
    }
}