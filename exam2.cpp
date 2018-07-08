// exam2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <algorithm>
#include <cstring>

int a[100005];

void partify(int a[], int head, int tail)
{
	if (head >= tail) return;
	int piv = tail;
	int cnt = 0;
	int samecnt = 0;
	for (int i = 0; i < tail - head; ++i)
	{
		if (a[i] < a[piv])
		{
			std::swap(a[i], a[cnt++]);
			continue;
		}
		if (a[i] == a[piv])
		{
			std::swap(a[i], a[piv-1-samecnt]);
			--i;
			++samecnt;
			continue;
		}
	}
	while (a[piv] < a[cnt])
	{
		std::swap(a[piv--], a[cnt++]);
	}
	partify(a, head, piv - 1 - samecnt);
	partify(a, piv + 1, tail);
}

int main()
{
	int n = 0;
	while (std::cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			std::cin >> a[i];
		}
		partify(a, 0, n - 1);
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}
