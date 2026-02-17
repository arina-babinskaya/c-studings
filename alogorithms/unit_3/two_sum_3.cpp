#include <iostream>
#include <string>

int main() {
    int n;
    std::string a, b;
    std::cin >> n >> a >> b;
    for (size_t i=0; i<n; ++i) {
        std::cout << a[i] << b[i];
    }
}