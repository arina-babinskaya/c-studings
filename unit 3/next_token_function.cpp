#include <iostream>
#include <string_view>
#include <string>

bool NextToken(std::string_view& sv, const char delimiter, std::string_view& token) {
    if (sv.empty()) {
        return false;
    }

    auto position = sv.find(delimiter);
    if (position == -1) {
        token = sv;
        sv.remove_prefix(sv.size());

    } else {
        token = sv.substr(0, position);
        sv.remove_prefix(position + 1);
    }
    return true;

}

int main() {
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;

    // Делим строку на токены по разделителю и перебираем эти токены:
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << token << "\n";
    }
}