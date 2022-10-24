#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int N, L;
		scanf("%d%d", &N, &L);

		vector<int> a(N + 1, 0);
		int default_step = 100 / N;
		for (int i = 0; i <= N; ++i)
		{
			int up = i * 1000 / N;
			a[i] = (up + 5) / 10;
		}

		for (int i = 1; i <= N; ++i)
		{
			a[i] = a[i] - default_step * i;
		}

		int ret = default_step * N;

		vector<int> minpos(N + 1, -1);
		for (int i = 0; i <= N; ++i)
		{
			if (minpos[a[i]] == -1)
			{
				minpos[a[i]] = i;
			}
		}

		int remain = N;

		vector<int> need;
		for (int i = 0; i < L; ++i)
		{
			int C;
			scanf("%d", &C);

			ret += a[C];
			remain -= C;
			if (minpos[a[C] + 1] != -1)
			{
				need.push_back(minpos[a[C] + 1] - C);
			}
		}

		int need_zero = minpos[a[0] + 1];

		sort(need.begin(), need.end());
		for (int i = 0; i < need.size(); ++i)
		{
			if (need[i] > need_zero)
			{
				break;
			}
			if (remain >= need[i])
			{
				remain -= need[i];
				ret++;
			}
		}

		if (remain > 0 && need_zero != -1)
		{
			ret += remain / need_zero;
		}
		printf("Case #%d: %d\n", cn, ret);
	}
}