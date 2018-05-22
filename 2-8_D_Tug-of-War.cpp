#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <cmath>

int main() {
    srand((unsigned)time(NULL));
    int n, cnt, a[110], b[55], c[55];
    int len_b, len_c, sum_b, sum_c;
    int devia, x, y, sum_x, sum_y;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
        }
        if (n == 1) {
            printf("0 %d\n", a[0]);
            continue;
        }
        std::sort(a, a+n);
        sum_b = sum_c = 0;
        if (n & 1) {
            len_b = n/2 + 1;
            len_c = n - len_b;
            int i = 0;
            for(; i < len_b; ++i) {
                b[i] = a[i];
                sum_b += a[i];
            }
            for(; i < n; ++i) {
                c[i - len_b] = a[i];
                sum_c += a[i];
            }
        }
        else {
            len_b = len_c = n/2;
            int i = 0;
            for(; i < len_b; ++i) {
                b[i] = a[i];
                sum_b += a[i];
            }
            for(; i < n; ++i) {
                c[i - len_b] = a[i];
                sum_c += a[i];
            }
        }
        devia = abs(sum_b - sum_c);
        cnt = 1000000;
        while (cnt--) {
            x = rand() % len_b;
            y = rand() % len_c;
            sum_x = sum_b - b[x] + c[y];
            sum_y = sum_c + b[x] - c[y];
            if (abs(sum_x - sum_y) < devia) {
                sum_b = sum_x;
                sum_c = sum_y;
                std::swap(b[x], c[y]);
                devia = abs(sum_x - sum_y);
            }
        }
        if(sum_b > sum_c) {
            std::swap(sum_b, sum_c);
        }
        printf("%d %d\n", sum_b, sum_c);
    }
    return 0;
}
