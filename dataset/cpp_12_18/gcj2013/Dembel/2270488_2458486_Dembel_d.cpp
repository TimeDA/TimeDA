#include <vector>
 #include <list>
 #include <map>
 #include <set>
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
 #include <cstring>
 #include <string>
 #include <cstdarg>
 
 #pragma comment(linker, "/STACK:64000000")
 
 #define DBG2 1
 
 void dbg(const char * fmt, ...)
 {
 #ifdef DBG1
 #if DBG2
 	va_list args;
 	va_start(args, fmt);
 	vfprintf(stderr, fmt, args);
 	va_end(args);
 
 	fflush(stderr);
 #endif
 #endif
 }
 
 using namespace std;
 
 #define clr(a) memset(a, 0, sizeof(a))
 #define fill(a, b) memset(a, b, sizeof(a))
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef std::pair<int, int> pii;
 
 bool hasKeyAfterOpen(const vector<int>& keysOnStart, const vector<vector<int>>& keysInChest, const vector<int>& lock, int openedMask, int needKey)
 {
 	int countKey = 0;
 	for (int i = 0; i < int(keysOnStart.size()); ++i)
 		if (keysOnStart[i] == needKey)
 			++countKey;
 	for (int i = 0; i < int(lock.size()); ++i)
 	{
 		if (openedMask & (1 << i))
 		{
 			if (lock[i] == needKey)
 				--countKey;
 			for (int j = 0; j < int(keysInChest[i].size()); ++j)
 				if (keysInChest[i][j] == needKey)
 					countKey++;
 		}
 	}
 	return countKey >= 1;
 }
 
 int main()
 {
 #ifdef DBG1
 	freopen(".in", "r", stdin);
 	freopen(".out", "w", stdout);
 	freopen(".err", "w", stderr);
 #endif
 
 	int tt;
 	scanf("%d", &tt);
 	for (int ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d: ", ii);
 		int k, n;
 		scanf("%d%d", &k, &n);
 		vector < int > keysOnStart(k);
 		for (int i = 0; i < k; ++i)
 			scanf("%d", &keysOnStart[i]);
 
 		vector < int > lock(n);
 		vector < vector<int> > keysInChest(n);
 		for (int i = 0; i < n; ++i)
 		{
 			int cnt;
 			scanf("%d%d", &lock[i], &cnt);
 			keysInChest[i].resize(cnt);
 			for (int j = 0; j < cnt; ++j)
 				scanf("%d", &keysInChest[i][j]);
 		}
 
 		vector <int> dp(1 << n, -1);
 		dp[(1 << n) - 1] = 0;
 		for (int mask = (1 << n) - 2; mask >= 0; --mask)
 		{
 			for (int i = 0; i < n && dp[mask] == -1; ++i)
 				if ((mask & (1 << i)) == 0)
 				{
 					int nextMask = mask ^ (1 << i);
 					if (dp[nextMask] != -1 && hasKeyAfterOpen(keysOnStart, keysInChest, lock, mask, lock[i]))
 						dp[mask] = i;
 				}
 		}
 
 		if (dp[0] != -1)
 		{
 			vector <int> res;
 			int curMask = 0;
 			while (curMask != (1 << n) - 1)
 			{
 				printf("%d ", dp[curMask] + 1);
 				curMask ^= (1 << dp[curMask]);
 			}
 			printf("\n");
 		}
 		else
 			printf("IMPOSSIBLE\n");
 
 		fflush(stdout);
 	}
 
 	return 0;
 }