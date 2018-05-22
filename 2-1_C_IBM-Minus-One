#include <iostream>
#include <cstring>


int main() {
    int count = 0;
    std::cin >> count;
    int length[count];
    char input[count][60], output[count][60], passwd[200];
    for (int i = (int)'A'; i < (int)'Z'; ++i) {
        passwd[i] = (char)(i + 1);
    }
    passwd['Z'] = 'A';


    for (int i = 0; i < count; ++i) {
        std::cin >> input[i];
        length[i] = strlen(input[i]);
        for (int j = 0; j < length[i]; ++j) {
            output[i][j] = passwd[input[i][j]];
        }
    }
    for (int i = 0; i < count; ++i) {
        std::cout << "String #" << i + 1 << std::endl;
        for (int j = 0; j < length[i]; ++j) {
            std::cout << output[i][j];
        }
        std::cout << std::endl;
        if (i < count - 1) std::cout << '\n';
    }


    return 0;
}
