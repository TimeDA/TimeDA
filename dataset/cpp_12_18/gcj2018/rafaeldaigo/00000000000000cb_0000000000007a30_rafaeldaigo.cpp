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
		int a;
		int x, y;
		scanf("%d", &a);

		int b = max((a + 2) / 3, 3);
		bool prepared[4][1000];
		for (int i = 1; i <= b; i++)
		{
			prepared[1][i] = prepared[2][i] = prepared[3][i] = false;
		}
		printf("2 2\n");
		fflush(stdout);

		int next = 2;
		while(true)
		{
			scanf("%d %d", &x, &y);

			if (x == 0 && y == 0)
				break;
			if (x == -1 && y == -1)
				return 0;
			prepared[x][y] = true;
			if (prepared[1][next - 1] && prepared[2][next - 1] && prepared[3][next - 1])
			{
				next++;
			}
			printf("2 %d\n", min(next, b - 1));
			fflush(stdout);
		}
	}
	return 0;
}
