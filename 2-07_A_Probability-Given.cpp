#include <cstdio>
#include <iostream>
#include <string.h>

int n, r;
double p[25], p_each[25], p_given;
bool in_given[25];

void cal(int index, int cnt) 
{
	if (cnt == r)
	{
		double total = 1.0;
		for (int i = 0; i < n; i++)
		{
			if (in_given[i]) total *= p[i];
			else total *= (1 - p[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (in_given[i]) p_each[i] += total;
		}
		p_given += total;
	}
	for (int i = index + 1; i < n; i++)
	{
		in_given[i] = 1;
		cal(i, cnt + 1);
		in_given[i] = 0;
	}
}

int main()
{
	int cases = 0;
	while (std::cin >> n >> r && n != 0)
	{
		memset(p_each, 0, sizeof(p_each));
		memset(in_given, 0, sizeof(in_given));
		p_given = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> p[i];
		}
		cal(-1, 0);
		printf("Case %d:\n", ++cases);
		for (int i = 0; i < n; i++)
		{
			printf("%.6lf\n", p_each[i] / p_given);
		}
	}
    return 0;
}

