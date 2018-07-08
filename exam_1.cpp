#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

int a[100005];

int main()
{
    int n, m, target;
    int finder = 0, head, tail;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        if(target == a[0])
        {
            printf("%d\n", 0);
            continue;
        }
        head = 0;
        tail = n;
        scanf("%d", &target);
        finder = n/2;
        while (true)
        {
            if (target < a[finder])
            {
                finder = (head + finder)/2;
            }
            if (target > a[finder])
            {
                finder = (tail + finder)/2;
            }
            else{
                printf("%d\n", finder);
                break;
            }
        }
    }
    return 0;
}
