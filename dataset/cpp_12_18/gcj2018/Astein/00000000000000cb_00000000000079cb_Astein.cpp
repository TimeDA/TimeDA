#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int N;
		scanf("%d", &N);
		vector<int> a(N), sorted;
		vector<int> odds, evens;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
			if (i % 2 == 0)
			{
				evens.push_back(a[i]);
			}
			else
			{
				odds.push_back(a[i]);
			}
		}

		sort(evens.begin(), evens.end());
		sort(odds.begin(), odds.end());

		for (int i = 0; i < evens.size(); ++i)
		{
			sorted.push_back(evens[i]);
			if (i != odds.size())
			{
				sorted.push_back(odds[i]);
			}
		}

		int error_index = -1;
		for (int i = 0; i < sorted.size() - 1; ++i)
		{
			if (sorted[i] > sorted[i + 1])
			{
				error_index = i;
				break;
			}
		}
		if (error_index == -1)
		{
			printf("Case #%d: OK\n", cn);
		}
		else
		{
			printf("Case #%d: %d\n", cn, error_index);
		}
	}
}