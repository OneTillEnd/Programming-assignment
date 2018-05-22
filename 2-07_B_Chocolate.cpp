#include <iostream>
#include <cstring>
#include <stdio.h>
	
int c, n, m;
double dp[1005][105];

int main()
{
	while (std::cin >> c && c != 0)
	{
		std::cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		if (m > n || m > c || (m + n)%2)
		{
			std::cout << "0.000\n";
			continue;
		}
		if (n > 1000)
		{
			n = 1000 + n % 2;
		}
		dp[0][0] = 1.0;
		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = dp[i - 1][1] / c;
			dp[i][c] = dp[i - 1][c - 1] / c;
			for (int j = 1; j < c; j++)
			{
				dp[i][j] = dp[i - 1][j - 1] * (c - j + 1) / c + dp[i - 1][j + 1] * (j + 1) / c;
			}
		}
		printf("%.3f\n", dp[n][m]);
	}
    return 0;
}

