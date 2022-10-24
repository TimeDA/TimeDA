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
 
 int t, n;
 int D[1 << 16], L[1 << 16];
 int mem[1 << 8][1 << 8];
 int end;
 
 int dfs(int from, int x)
 {
 	if (x == n)
 		return 1;
 	if (mem[from][x] != -1)
 		return mem[from][x];
 	int len = min(L[x], D[x] - D[from]);
 	mem[from][x] = 0;
 	for(int i = x + 1; i <= n; ++i)
 		if (len >= D[i] - D[x])
 			if (dfs(x, i))
 				return mem[from][x] = 1;
 	return 0;
 }
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &t);
 	for(int i = 0; i < t; ++i)
 	{
 		scanf("%d", &n);
 		D[0] = 0, L[0] = 0;
 		for(int j = 1; j <= n; ++j)
 			scanf("%d%d", &D[j], &L[j]);
 		scanf("%d", &D[n + 1]);
 		L[n + 1] = (int)1e9;
 		n++;
 		printf("Case #%d: ", i + 1);
 		memset(mem, -1, sizeof(mem));
 		if (dfs(0, 1))
 			printf("YES\n");
 		else
 			printf("NO\n");
 	}
 	return 0;
 }