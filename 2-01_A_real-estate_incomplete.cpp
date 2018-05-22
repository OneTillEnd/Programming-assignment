#include <iostream>

int main() {
    int area[5][16];
    int price[5][16];
    int ppa[5][16];
    int j = 0;

    for (int i = 0; i < 5; ++i) {
        std::cin >> area[i][j];
        while (area[i][j] != -1){
            j = j + 1;
            std::cin >> area[i][j];
        }
        j = 0;
    }
    for (int i = 0; i < 5; ++i) {
        std::cin >> price[i][j];
        while (price[i][j] != -1){
            j = j + 1;
            std::cin >> price[i][j];
        }
        j = 0;
    }
    for (int i = 0; i < 5; ++i) {
        while (price[i][j] != -1){
            ppa[i][j] = price[i][j] / area[i][j];
            j = j + 1;
        }
        ppa[i][j] = -1;
        j = 0;
    }



    /*for (int i = 0; i < 5; ++i) {
        while (area[i][j] != -1){
            std::cout << area[i][j] << " ";
            j = j + 1;
        }
        std::cout << std::endl;
        j = 0;
    }*/

    return 0;
}
