#include <string>
 #include <cstdio>
 #include <vector>
 #include <set>
 
 using namespace std;
 
 char s[105];
 vector<string> vs;
 int n, m;
 int a[1005];
 int sum[1005];
 int ret1, ret2;
 
 void backtr(int k)
 {
 	if (k == m)
 	{
 		for (int i = 0; i < n; ++i)
 			if (sum[i] == 0) return;
 
 		vector< set<string> > vss(n);
 		for (int i = 0; i < m; ++i)
 		{
 			for (int j = 0; j <= vs[i].size(); ++j)
 			{
 				vss[ a[i] ].insert( vs[i].substr(0, j) );
 			}
 		}
 
 		int tmp = 0;
 		for (int i = 0; i < n; ++i)
 		{
 			tmp += vss[i].size();
 		}
 
 		if (ret1 < tmp) 
 		{
 			ret1 = tmp;
 			ret2 = 0;
 		}
 		if (ret1 == tmp) ret2++;
 		return;
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		a[k] = i;
 		sum[i]++;
 		backtr(k + 1);
 		sum[i]--;
 	}
 }
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		ret1 = 0;
 		ret2 = 0;
 
 		scanf("%d%d", &m, &n);
 		vs.resize(m);
 		for (int i = 0; i < m; ++i)
 		{
 			scanf("%s", s);
 			vs[i] = s;
 		}
 		backtr(0);
 		printf("Case #%d: %d %d\n", cn, ret1, ret2);
 	}
 }
 
