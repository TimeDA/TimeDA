#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		int n;
		int a[110];
		int target[110];
		char layout[110][110];
		scanf("%d\n", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		bool possible = true;
		if (a[0] == 0 || a[n-1] == 0)
			possible = false;
		int resp = 0;

		if (possible)
		{
			int index = 0;
			for (int i = 0; i < n; i++)
			{
				while (a[index] == 0)
				{
					index++;
				}
				target[i] = index;
				a[index]--;
				resp = max(resp, abs(i - target[i]));
			}

			for (int i = 0; i <= resp; i++)
			{
				for (int j = 0; j < n; j++)
				{
					layout[i][j] = '.';
				}
				layout[i][n] = 0;
			}
			for (int i = 0; i < n; i++)
			{
				if (target[i] > i)
				{
					for (int j = i; j < target[i]; j++)
					{
						layout[j - i][j] = '\\';
					}
				}
				else if (target[i] < i)
				{
					for (int j = i; j > target[i]; j--)
					{
						layout[i - j][j] = '/';
					}
				}
			}
		}

		if (possible)
		{
			printf("Case #%d: %d\n", t + 1, resp + 1);
			for (int i = 0; i <= resp; i++)
			{
				printf("%s\n", layout[i]);
			}
		}
		else
			printf("Case #%d: IMPOSSIBLE\n", t + 1);
	}
	return 0;
}
