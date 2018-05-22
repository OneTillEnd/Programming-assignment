#include <iostream>
#include <cstring>
#include <algorithm>

struct node{
    int x, y;
}a[5005];
bool map[5005][5005];
int n, row, col, dx, dy;

bool cmp(node a, node b){
    if (a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}

bool in_map(int x, int y){
    return x >= 1 && x <= row && y >= 1 && y <= col;
}

int cal(int x, int y){
    int sum = 1;
    while (in_map(x + dx, y + dy)){
        if (map[x + dx][y + dy]){
            ++sum;
            x += dx;
            y += dy;
        } else return 0;
    }
    return sum;
}

int main() {
    int i, j, ans;
    while (std::cin >> row >> col){
        memset(map, 0, sizeof(map));
        std::cin >> n;
        for (i = 0; i < n; ++i) {
            std::cin >> a[i].x >> a[i].y;
            map[a[i].x][a[i].y] = true;
        }
        std::sort(a, a + n, cmp);

        ans = 2;
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                dx = a[j].x - a[i].x;
                dy = a[j].y - a[i].y;
                if (in_map(a[i].x - dx, a[i].y - dy))
                    continue;
                if (a[i].y + ans*dy > col)
                    break;
                if (!in_map(a[i].x + ans*dx, a[i].y + ans*dy))
                    continue;
                ans = std::max(ans, cal(a[i].x, a[i].y));
            }
        }
        if (ans < 3) std::cout << "0" << std::endl;
        else std::cout << ans << std::endl;
    }
    return 0;
}
