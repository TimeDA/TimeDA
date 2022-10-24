#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <sstream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int nt;
 
 const long long MOD = 1000002013LL;
 
 set<int> xs;
 map<int, vector< pair<int, int> > > out; 
 
 map<int, int> x2i;
 
 int i2x[10000];
 
 long long nxt[10000];
 long long cur[10000];
 
 int n, m;
 
 long long cost(long long k)
 {
 	if (k == 0) return 0;
 	return (n * k - k * (k - 1) / 2) % MOD;
 }
 
 int main()
 {
 	//freopen("in", "r", stdin);
 
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 		
 		scanf("%d %d", &n, &m);
 
 		xs.clear();
 		out.clear();
 		long long res = 0;
 		for(int i = 0; i < m; i++)
 		{
 			int x, y, z;
 			scanf("%d %d %d", &x, &y, &z);
 			xs.insert(x);
 			xs.insert(y);
 			out[x].push_back(make_pair(y, z));
 			res = (res + cost(y - x) * z) % MOD;
 		}
 
 		long long res2 = 0;
 
 		int cnt = 0;
 		x2i.clear();
 
 		set<int>::iterator p = xs.begin(), q = xs.end();
 		while(p != q)
 		{
 			int x = *p++;
 			i2x[cnt] = x;
 			x2i[x] = cnt++;
 		}
 
 		memset(nxt, 0, sizeof nxt);
 		memset(cur, 0, sizeof cur);
 
 		for(int i = 0; i < cnt; i++)
 		{
 			int x = i2x[i];
 			for(int j = 0; j < out[x].size(); j++)
 			{
 				int to = x2i[out[x][j].first], num = out[x][j].second;
 				//printf("x = %d, to = %d, num = %d\n", x, out[x][i].first, num);
 				for(int k = i; k < to; k++) nxt[k] += num;
 			}
 		}
 
 		for(int i = 0; i < cnt; i++)
 		{
 			long long left = nxt[i];
 			//printf("x = %d, left = %d\n", i2x[i], left);
 			for(int j = 0; j < i; j++)
 			{
 				if (left >= cur[j])
 				{
 					left -= cur[j];
 					continue;
 				}
 				long long stop = (cur[j] - left) % MOD;
 				cur[j] = left;
 				left = 0;
 				//printf("%d -> %d (%d)\n", i2x[j], i2x[i], stop);
 				res2 = (res2 + cost(i2x[i] - i2x[j]) * stop) % MOD;
 			}
 			cur[i] = left;
 		}
 	
 		//printf("%d\n", res);
 		//printf("%d\n", res2);
 		printf("%d\n", (res - res2 + MOD) % MOD);
 	}
 	return 0;
 }