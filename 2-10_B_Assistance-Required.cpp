#include <iostream>
#include <stdio.h>
#include <cstring>



int main() {
    int vis[50005];
    int lucky[5005];
    int cnt = 0;
    int j, step;
    memset(vis, 0, sizeof(vis));

    for (int i = 2; i < 50005; ++i) {
        if (vis[i] == 0) {
            lucky[cnt++] = i;
            j = i + 1;
            step = 0;
            while (j < 50005) {
                if (vis[j] == 0) {
                    ++step;
                }
                if (step == i) {
                    vis[j] = 1;
                    step = 0;
                }
                ++j;
            }
        }
    }
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        printf("%d\n", lucky[n-1]);
    }
    return 0;
}
