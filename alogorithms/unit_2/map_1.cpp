// #include <iostream>
// #include <map>
// #include <utility>
// #include <cstdlib>

// int nod(int a, int b) {
//     a = std::abs(a);
//     b = std::abs(b);
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }
 
// int main() {
//     int n;
//     std::cin >> n;
//     std::map<std::pair<int,int>,int> data;
//     for (size_t i=0; i<n; ++i) {
//         int num, den;
//         std::cin >> num >> den;
//         int sign = 1;
//         if (den < 0) { sign = -1; num = -num; den = -den; }
//         if (num < 0) { sign = -1; num = -num; }
//         std::pair<int, int> frac = {num, den};
//         while (true) {
//         int t = nod(frac.first, frac.second);
//         if (t == 1) {
//             break;
//         } 
//         frac.first /= t;
//         frac.second /= t;
//         }
//         ++data[frac];
//     }

//     int max_freq = -1000000;
//     std::pair<int, int> max_frac;

//     for (const auto [frac, freq] : data) {
//         if (freq >= max_freq) {
//             max_freq = freq;
//             max_frac = frac;
//         }
//         //std::cout << frac.first << "/" << frac.second << " " << freq << "\n";
//     }
//     std::cout << max_frac.first << " " << max_frac.second << "\n";
// }



// #include <iostream>
// #include <unordered_map>
// #include <utility>
// #include <vector>
// #include <set>

// int main() {
//     int n;
//     std::unordered_map<int, int> data;
//     std::cin >> n;
//     for (size_t i=0; i<n; ++i) {
//         int num;
//         std::cin >> num;
//         ++data[num];
//     }



//     std::set<int> ans;

//     std::vector<std::pair<int, int>> vec(data.begin(), data.end());
//     std::sort(vec.begin(), vec.end(),
//         [](const auto& a, const auto& b) {
//             return std::tie(b.second, a.first) < std::tie(a.second, b.first);  
//         });


//     // for (const auto& [num, freq] : vec) {
//     //     std::cout << num << " " << freq << "\n";
//     // }

//     int c = 0;
//     for (const auto& [num, freq] : vec) {
//         ++c;
//         ans.insert(num);
//         if (c == 3) { break; }
//     }

//     for (const auto& num : ans) {
//         std::cout << num << " ";
//     }
//     // for (const auto& [num, freq] : vec) {
//     //     std::cout << num << " " << freq << "\n";
//     // }
// }
