#include <cstdio>

struct node{
    int x, y;
}a[705];

int main() {
    int n;
    while (scanf("%d", &n) && n != 0){
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a[i].x, &a[i].y);
        }
        int max = 2;
        int ans;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = 2;
                for (int k = j + 1; k < n; ++k) {
                    if ((a[j].x-a[i].x)*(a[k].y-a[j].y) == (a[j].y-a[i].y)*(a[k].x-a[j].x))
                        ++ans;
                }
                if (ans > max) max = ans;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
