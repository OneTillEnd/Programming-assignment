#include<iostream>
#include<cstring>
#include <cstdio>

#define base 10000
#define maxN 100

void multiply(int a[], int max, int b) {
    int i, array=0;
    for(i = max-1; i >= 0; --i) {
        array += b * a[i];
        a[i] = array % base;
        array /= base;

    }
}

void divide(int a[], int max, int b) {
    int i, div = 0;
    for(i = 0; i < max; ++i) {
        div = div * base + a[i];
        a[i] = div / b;
        div %= b;
    }
}

int main() {
    int n, i;
    int a[101][maxN];
    memset(a[1], 0, maxN * sizeof(int));
    for(i = 2, a[1][maxN-1] = 1; i < 101; ++i) {
        memcpy(a[i], a[i-1], maxN * sizeof(int));
        multiply(a[i], maxN, 4*i - 2);
        divide(a[i], maxN, i+1);
    }
    while(scanf("%d", &n) && n!=-1)
    {
        for(i = 0; i < maxN && a[n][i] == 0; ++i);
        printf("%d", a[n][i++]);
        for(; i < maxN; ++i) {
            printf("%04d", a[n][i]);
        }
        printf("\n");
    }
    return 0;
}
