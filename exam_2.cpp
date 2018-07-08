#include <iostream>
#include <algorithm>
#include <cstring>

int a[100005];

void partify(int a[], int head, int tail)
{
    if (head >= tail) return;
    int piv = tail;
    for (int i = 0; i < tail - head; ++i)
    {
        if (i < piv && a[i] > a[piv])
        {
            std::swap(a[i], a[piv]);
            piv = i;
            continue;
        }
        if (i < piv && a[i] == a[piv])
        {
            std::swap(a[i+1], a[piv]);
            piv = i+1;
            continue;
        }
        if (i > piv && a[i] < a[piv])
        {
            std::swap(a[i], a[piv]);
            piv = i;
            continue;
        }
        if (i > piv && a[i] == a[piv])
        {
            std::swap(a[piv+1], a[i]);
            piv = piv + 1;
            continue;
        }
    }
    partify(a, head, piv-1);
    partify(a, piv+1, tail);
}

int main()
{
    int n = 0;
    while(std::cin >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        partify(a, 0, n-1);
        for(int i = 0; i < n; ++i)
        {
            printf("%d ", a[i]);
        }
        std::cout << std::endl;
    }
    return 0;
}
