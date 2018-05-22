#include <iostream>

int main() {
    int n, m, tmp, count;
    int list[3005], sorted[1005];
    while (std::cin >> n >> m){
        count = 0;

        for (int i = 0; i < n; ++i) {
            std::cin >> list[i];
        }
        for (int i = 0; i < 1005; ++i) {
            sorted[i] = 0;
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                tmp = list[i] + list[j];
                if (tmp <= sorted[1000]) continue;
                for (int k = count + 1; k > 0; --k) {
                    if (tmp <= sorted[k - 1] && tmp > sorted[k]){
                        ++count;
                        for (int l = count + 1; l > k; --l) {
                            sorted[l] = sorted[l - 1];
                        }

                        sorted[k] = tmp;
                        break;
                    }
                    if (tmp > sorted[0]){
                        ++count;
                        for (int l = count + 1; l > 0; --l) {
                            sorted[l] = sorted[l - 1];
                        }
                        sorted[0] = tmp;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            std::cout << sorted[i];
            if (i != m - 1) std::cout << " ";
            else std::cout << std::endl;
        }
    }
    return 0;
}
