#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {
    std::vector<long long> heights;
    std::vector<int> stk;
    int n, tmp;
    int j;
    long long sum;

    while (scanf("%d", &n) != EOF && n != 0) {
        heights.clear();
        stk.clear();
        sum = 0;
        j = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            heights.push_back(tmp);
        }
        heights.push_back(0);

        while (j < heights.size()) {
            if (stk.empty() || heights[j] > heights[stk.back()]) {
                stk.push_back(j);
                ++j;
            } else {
                int t = stk.back();
                stk.pop_back();
                sum = std::max(sum, (long long)heights[t]*(stk.empty() ? j : j-stk.back()-1));
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
