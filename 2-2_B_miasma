#include <iostream>
#include <iomanip>

int main() {
    int times, n, V, W, tmp, volume;
    double product;
    int P[100];
    std::cin >> times;
    for (int i = 0; i < times; ++i) {
        product = 0;
        volume = 0;
        std::cin >> n >> V >> W;
        for (int j = 0; j < n; ++j) {
            std::cin >> P[j];
        }
        for (int j = 0; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (P[j] > P[k]){
                    tmp = P[j];
                    P[j] = P[k];
                    P[k] = tmp;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (P[j] <= W) {
                product += P[j] * V;
                volume = j + 1;
            }
            else{
                if (W >= (product + P[j] * V)/(j + 1)/V) {
                    product += P[j] * V;
                    volume = j + 1;
                } else break;
            }
        }
        std::cout << volume*V << " ";
        if (volume == 0) std::cout << "0.00";
        else std::cout << std::setprecision(2) << std::fixed
                       << product/(V*volume*100);
        std::cout << std::endl;

    }
    return 0;
}
