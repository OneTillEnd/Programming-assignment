#include <iostream>

int main() {
    int c, n;
    std::cin >> c;
    for (int i = 0; i < c; ++i) {
        std::cin >> n;
        std::cout << 1 + n*(2*n - 1);
    }
    return 0;
}
