#include <iostream>

int room[55][55];
int m, n;
bool used[55][55];

bool in_map(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int &k){
    if (!(room[x][y] & 2)){
        if (!used[x-1][y] && in_map(x-1, y)){
            ++k;
            used[x-1][y] = true;
            dfs(x-1, y, k);
        }
    }
    if (!(room[x][y] & 8)){
        if (!used[x+1][y] && in_map(x+1, y)){
            ++k;
            used[x+1][y] = true;
            dfs(x+1, y, k);
        }
    }
    if (!(room[x][y] & 1)){
        if (!used[x][y-1] && in_map(x, y-1)){
            ++k;
            used[x][y-1] = true;
            dfs(x, y-1, k);
        }
    }
    if (!(room[x][y] & 4)){
        if (!used[x][y+1] && in_map(x, y+1)){
            ++k;
            used[x][y+1] = true;
            dfs(x, y+1, k);
        }
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> room[i][j];
            used[i][j] = false;
        }
    }
    int count = 0;
    int max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j]){
                used[i][j] = true;
                int k = 1;
                dfs(i, j, k);
                max = std::max(max, k);
                ++count;
            }
        }
    }
    std::cout << count << std::endl << max << std::endl;
    return 0;
}
