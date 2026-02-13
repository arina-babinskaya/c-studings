#include <iostream>
#include <string>
#include <vector>
#include <map>


int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (auto& w : words) {
        std::cin >> w;
    }
    
    std::unordered_map<std::string, long long> groups;   // маска -> количество слов
    std::unordered_map<std::string, int> seen;           // слово -> сколько раз встречено
    
    long long answer = 0;
    
    for (const std::string& word : words) {
        if (seen[word] > 0) continue;  // уже видели это слово
        
        size_t len = word.size();
        
        // Считаем пары с уже обработанными словами
        for (size_t pos = 0; pos < len; ++pos) {
            std::string mask = word;
            mask[pos] = '*';
            auto it = groups.find(mask);
            if (it != groups.end()) {
                answer += it->second;
            }
        }
        
        for (size_t pos = 0; pos < len; ++pos) {
            std::string mask = word;
            mask[pos] = '*';
            groups[mask]++;
        }
        
        seen[word] = 1;  
    }
    
    std::cout << answer << '\n';
}