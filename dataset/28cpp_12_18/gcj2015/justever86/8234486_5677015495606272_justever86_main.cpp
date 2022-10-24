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
 
 #define	MAXN		
 #define MODN		(1000000007)
 
 typedef long long ll;
 
 #define TEST_LOCAL 1
 
 long long dp[105][2][3];
 
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
 		int n,m;
 		scanf("%d %d",&n,&m);
 
 		clr(dp);
 		dp[1][1][0] += 1;
 		dp[2][0][0] += 1;
 		if (m % 3 == 0)
 		{
 			dp[2][1][1] += 1;
 		}
 		if (m % 6 == 0)
 		{
 			dp[2][1][2] += 2;
 		}
 		
 		REP(i,n)
 		{
 			if (dp[i][0][0] != 0)
 			{
 				dp[i + 1][1][0] += dp[i][0][0];
 				dp[i + 1][1][0] %= MODN;
 				if (m % 3 == 0)
 				{
 					dp[i + 2][1][1] += dp[i][0][0];
 					dp[i + 2][1][1] %= MODN;
 				}
 				if (m % 6 == 0)
 				{
 					dp[i + 2][1][2] += dp[i][0][0] * 2;
 					dp[i + 2][1][2] %= MODN;
 				}
 			}
 			if (dp[i][1][0] != 0)
 			{
 				dp[i + 2][0][0] += dp[i][1][0];
 				dp[i + 2][0][0] %= MODN;
 			}
 			if (dp[i][0][1] != 0)
 			{
 				dp[i + 1][1][1] += dp[i][0][1];
 				dp[i + 1][1][1] %= MODN;
 				if (m % 3 == 0)
 				{
 					dp[i + 2][1][1] += dp[i][0][1] * 3;
 					dp[i + 2][1][1] %= MODN;
 				}
 				if (m % 6 == 0)
 				{
 					dp[i + 2][1][2] += dp[i][0][1] * 6;
 					dp[i + 2][1][2] %= MODN;
 				}
 			}
 			if (dp[i][1][1] != 0)
 			{
 				dp[i + 2][0][1] += dp[i][1][1];
 				dp[i + 2][0][1] %= MODN;
 			}
 			if (dp[i][0][2] != 0)
 			{
 				dp[i + 1][1][2] += dp[i][0][2];
 				dp[i + 1][1][2] %= MODN;
 				if (m % 3 == 0)
 				{
 					dp[i + 2][1][2] += dp[i][0][2] * 3;
 					dp[i + 2][1][2] %= MODN;
 				}
 				if (m % 6 == 0)
 				{
 					dp[i + 2][1][2] += dp[i][0][2] * 12;
 					dp[i + 2][1][2] %= MODN;
 				}
 			}
 			if (dp[i][1][2] != 0)
 			{
 				dp[i + 2][0][2] += dp[i][1][2];
 				dp[i + 2][0][2] %= MODN;
 			}
 		}
 
 		long long res = 0;
 		REP(i,2)
 		{
 			REP(j,3)
 			{
 				res += dp[n][i][j];
 				res %= MODN;
 			}
 		}
 		
 		printf("Case #%d: ",K);
 		printf("%d\n",res);
 	}
 
 
 	return 0;
 }
