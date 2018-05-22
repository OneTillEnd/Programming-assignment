#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>

int main() {
    int n;
    int l1, l2, tmp;
    long long ans = 0;
    while (~scanf("%d", &n)) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            pq.push(tmp);
        }
        while (pq.size() > 1) {
            l1 = pq.top();
            pq.pop();
            l2 = pq.top();
            pq.pop();

            ans += (long long) (l1 + l2);
            pq.push(l1 + l2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
