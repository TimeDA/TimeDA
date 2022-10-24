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
		printf("Case #%d: ", cn);
		int C;
		scanf("%d", &C);
		vector<int> B(C);
		for (int i = 0; i < C; ++i)
			scanf("%d", &B[i]);
		if (B[0] == 0 || B[C - 1] == 0)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		vector<string> ret(C, string(C, '.'));

		vector<int> target(C, -1);
		int index = 0;
		for (int i = 0; i < C; ++i)
		{
			for (int j = 0; j < B[i]; ++j)
			{
				target[index] = i;
				index++;
			}
		}
		int max_height = 1;
		for (int i = 0; i < C; ++i)
		{
			int height = 0;
			if (target[i] > i)
			{
				for (int j = i; j < target[i]; ++j)
				{
					ret[height][j] = '\\';
					height++;
				}
			}
			else if (target[i] < i)
			{
				for (int j = i; j > target[i]; --j)
				{
					ret[height][j] = '/';
					height++;
				}
			}
			if (max_height <= height)
			{
				max_height = height + 1;
			}
		}

		printf("%d\n", max_height);
		for (int i = 0; i < max_height; ++i)
			printf("%s\n", ret[i].c_str());
	}
}
