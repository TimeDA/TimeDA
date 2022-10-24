#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int ans[51][51][51][51];
int rec(int r, int b, int lr, int lb)
{
	if (!r && !b)
		return 0;
	if (ans[r][b][lr][lb])
		return ans[r][b][lr][lb];
	int res = 0;
	for (int i = lr; i <= r; i++)
		for (int j = i == lr ? lb : 0; j <= b; j++)
			if (i != lr || j != lb)
				res = max(res, 1 + rec(r - i, b - j, i, j));
	if (!res)
		res = -1000000;
	return ans[r][b][lr][lb] = res;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		int r, b;
		scanf("%d%d", &r, &b);
		printf("Case #%d: %d\n", ts, rec(r, b, 0, 0));
	}
	return 0;
}