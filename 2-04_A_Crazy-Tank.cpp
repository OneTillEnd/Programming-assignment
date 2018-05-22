#include <iostream>
#include <cmath>
#include <algorithm>

const double pi = acos(-1.0);
const double g = 9.8;
double v[200];
double h, l1, r1, l2, r2;
int n;

int judge(double theta){
    int balls = 0;
    for (int i = 0; i < n; ++i) {
        double v0x = v[i] * cos(theta);
        double v0y = v[i] * sin(theta);
        double v1y = sqrt(v0y * v0y + 2 * g * h);
        double t = (v1y + v0y) / g;
        double s = v0x * t;
        if (s >= l2 && s <= r2) return 0;
        if (s >= l1 && s <= r1) ++balls;
    }
    return balls;
}

int main() {
    while (std::cin >> n && n){
        std::cin >> h >> l1 >> r1 >> l2 >> r2;
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
        }
        double delta = pi / 1000;
        int ans = 0;
        for (double i = -pi / 2; i <= pi/2; i += delta) {
            ans = std::max(ans, judge(i));
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
