#include <iostream>
#include <cmath>

int main() {
    long long n, x1, y1, x2, y2, x, y, d1, d2;
    long long r1 = 0, r2 = 0;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        d1 = pow(std::abs(x - x1), 2) + pow(std::abs(y - y1), 2);
        d2 = pow(std::abs(x - x2), 2) + pow(std::abs(y - y2), 2);
        if (d1 > r1 && d2 > r2){
            if ((d1 + r2) > (d2 + r1)) r2 = d2;
            else if ((d1 + r2) < (d2 + r1)) r1 = d1;
            else
        }
    }
    std::cout << r1 + r2;
    return 0;
}
