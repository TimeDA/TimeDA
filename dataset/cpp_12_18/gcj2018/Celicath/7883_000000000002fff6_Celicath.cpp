/* 2018.4.14 Celicath */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <climits>
#include <set>

int T;
long long R, B, C;
long long M[2000];
long long S[2000];
long long P[2000];

int main()
{
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%lld%lld%lld", &R, &B, &C);

		for (long long i = 0; i < C; i++)
			scanf("%lld%lld%lld", M + i, S + i, P + i);

		long long min = 0;
		long long max = 9223372036854775807;

		while (min < max)
		{
			long long target = (min + max) / 2;
			std::multiset<long long> set;

			for (long long i = 0; i < C; i++)
			{
				set.insert(std::max(std::min((target - P[i]) / S[i], M[i]), (long long)0));
			}
			long long tot = 0;
			long long count = 0;
			for (auto it = set.rbegin(); it != set.rend(); ++it)
			{
				tot += (*it);
				if (++count >= R) break;
			}
			if (tot < B) min = target + 1;
			else max = target;
		}

		printf("Case #%d: %lld\n", c_n, min);
	}
	return -0;
}
