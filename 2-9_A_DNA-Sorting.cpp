#include <iostream>
#include <cstring>
#include <algorithm>

struct Str{
    char s[55];
    int cnt;
}str[105];

bool cmp(Str a, Str b){
    if (a.cnt < b.cnt) return 1;
    return 0;
}

int main() {
    int n = 0, m = 0;
    int a, c, g, sum;
    while (std::cin >> n >> m){
        for (int i = 0; i < m; ++i) {
            std::cin >> str[i].s;
        }
        for (int i = 0; i < m; ++i) {
            sum = 0;
            a = c = g = 0;
            for (int j = strlen(str[i].s) - 1; j >= 0; --j) {
                if (str[i].s[j] == 'A'){
                    ++a;
                    continue;
                }
                if (str[i].s[j] == 'C'){
                    ++c;
                    sum += a;
                    continue;
                }
                if (str[i].s[j] == 'G'){
                    ++g;
                    sum += (a + c);
                    continue;
                }
                if (str[i].s[j] == 'T'){
                    sum += (a + c + g);
                    continue;
                }
            }
            str[i].cnt = sum;
        }
        std::sort(str, str + m, cmp);
        for (int i = 0; i < m; ++i) {
            std::cout << str[i].s << std::endl;
        }
    }
    return 0;
}
