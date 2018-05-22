#include <iostream>

bool is_prime(int n){
    for (int i = 2; i < n; ++i) {
        if (0 == n % i) return 0;
    }
    return 1;
}

int main() {
    int count = 0, given_even;
    std::cin >> given_even;
    while (given_even != 0){
        for (int i = 2; i <= given_even / 2; ++i) {
            if (is_prime(i) && is_prime(given_even - i)){
                ++count;
            }
        }
        std::cout << count << std::endl;
        std::cin >> given_even;
        count = 0;
    }
    return 0;
}
