#include <iostream>

int main() {
    char in[10], out[10], command[20];
    int shifts, count, count_out;
    while (std::cin >> shifts){
        count = 0;
        count_out = 0;
        std::cin >> in >> out;
        for (int i = 0; i < shifts; ++i) {
            command[count] = 'i';
            ++count;
            if (out[count_out] == in[i]){
                command[count] = 'o';
                in[i] = '-';
                ++count_out;
                ++count;
                for (int j = i - 1; j >= 0; --j) {
                    if (in[j] == '-') continue;
                    if (in[j] != out[count_out]) break;
                    else {
                        command[count] = 'o';
                        in[j] = '-';
                        ++count_out;
                        ++count;
                    }
                }
            }
        }

        if (count_out != shifts) std::cout << "No." << std::endl;
        else{
            std:: cout << "Yes." << std::endl;
            for (int i = 0; i < count; ++i) {
                if (command[i] == 'i') std::cout << "in" << std::endl;
                else std::cout << "out" << std::endl;
            }
        }
        std::cout << "FINISH" << std::endl;
    }
    return 0;
}
