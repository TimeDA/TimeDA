#pragma comment(linker, "/STACK:33554432")
 
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
 #include <complex>
 #include <memory.h>
 
 using namespace std;
 
 typedef long long LL;
 typedef vector<int> vint;
 typedef vector<vector<int> > vvint;
 
 const int MOD = 1000002013;
 
 int T;
 int n, m;
 
 int O[1 << 7], E[1 << 7], P[1 << 7];
 
 LL cnt[1 << 7];
 
 LL f(int len)
 {
 	LL res = n * (n + 1) / 2;
 	res -= (n - len) * (n - len + 1) / 2;
 	res %= MOD;
 	return res;
 }
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	scanf("%d", &T);
 	for(int I = 1; I <= T; ++I)
 	{
 		scanf("%d%d", &n, &m);
 		for(int i = 0; i < m; ++i)
 		{
 			scanf("%d%d%d", &O[i], &E[i], &P[i]);
 			O[i]--, E[i]--;
 		}
 		LL res = 0;
 		for(int i = 0; i < m; ++i)
 		{
 			int len = E[i] - O[i];
 			LL add = f(len);
 			res = (res + P[i] * add) % MOD;
 		}
 		memset(cnt, 0, sizeof(cnt));
 		for(int i = 0; i < m; ++i)
 			for(int j = O[i]; j < E[i]; ++j)
 				cnt[j] += P[i];
 		while (1)
 		{
 			int ok = 0;
 			for(int i = 0; i < n; ++i)
 			{
 				if (cnt[i])
 				{
 					int to = i;
 					LL Min = cnt[i];
 					while (cnt[to])
 					{
 						Min = min(Min, cnt[to]);
 						to++;
 					}
 					int len = to - i;
 					for(int j = i; j < to; ++j)
 						cnt[j] -= Min;
 					res = (res - (Min * f(len)) % MOD + MOD) % MOD;
 					ok = 1;
 				}
 				if (ok)
 					break;
 			}
 			if (!ok)
 				break;
 		}
 		printf("Case #%d: %lld\n", I, res);
 	}
 
 	return 0;
 }