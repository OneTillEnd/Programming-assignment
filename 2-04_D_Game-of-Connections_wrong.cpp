#include <iostream>
#include <algorithm>

long long sumseg[105];

int cal(int n){
    if (n == 0) return 1;
    if (n == 2) return 1;
    if (sumseg[n/2] == 0){
        for (int i = 0; i < n/2; ++i) {
            sumseg[n/2] += cal(2*i) * cal(n - (2*i + 2));
        }
    }
    return sumseg[n/2];
}

int main() {
    int n;
    for (int i = 1; i <= 100; ++i) {
        sumseg[i] = 0;
    }
    /*while (std::cin >> n && n != -1){
        std::cout << cal(2*n) << std::endl;
    }*/
    for (int i = 1; i <= 100; ++i) {
        std::cout << cal(2*i) << std::endl;
    }
    return 0;
}
