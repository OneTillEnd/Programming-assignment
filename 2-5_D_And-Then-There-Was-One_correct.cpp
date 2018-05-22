#include <iostream>

int main() {
    int n, k, m;
    int index;

    while (std::cin >> n && n != 0){
        std::cin >> k >> m;
        index = 0;
        for (int i = 2; i <= n; ++i) {
            index = (index + k) % i;
        }
        index = (index + m - k + 1) % n;
        if (index <= 0) index = index + n;
        std::cout << index << std::endl;
    }
    return 0;
}
