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
		int N;
		scanf("%d", &N);
		vector<pair<int, int>> vp;
		for (int i = 0; i < N; ++i)
		{
			int D, B, C;
			scanf("%d%d%d", &D, &B, &C);
			vp.push_back({ D + B, D - C });
		}

		int retA = 0, retB = -1;

		for (int i = 0; i < N; ++i)
		{
			int left_value = vp[i].first;
			int right_value = 0;
			bool is_set_left = false;
			bool is_set_right = false;
			int cur_max = -1;

			for (int j = i; j < N; ++j)
			{
				if (vp[j].first != left_value)
				{
					if (is_set_right)
					{
						if (right_value != vp[j].second)
						{
							break;
						}
					}
					else
					{
						right_value = vp[j].second;
						is_set_right = true;
					}
				}

				cur_max = (j + 1) - i;
			}

			left_value = 0;
			right_value = vp[i].second;
			for (int j = i; j < N; ++j)
			{
				if (vp[j].second != right_value)
				{
					if (is_set_left)
					{
						if (left_value != vp[j].first)
						{
							break;
						}
					}
					else
					{
						left_value = vp[j].first;
						is_set_left = true;
					}
				}

				if (cur_max < (j + 1) - i)
				{
					cur_max = (j + 1) - i;
				}
			}
			if (retA < cur_max)
			{
				retA = cur_max;
				retB = 0;
			}
			if (retA == cur_max)
			{
				retB++;
			}
		}
		printf("Case #%d: %d %d\n", cn, retA, retB);
	}
}