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
 
 typedef long long LL;
 typedef vector<int> vint;
 typedef vector<vint> vvint;
 
 int t, W, L, n;
 pair<int, int> r[1 << 10];
 int x[1 << 10], y[1 << 10];
 
 const int dx[4] = {1, 0, -1, 0};
 const int dy[4] = {0, 1, 0, -1};
 
 int ok(int k)
 {
 	for(int i = 0; i < n; ++i)
 	{
 		if (i == k)
 			continue;
 		LL xx = x[r[i].second] - x[r[k].second];
 		LL yy = y[r[i].second] - y[r[k].second];
 		LL rr = r[i].first + r[k].first;
 		if (xx * xx + yy * yy < rr * rr)
 			return 0;
 	}
 	return 1;
 }
 
 bool bound(int x, int y)
 {
 	return x >= 0 && y >= 0 && x <= W && y <= L;
 }
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &t);
 	for(int i = 0; i < t; ++i)
 	{
 		scanf("%d%d%d", &n, &W, &L);
 		for(int j = 0; j < n; ++j)
 		{
 			scanf("%d", &r[j].first);
 			r[j].second = j;
 		}
 		sort(r, r + n);
 		memset(x, 0, sizeof(x));
 		memset(y, 0, sizeof(y));
 		printf("Case #%d:", i + 1);
 		int cur = 0;
 		for(int j = n - 2; j >= 0; --j)
 		{
 			x[r[j].second] = x[r[j + 1].second], y[r[j].second] = y[r[j + 1].second];
 			while (!ok(j))
 			{
 				if (!bound(x[r[j].second] + dx[cur], y[r[j].second] + dy[cur]))
 					++cur;
 				x[r[j].second] += dx[cur];
 				y[r[j].second] += dy[cur];
 			}
 		}
 		for(int j = 0; j < n; ++j)
 			printf(" %d %d", x[j], y[j]);
 		printf("\n");
 	}
 	return 0;
 }