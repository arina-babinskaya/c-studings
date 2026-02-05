#include <iostream>
#include <string>
#include <stack>

bool brackets(const std::string& seq) {
    std::stack<char> br;

    for (auto elem : seq) {
        if (elem == '{' || elem == '(' || elem == '[') {
            br.push(elem);
        } else {
            if (br.empty()) {
                return false;
            } 

            if ((br.top() == '(' && elem == ')') || (br.top() == '[' && elem == ']') || (br.top() == '{' && elem == '}')) {
                br.pop();
            } else {
                return false;
            }
        }
    }
    return br.empty();
}

int main() {
    std::string seq;
    std::cin >> seq;
    if (brackets(seq)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}


