#include <iostream>
#include <cstring>

char s[105];
int s_len, sum0, sum00;
int p_shoot, p_rotate;

int main()
{
	while (std::cin >> s)
	{
		s_len = strlen(s);
		sum0 = sum00 = 0;
		s[s_len] = s[0];
		for (int i = 0; i < s_len; i++)
		{
			if (s[i] == '0') 
			{
				++sum0;
				if (s[i + 1] == '0') ++sum00;
			}
		}
		p_shoot = sum00 * s_len;
		p_rotate = sum0 * sum0;
		if (p_shoot > p_rotate) std::cout << "SHOOT\n";
		else if (p_shoot < p_rotate) std::cout << "ROTATE\n";
		else std::cout << "EQUAL\n";
	}
    return 0;
}

