#include <iostream>
#include <string>

int main() {
    int troom, tcond, ans;
    std::string command;
    std::cin >> troom >> tcond >> command;

    if (command == "freeze") {
        if (troom <= tcond) {
            ans = troom;
        } else {
            ans = tcond;
        }
    } else if (command == "heat") {
        if (troom >= tcond) {
            ans = troom;
        } else {
            ans = tcond;
        }
    } else if (command == "auto") {
        ans = tcond;
    } else if (command == "fan") {
        ans = troom;
    }

    std::cout << ans << "\n";

}