// //task 1
// #include <iostream>
// #include <map>
// #include <string>
// #include <queue>

// int main() {
//     std::string s;
//     std::cin >> s;
//     std::map<int, char> data;
//     char alp = 'a';
//     for (int i=1; i<27; ++i) {
//         data[i] = alp;
//         ++alp; 
//     }

//     std::string res;
//     std::queue<int> q;
//     for (char t : s) {
//         if (t != '#') {
//             q.push(t - '0');
//         } else {
//             while (q.size() > 2) {
//                 int key = q.front();
//                 q.pop();
//                 res += data[key];
//             }
            
//             int a = q.front();
//             q.pop();
//             int b = q.front();
//             q.pop();
//             res += data[10*a + b];
//         }
//     }
//     if (!q.empty()) {
//         while (!q.empty()) {
//             int key = q.front();
//             q.pop();
//             res += data[key];
//         }
//     }
//     std::cout << res << "\n";
//     return 0;
// }

//task 2
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<long long> a(n+1), pref(n+1);
    std::set<long long> d;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        d.insert(a[i]);
        pref[i] = pref[i-1] + a[i];
    }

    if (d.size() == 1) {
        for (size_t i=0; i<n; ++i) { std::cout << 0 << " "; }
    } else {
        int start = n;

        for (int i = n-1; i >= 1; i--) {
            if (pref[i] > a[i+1])
                start = i;
            else
                break;
        }

        for (int i = 1; i <= n; i++) {
            if (i >= start) std::cout << 1 << " ";
            else std::cout << 0 << " ";
        }

    }

    return 0;
}

