#include <fstream>
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>



void MakeTrain() {
    std::string command;
    int num;
    std::deque<int> train;
    size_t c;
    while(std::cin >> command) {
        if (command == "+left") {
            std::cin >> num;
            train.push_front(num);
        }
        else if (command == "+right") {
            std::cin >> num;
            train.push_back(num);
        }
        else if (command == "-left") {
            std::cin >> c;
            c = std::min(c, train.size());
            train.erase(train.begin(),train.begin() + c);
        }
        else if (command == "-right") {
            std::cin >> c;
            c = std::min(c, train.size());
            train.erase(train.end() - c,train.end());
        }
    }
    for (const auto& num : train) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}


std::string run_test(const std::string& input, const std::vector<int>& expected) {
    std::istringstream iss(input);
    std::ostringstream oss;
    
    std::streambuf* cin_buf = std::cin.rdbuf(iss.rdbuf());
    std::streambuf* cout_buf = std::cout.rdbuf(oss.rdbuf());
    
    MakeTrain();
    
    std::cin.rdbuf(cin_buf);
    std::cout.rdbuf(cout_buf);
    
    // Parse output numbers
    std::istringstream result(oss.str());
    std::vector<int> output;
    int num;
    while (result >> num) {
        output.push_back(num);
    }
    
    return (output == expected) ? "PASS" : "FAIL";
}

int main() {
    std::cout << "=== Train Simulator Tests ===\n\n";
    
    // Test 1: Basic left/right adds
    std::cout << "1. '+left 1 +right 2 +right 3' → [1,2,3]: " 
              << run_test("+left 1 +right 2 +right 3", {1,2,3}) << "\n";
    
    // Test 2: Remove more than exists (clamped)
    std::cout << "2. '+left 10 +right 20 -left 2' → []: " 
              << run_test("+left 10 +right 20 -left 2", {}) << "\n";
    
    // Test 3: Right remove partial
    std::cout << "3. '+left 5 +left 4 +right 6 -right 1' → [4,5]: " 
              << run_test("+left 5 +left 4 +right 6 -right 1", {4,5}) << "\n";
    
    // Test 4: Mixed operations
    std::cout << "4. '+right 1 +left 2 +right 3 -left 1 -right 1' → [1]: " 
              << run_test("+right 1 +left 2 +right 3 -left 1 -right 1", {1}) << "\n";
    
    // Test 5: Empty train
    std::cout << "5. '+left 1 -left 1' → []: " 
              << run_test("+left 1 -left 1", {}) << "\n";
    
    // Test 6: Large right remove clamped
    std::cout << "6. '+right 10 +right 20 +right 30 -right 5' → []: " 
              << run_test("+right 10 +right 20 +right 30 -right 5", {}) << "\n";
    
    std::cout << "\nTests complete!\n";
    return 0;
}