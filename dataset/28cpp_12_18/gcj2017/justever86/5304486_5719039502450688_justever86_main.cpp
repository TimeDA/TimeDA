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
 #include <cstring>
 #include <ctime>
 #include <queue>
 
 using namespace std;
 
 #define	sqr(a)		((a)*(a))
 #define	rep(i,a,b)	for(int i=(a);i<(int)(b);i++)
 #define	per(i,a,b)	for(int i=((a)-1);i>=(int)(b);i--)
 #define	PER(i,n)	per(i,n,0)
 #define	REP(i,n)	rep(i,0,n)
 #define	clr(a)		memset((a),0,sizeof (a))
 #define	SZ(a)		((int)((a).size()))
 #define	ALL(x)		x.begin(),x.end()
 #define	mabs(a)		((a)>0?(a):(-(a)))
 #define	inf			(0x7fffffff)
 #define	eps			1e-6
 
 #define	MAXN		0x3fffffff
 #define MODN		(1000000007)
 
 typedef long long ll;
 
 #define TEST_LOCAL 1
 
 int dp[105][105][105][105];
 int ap[105][105][105][105];
 
 int hh1,aa1,hh2,aa2,b,d;
 
 int dfs(int h1,int a1,int h2,int a2)
 {
 	if(a1 >= h2)
 	{
 		a1 = h2;
 		//return 1;
 	}
 	if (h2 <= 0)
 	{
 		return 0;
 	}
 	if (h1 <= 0)
 	{
 		return MAXN;
 	}
 	if (a2 <= 0)
 	{
 		a2 = 0;
 	}
 	if (ap[h1][a1][h2][a2] == 1)
 	{
 		return MAXN;
 	}
 	if (dp[h1][a1][h2][a2] > 0)
 	{
 		//printf("%d %d %d %d %d\n",h1,a1,h2,a2,dp[h1][a1][h2][a2]);
 		return dp[h1][a1][h2][a2];
 	}
 	int res = MAXN;
 	//printf("%d %d %d %d\n",h1,a1,h2,a2);
 	ap[h1][a1][h2][a2] = 1;
 
 	res = min(res,dfs(h1 - a2,a1,h2 - a1,a2) + 1);
 	//if (a1 < h2)
 	{
 		if (b > 0)
 		{
 			res = min(res,dfs(h1 - a2,a1 + b,h2,a2) + 1);
 		}
 		res = min(res,dfs(hh1 - a2,a1,h2,a2) + 1);
 		//if (a2 > 0 && d > 0)
 		{
 			if (a2 >= d)
 			{
 				res = min(res,dfs(h1 - a2 + d,a1,h2,a2 - d) + 1);
 			}
 			else
 			{
 				res = min(res,dfs(h1,a1,h2,a2 - d) + 1);
 			}
 		}
 	}
 	
 	ap[h1][a1][h2][a2] = 0;
 
 	dp[h1][a1][h2][a2] = res;
 	
 	return res;
 }
 
 int main()
 {
 	freopen("data.in","r",stdin);
 #if TEST_LOCAL
 	freopen("data.out","w",stdout);
 #endif
 
 	int T;
 	scanf("%d",&T);
 
 	for (int K = 1;K <= T;K++)
 	{
 		
 		scanf("%d %d %d %d %d %d",&hh1,&aa1,&hh2,&aa2,&b,&d);
 
 		memset(dp,-1,sizeof(dp));
 		memset(ap,0,sizeof(ap));
 
 		int res = dfs(hh1,aa1,hh2,aa2);
 
 		printf("Case #%d: ",K);
 		if (res < MAXN)
 		{
 			printf("%d\n",res);
 		}
 		else
 		{
 			printf("IMPOSSIBLE\n");
 		}
 	}
 
 
 	return 0;
 }
