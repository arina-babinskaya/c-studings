#include <iostream>
#include <string>
#include <queue>

int main() {
    std::priority_queue<int> seq;
    std::string command;
    
    while (std::cin >> command) {
        if (command == "ADD") {
            int num;
            std::cin >> num;
            seq.push(num);
        } else if (command == "CLEAR") {
            while (!seq.empty()) {
                seq.pop();
            }
        } else if (command == "EXTRACT") {
            if (seq.empty()) {
                std::cout << "CANNOT\n";
            } else {
                std::cout << seq.top() << "\n";
                seq.pop();
            }
        } 
    }
}