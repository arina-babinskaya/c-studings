std::vector<int> dr = {1, 0, -1, 0}, dc = {0, 1, 0, -1};
    // std::vector<char> dn = {'U', 'R', 'D', 'L'};
    // std::queue<std::pair<int, int>> q;
    // q.push(start);
    // std::vector<std::vector<std::string>> path(n, std::vector<std::string>(m, " "));

    // while (!q.empty()) {
    //     std::pair<int, int> curr = q.front();
    //     q.pop();

    //     for (size_t shift=0; shift<4; ++shift) {
    //         int new_r = curr.first + dr[shift];
    //         int new_c = curr.second + dc[shift];
    //         if (lad[new_r][new_c] != -1 or lad[new_r][new_c] != 1) {
    //             lad[new_r][new_c] = 1;
    //             q.push({new_r, new_c});
    //             path[new_r][new_c] = path[curr.first][curr.second] + dn[shift];

    //             if (new_r == finish.first && new_c == finish.second) {
    //                 auto s = path[new_r][new_c] ;
    //                 std::cout << s.size() - 1 << "\n";
    //                 for (size_t i=1; i<s.size(); ++i) {
    //                     std::cout << i;
    //                 }
    //                 return 0;
    //             }
    //         }
    //     }
    //     std::cout << 1 << "\n";
    // }