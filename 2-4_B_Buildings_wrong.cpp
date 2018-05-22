#include <iostream>
#include <algorithm>

int pdv;
int w[100000], s[100000];
int number = 0;

int cal(int w[], int s[], int list[], int n){
    int weight = 0;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        weight += w[list[i - 1]];
        ans = std::max(ans, weight - s[list[i]]);
    }
    if (ans < 0) return 0;
    else return ans;
}

void permutate_cal(int list[], int n, int cnt){
    if (n == 1){
        pdv = std::min(pdv, cal(w, s, list, number));
    }
    else {
        for (int i = 0; i < n; ++i) {
            std::swap(list[cnt], list[i]);
            ++cnt;
            permutate_cal(list, n - 1, cnt);
            --cnt;
            std::swap(list[cnt], list[i]);
        }

    }
}

int main() {
    int list[100000];
    int cnt, n;
    for (int i = 0; i < 100000; ++i) {
        list[i] = i;
    }
    while (std::cin >> number){
        cnt = 0;
        pdv = 100000;
        n = number;
        for (int i = 0; i < number; ++i) {
            std::cin >> w[i] >> s[i];
        }
        permutate_cal(list, n, cnt);
        std::cout << pdv << std::endl;
    }
    return 0;
}
