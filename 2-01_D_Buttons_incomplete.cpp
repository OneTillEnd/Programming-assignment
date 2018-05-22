#include <iostream>

int calculation(int n, int &m){
    if (n >= 2){
        for (int i = 1; i < n; ++i) {
            m = m + i * (n - i);
        }
        m = m + n;
        return m;
    } else return 1;
}

int main() {
    int button_number = 0;
    int press_time;
    while (std::cin >> button_number){
        press_time = 0;
        std::cout << calculation(button_number, press_time) << std::endl;
    }
    return 0;
}
