#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t s = v.size();
    v.reserve(s*2);
    for (size_t it = 0; it != s; ++it) {
        v.push_back(v[it]);
    }
}

int main() {
    std::vector<int> train = {1, 2, 3};
    Duplicate(train);

    for (int x : train) std::cout << x << " "; 
}
