/* 2018.4.7 Celicath */
#include <stdio.h>
#include <string.h>

int T, D;
char line[100];

long long damage()
{
	long long result = 0;
	long long charge = 1;
	for (int i = 0; line[i]; i++)
	{
		if (line[i] == 'C')
			charge <<= 1;
		else result += charge;
	}
	return result;
}

int main()
{
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%d%s", &D, line);
		int len = (int)strlen(line);

		for (int i = 0;; i++)
		{
			if (damage() <= D)
			{
				printf("Case #%d: %d\n", c_n, i);
				break;
			}

			bool isS = false;
			for (int j = len - 1; ; j--)
			{
				if (!isS)
					isS = line[j] == 'S';
				else if (line[j] == 'C')
				{
					line[j] = 'S';
					line[j + 1] = 'C';
					break;
				}
				if (j == 0)
				{
					printf("Case #%d: IMPOSSIBLE\n", c_n);
					goto hell;
				}
			}
		}
	hell:;
	}
	return -0;
}
