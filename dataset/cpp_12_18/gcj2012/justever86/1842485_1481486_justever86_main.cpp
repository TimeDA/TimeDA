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
 
 int a[10005][2];
 int dp[10005];
 
 int main()
 {
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 
 	int T;
 	scanf("%d",&T);
 	rep(CASE,1,T + 1)
 	{
 		int n;
 		int d;
 		scanf("%d",&n);
 		REP(i,n)
 		{
 			scanf("%d %d",&a[i][0],&a[i][1]);
 		}
 		scanf("%d",&d);
 		clr(dp);
 		if (a[0][1] >= a[0][0])
 		{
 			dp[0] = a[0][0];
 		}
 		int flag = 0;
 		REP(i,n)
 		{
 			if (dp[i] + a[i][0] >= d)
 			{
 				flag = 1;
 				break;
 			}
 			rep(j,i + 1,n)
 			{
 				if (dp[i] + a[i][0] >= a[j][0])
 				{
 					dp[j] = max(dp[j],min(a[j][1],a[j][0] - a[i][0]));
 				}
 			}
 		}
 		printf("Case #%d: ",CASE);
 		if (flag)
 		{
 			puts("YES");
 		}
 		else
 		{
 			puts("NO");
 		}
 	}
 
 	return 0;
 }
