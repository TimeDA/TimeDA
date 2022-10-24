#include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <queue>
 #include <algorithm>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <memory.h>
 #include <ctime>
 #include <bitset>
 #include <unordered_map>
 
 using namespace std;
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.14159265358979
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 
 int dp[(1 << 15) + 7][16];
 
 int how[16];
 int who[16];
 int startBad;
 int n;
 vector<int> all;
 
 int r(int mask, int p)
 {
 	if (p == n)
 	{
 		int res = 0;
 		FOR(i,0,15)
 		if ((mask >> i) & 1)
 			res++;
 		return res;
 	}
 	if (dp[mask][p] != -1)
 		return dp[mask][p];
 	int res = 20;
 	if (how[p] == 0)
 	{
 		if (who[p] == 0)
 		{
 			FOR(j, 0, 15)
 			{
 				if (((mask >> j) & 1) == 0)
 				{
 					res = min(res, r(mask | (1 << j), p + 1));
 				}
 			}
 			return dp[mask][p] = res;
 		}
 		else
 		{
 			int v = lower_bound(all.begin(), all.end(), who[p]) - all.begin();
 			if ((mask >> v) & 1)
 				return dp[mask][p]=20;
 			return dp[mask][p]=r(mask | (1 << v), p + 1);
 		}
 	}
 	else
 	{
 		if (who[p] == 0)
 		{
 			FOR(j, 0, 15)
 			{
 				if (((mask >> j) & 1) == 1)
 				{
 					res = min(res, r(mask ^ (1 << j), p + 1));
 				}
 			}
 			return dp[mask][p] = res;
 		}
 		else
 		{
 			int v = lower_bound(all.begin(), all.end(), who[p]) - all.begin();
 			if (((mask >> v) & 1)==0)
 				return dp[mask][p] = 20;
 			return dp[mask][p] = r(mask ^ (1 << v), p + 1);
 		}
 	}
 }
 char s[3];
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 	double beg = clock();
 #else
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 #endif
 
 	int t;
 	scanf("%d", &t);
 	FOR(it, 1, t + 1)
 	{
 		MEMS(dp, -1);
 		scanf("%d", &n);
 		all.clear();
 		FOR(i, 0, n)
 		{
 			scanf("%s%d", s, &who[i]);
 			if (s[0] == 'E')
 				how[i] = 0;
 			else
 				how[i] = 1;
 			if (who[i] != 0)
 				all.push_back(who[i]);
 		}
 		sort(all.begin(), all.end());
 		all.resize(unique(all.begin(), all.end())-all.begin());
 		int res = 20;
 		FOR(mask, 0, (1 << 15))
 		{
 			int now = r(mask, 0);
 			res = MIN(res, now);
 		}
 		printf("Case #%d: ",it);
 		if (res == 20)
 			printf("CRIME TIME\n");
 		else
 			printf("%d\n", res);
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }