// #include <list>
// #include <string>
// #include <iostream>
// #include <utility>

// #include <fstream>

// int main() {
//     std::list<std::string> file;

//     std::ifstream input_file("input.txt");
//     if (!input_file.is_open()) {
//         std::cerr << "Error: Cannot open input.txt" << std::endl;
//         return 1;
//     }

//     while (true) {
//         std::string line;
//         std::getline(input_file,line);

//         if (line.empty()){
//             break;
//         }

//         file.push_back(line);
//     }

//     auto flag = file.begin();
//     std::string command;
//     std::string buffer;
//     while (std::cin >> command) {
//         if (command == "Down") {
//             if (flag == file.end()) {
//                 continue;
//             }
//             ++flag; 
//         }
//         else if (command == "Up") {
//             if (flag == file.begin()) {
//                 continue;
//             }
//             --flag; 
//         }
//         else if (command == "Ctrl+X") {
//             if (flag == file.end()) {
//                 continue;
//             }
//             buffer = std::move(*flag);
//             flag = file.erase(flag);
//         }
//         else if (command == "Ctrl+V") {
//             if (buffer.empty()) {
//                 continue;
//             }
//             flag = file.insert(flag, buffer);
//         }

//         for (const auto& elem : file) {
//             std::cout << elem << "\n";
//         }
//     }
// }


#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>

int main() {
    std::list<std::string> file;
    
    // Read from input.txt instead of std::cin
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error: Cannot open input.txt" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(input_file, line)) {
        if (!line.empty()) {  // Only add non-empty lines
            file.push_back(line);
        }
    }
    input_file.close();

    auto flag = file.empty() ? file.end() : file.begin();
    
    std::string command;
    std::string buffer;
    
    while (std::cin >> command) {
        if (command == "quit") {
            break;
        }
        
        if (command == "Down") {
            if (flag != file.end()) {
                ++flag;
            }
        }
        else if (command == "Up") {
            if (flag != file.begin()) {
                --flag;
            }
        }
        else if (command == "Ctrl+X") {
            if (flag != file.end()) {
                buffer = std::move(*flag);
                flag = file.erase(flag);
            }
        }
        else if (command == "Ctrl+V") {
            if (!buffer.empty() && flag != file.end()) {
                flag = file.insert(flag, buffer);  // insert before flag
                ++flag;  // move to inserted item
            }
        }
        
        // Print current state
        std::cout << "\n--- Current file state ---\n";
        for (const auto& elem : file) {
            std::cout << elem << "\n";
        }
        std::cout << "Flag position: " << std::distance(file.begin(), flag) 
                  << " (0-based index)\n\n";
        
        std::cout << "Enter next command: ";
    }
    
    return 0;
}

