#include <iostream>
#include <cstring>

int main() {
    char c[100];
    int count = 0;
    bool start = true;
    while (std::cin >> c){
        if (c[0] == '<'){
            if (c[1] == 'h') {
                if (!start) std::cout <<std::endl;
                std::cout << "--------------------------------------------------------------------------------"
                          << std::endl;
            }
            if (c[1] == 'b') std::cout << std::endl;
            start = true;
            continue;
        } else {
            if (80 <= count + strlen(c)){
                std::cout << std::endl;
                std::cout << c;
                count = strlen(c) % 80;
            }
            else if (start) {
                std::cout << c;
                count = strlen(c) % 80;
            }
            else{
                std::cout << " " << c;
                count = (count + strlen(c) + 1) % 80;
            }
            if (count != 0) start = false;
            else std::cout << std::endl;
        }
    }
    if (!start) std::cout << std::endl;
    return 0;
}
