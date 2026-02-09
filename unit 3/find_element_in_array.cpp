// #include <iostream>

// struct Node {
//     int value, index;
//     Node* next;
//     Node(int v, int i): value(v), index(i), next(nullptr) {}
// };

// int main() {
//     int n, q;
//     std::cin >> n >> q;

//     Node* head = nullptr;
//     Node* tail = nullptr;
//     for (int i=0; i<n; ++i) {
//         int y;
//         std::cin >> y;
//         Node* newnode = new Node(y, i+1);
//         if (!head) {
//             head = tail = newnode;
//         } else {
//             tail->next = newnode;
//             tail = newnode;
//         }
//     }

//     for (int i=0; i<q; ++i){
//         int x;
//         std::cin >> x;
//         Node* cur = head;
//         int pos = -1;
//         while (cur) {
//             if (cur->value == x){
//                 pos = cur->index;
//                 break;
//             }
//             cur = cur->next;
//         }
//         std::cout << pos << "\n";
//     }
// }



// #include <iostream>
// #include <vector>

// struct Node {
//     int value, index;
//     Node* next;
//     Node(int v, int i): value(v), index(i), next(nullptr) {}
// };

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int n, q;
//     std::cin >> n >> q;
//     std::vector<int> a(n);  
    
//     for (int i = 0; i < n; ++i) {
//         std::cin >> a[i]; 
//     }
    
//     Node* head = nullptr;
//     Node* tail = nullptr;
//     for (int i=0; i<n; ++i) {
//         Node* newnode = new Node(a[i], i+1);
//         if (!head) {
//             head = tail = newnode;
//         } else {
//             tail->next = newnode;
//             tail = newnode;
//         }
//     }

//     for (int i=0; i<q; ++i){
//         int x;
//         std::cin >> x;
//         Node* cur = head;
//         int pos = -1;
//         while (cur) {
//             if (cur->value == x){
//                 pos = cur->index;
//                 break;
//             }
//             cur = cur->next;
//         }
//         std::cout << pos << "\n";
//     }
// }

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    
    std::unordered_map<int, int> first_position;
    
    for (int i = 0; i < n; ++i) {
        int y;
        std::cin >> y;
        // Сохраняем только первое вхождение
        if (first_position.find(y) == first_position.end()) {
            first_position[y] = i + 1;
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int x;
        std::cin >> x;
        
        auto it = first_position.find(x);
        if (it != first_position.end()) {
            std::cout << it->second << "\n";
        } else {
            std::cout << "-1\n";
        }
    }
    
    return 0;
}