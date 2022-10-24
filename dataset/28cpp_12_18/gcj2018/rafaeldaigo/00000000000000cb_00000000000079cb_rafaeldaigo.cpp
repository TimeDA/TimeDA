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
		int a, i, n;
		vector<int> l1, l2;
		scanf("%d\n", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d\n", &a);
			if (i % 2 == 0)
				l1.push_back(a);
			else
				l2.push_back(a);
		}
		sort(l1.begin(), l1.end());
		sort(l2.begin(), l2.end());
		for (i = 0; i + 1 < n; i++)
		{
			if (i % 2 == 0)
			{
				if (l1[i/2] > l2[i/2])
					break;
			}
			else
			{
				if (l2[i/2] > l1[i/2 + 1])
					break;
			}
		}

		if ((i + 1) == n)
			printf("Case #%d: OK\n", t + 1);
		else	
			printf("Case #%d: %d\n", t + 1, i);
	}
	return 0;
}
