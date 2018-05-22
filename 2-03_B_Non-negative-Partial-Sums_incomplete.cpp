#include <iostream>


int main() {
    int n, sum, count, j;
    int a[2000005], ;
    while (std::cin >> n && n != 0){
        count = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            a[i + n] = a[i];
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] < 0){

            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
