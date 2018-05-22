#include <iostream>
#include <cstdio>

int main() {
    char name[70][20];
    int n, w, s;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> name[i];
    }
    scanf("%d,%d", &w, &s);
    int index = w - 1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) index = (index + s - 1) % n;
        else {
            for (int j = 0; j < s; ++j) {
                if (name[index][0] != '-'){
                    index = (index + 1) % n;
                }
                while (name[index][0] == '-'){
                    index = (index + 1) % n;
                }
            }
        }
        std::cout << name[index] << std::endl;
        name[index][0] = '-';
    }
    return 0;
}
