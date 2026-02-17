#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

std::vector<long long> SumInt(long long a, long long b) {  // Убрал cin
    long long ost = 0;
    std::vector<long long> ans;
    while (a > 0 || b > 0) {
        long long ai = a % 10;
        long long bi = b % 10;
        long long sum = ai + bi + ost;
        ans.push_back(sum % 2);
        ost = sum / 2;
        a /= 10;
        b /= 10;
    }
    if (ost == 1) { ans.push_back(1); }
    if (ans.empty()) { ans.push_back(0); }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::vector<long long> SumStr(std::string a, std::string b) {
    size_t i = a.size() - 1;
    size_t j = b.size() - 1;
    long long ost = 0;
    std::vector<long long> ans;

    while (i != size_t(-1) || j != size_t(-1) || ost) {  // Исправил i>=0
        long long ai = (i != size_t(-1) ? a[i] - '0' : 0);
        long long bi = (j != size_t(-1) ? b[j] - '0' : 0);
        long long sum = ai + bi + ost;
        ans.push_back(sum % 2);
        ost = sum / 2;
        if (i != size_t(-1)) i--;
        if (j != size_t(-1)) j--;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

void StressTest() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bit_dist(0, 1);
    
    const int MAX_TESTS = 100000;  // Лимит тестов
    int iteration = 0;
    
    for (int test_len = 1; test_len <= 20; ++test_len) {  // Тестируем разную длину
        for (int test_num = 0; test_num < 1000; ++test_num) {
            // Генерируем случайные двоичные числа заданной длины
            std::string str1, str2;
            for (int i = 0; i < test_len; ++i) {
                str1 = std::to_string(bit_dist(gen)) + str1;
                str2 = std::to_string(bit_dist(gen)) + str2;
            }
            
            // Конвертируем строки в числа (если помещаются)
            long long num1 = std::stoll(str1);
            long long num2 = std::stoll(str2);
            
            iteration++;
            std::cout << "\rТест " << iteration << "/" << MAX_TESTS 
                      << " (длина=" << test_len << ")     ";
            
            auto result1 = SumInt(num1, num2);
            auto result2 = SumStr(str1, str2);
            
            if (result1 != result2) {
                std::cout << "\n НАЙДЕНА ОШИБКА на тесте #" << iteration << "!\n";
                std::cout << "Вход: " << str1 << " + " << str2 << "\n";
                std::cout << "SumInt: ";
                for (auto x : result1) std::cout << x;
                std::cout << "\nSumStr: ";
                for (auto x : result2) std::cout << x;
                std::cout << "\n";
                return;
            }
        }
    }
    std::cout << "\n" << iteration << " тестов пройдено!\n";
}

int main() {
    StressTest();
    return 0;
}
