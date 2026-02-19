// #include <iostream>
// #include <vector>
// #include <algorithm>


// int main() {
//     int n;
//     std::cin >>n;
//     std::vector<long long> data;
//     for (size_t i=0; i<n; ++i) {
//         long long num;
//         std::cin >> num;
//         data.push_back(num);
//     }
//     std::sort(data.begin(), data.end());
//     long long maxx = 1;
//     if (data[0] == 0 && data[n-1] == 0) {
//         maxx = 0;
//     } else {
//         for (size_t i=0; i<n; ++i){
//             if (data[i] == 0 && i != n) {
//                 continue;
//             } else if (data[i] < 0 ) 

//         }


//     }
    
// }



#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<long long, int>> dataP, dataM, dataZ;
    for (size_t i=0; i<n; ++i) {
        long long num;
        std::cin >> num;
        if (num > 0) {
            dataP.push_back({num, i+1});
        } else if (num < 0) {
            dataM.push_back({num, i+1});
        } else {
            dataZ.push_back({num, i+1});
        }
    }
    if (dataZ.size() == n || (dataZ.size() == n-1 && dataM.size() == 1)) {
        for (const auto& [num, ind] : dataZ) { std::cout << ind << " "; } 
    } else {
        std::sort(dataP.begin(), dataP.end());
        std::sort(dataM.begin(), dataM.end());
        std::vector<int> ans;
        if (dataM.size() % 2 == 1 && dataM.size() != 1) {
            dataM.pop_back();
        }
        for (const auto& [num, t] : dataP) { ans.push_back(t); }
        for (const auto& [num, t] : dataM) { ans.push_back(t); }
        std::sort(ans.begin(), ans.end());
        for (const auto& t : ans) { std::cout << t << " "; }
    }
}