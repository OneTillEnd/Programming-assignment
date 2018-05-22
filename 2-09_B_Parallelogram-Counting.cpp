#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

struct point{
    int x, y;
};

point a[1005], map[500005];

int cmp(const void *a, const void *b){
    point *p1 = (point *)a, *p2 = (point *)b;
    if (p1->x == p2->x)
        return (p1->y - p2->y);
    else return (p1->x - p2->x);
}

int main() {
    int t, n;
    int j, cnt;
    int m, c;
    scanf("%d", &t);
    for (int k = 0; k < t; ++k) {
        m = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        for (int i = 1; i <= n; ++i) {
            for (j = i + 1; j <= n; ++j) {
                map[m].x = a[i].x + a[j].x;
                map[m].y = a[i].y + a[j].y;
                ++m;
            }
        }
        qsort(map, m, sizeof(map[0]), cmp);
        j = 1, c = 1, cnt = 0;
        while (j < m) {
            if (map[j].x == map[j-1].x && map[j].y == map[j-1].y) {
                ++c;
            } else {
                cnt += c*(c - 1)/2;
                c = 1;
            }
            ++j;
        }
        cnt += c*(c - 1)/2;
        printf("%d\n", cnt);
    }
    return 0;
}
