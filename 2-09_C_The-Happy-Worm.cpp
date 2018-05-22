#include <iostream>
#include <algorithm>

struct point{
    int x, y;
};

point a[131080];

bool cmp_x(point a, point b) {
    if (a.x < b.x) return 1;
    if (a.x == b.x) {
        if (a.y < b.y) return 1;
        else return 0;
    } else return 0;
}

bool cmp_y(point a, point b) {
    if (a.y < b.y) return 1;
    if (a.y == b.y) {
        if (a.x < b.x) return 1;
        else return 0;
    } else return 0;
}

int main() {
    int t, m, n, k, cnt;
    scanf("%d", &t);
    while (t--) {
        cnt = 0;
        scanf("%d%d%d", &m, &n, &k);
        for (int i = 1; i <= k; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        a[0].x = 1, a[0].y = 0;
        a[k+1].x = m, a[k+1].y = n + 1;
        std::sort(a + 1, a + k + 1, cmp_x);
        for (int i = 1; i <= k+1; ++i) {
            if (a[i].x == a[i-1].x) {
                if (a[i].y - a[i-1].y >= 3)
                    ++cnt;
            } else {
                cnt += (a[i].x - a[i-1].x - 1);
                if (n - a[i-1].y >= 2)
                    ++cnt;
                if (a[i].y - 1 >= 2)
                    ++cnt;
            }
        }
        a[0].x = 0, a[0].y = 1;
        a[k+1].x = m + 1, a[k+1].y = n;
        std::sort(a + 1, a + k + 1, cmp_y);
        for (int i = 1; i <= k+1; ++i) {
            if (a[i].y == a[i-1].y) {
                if (a[i].x - a[i-1].x >= 3)
                    ++cnt;
            } else {
                cnt += (a[i].y - a[i-1].y - 1);
                if (m - a[i-1].x >= 2)
                    ++cnt;
                if (a[i].x - 1 >= 2)
                    ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
