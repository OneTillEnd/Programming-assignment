#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <time.h>

struct node{
    int num, index;
}a[200];

bool cmp(node a, node b){
    return a.num > b.num;
}

int main() {
    srand((unsigned)time(NULL));
    int k, sum1 = 0, sum2 = 0, rnd1, rnd2;
    std::cin >> k;
    for (int i = 0; i < 3*k; ++i) {
        std::cin >> a[i].num;
        a[i].index = i;
    }
    std::sort(a, a + 3*k, cmp);
    for (int i = 0; i < k; ++i) {
        sum1 += a[i].num;
        sum2 += a[i+k].num;
    }
    while (sum1 <= 500*k || sum2 <= 500*k) {
        rnd1 = rand() % k;
	rnd2 = rand() % k + k;
	sum1 = sum1 - a[rnd1].num + a[rnd2].num;
	sum2 = sum2 - a[rnd2].num + a[rnd1].num;
	std::swap(a[rnd1], a[rnd2]);
    }
    for(int i = 0; i < 3*k; ++i) {
        std::cout << a[i].index + 1 << std::endl;
    }
    return 0;
}
