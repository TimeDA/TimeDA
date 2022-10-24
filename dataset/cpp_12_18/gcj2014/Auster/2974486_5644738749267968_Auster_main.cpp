#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <memory.h>
 
 using namespace std;
 
 int T;
 int n;
 
 double a[1 << 10], b[1 << 10];
 
 int dp[1 << 10][1 << 10];
 int used[1 << 10];
 
 int fair()
 {
 	memset(used, 0, sizeof(used));
 	int res = 0;
 	for(int i = 0; i < n; ++i)
 	{
 		bool ok = 0;
 		for(int j = 0; j < n; ++j)
 		{
 			if (!used[j] && a[i] < b[j])
 			{
 				used[j] = 1;
 				ok = 1;
 				break;
 			}
 		}
 		if (!ok)
 		{
 			res++;
 			for(int j = 0; j < n; ++j)
 				if (!used[j])
 				{
 					used[j] = 1;
 					break;
 				}
 		}
 	}
 	return res;
 }
 
 int unfair(int La, int Lb)
 {
 	if (La == n)
 		return 0;
 	int & res = dp[La][Lb];
 	if (res != -1)
 		return res;
 	res = 0;
 	int Rb = n - (La - Lb) - 1;
 	if (a[La] > b[Lb])
 	{
 		res = max(res, 1 + unfair(La + 1, Lb + 1));
 		res = max(res, unfair(La + 1, Lb));
 	}
 	else
 	{
 		res = max(res, unfair(La + 1, Lb + 1));
 		res = max(res, unfair(La + 1, Lb));
 	}
 	return res;
 }
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &T);
 	for(int I = 1; I <= T; ++I)
 	{
 		scanf("%d", &n);
 		for(int i = 0; i < n; ++i)
 			scanf("%lf", &a[i]);
 		for(int i = 0; i < n; ++i)
 			scanf("%lf", &b[i]);
 		sort(a, a + n);
 		sort(b, b + n);
 		memset(dp, -1, sizeof(dp));
 		printf("Case #%d: %d %d\n", I, unfair(0, 0), fair()); 
 	}
 	return 0;
 }