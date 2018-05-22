#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

int a[505][505], b[505][505], c[505][505];
bool vis[505][505];

int main() {
    srand((unsigned)time(NULL));
    int n = 0;
    int row, col, item;
    while (~scanf("%d", &n)){
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &b[i][j]);
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &c[i][j]);
            }
        }
        bool flag = false;
        for(int i = 0; i < 80000; ++i) {
            row = rand() % n;
            col = rand() % n;
            if (vis[row][col]) continue;
            vis[row][col] = true;
            item = 0;
            for(int j = 0; j < n; ++j) {
                item = item + a[row][j] * b[j][col];
            }
            if (item != c[row][col]){
                flag = true;
                break;
            }
        }
        if (!flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
