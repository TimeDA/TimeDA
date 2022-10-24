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
 
 double a[1005],b[1005];
 int flag[1005];
 
 int main()
 {
 #if 1
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 #endif
 
 	int T;
 	scanf("%d",&T);
 
 	for (int K = 1;K <= T;K++)
 	{
 		int n;
 		scanf("%d",&n);
 
 		REP(i,n)
 		{
 			scanf("%lf",&a[i]);
 		}
 		REP(i,n)
 		{
 			scanf("%lf",&b[i]);
 		}
 
 		sort(a,a + n);
 		sort(b,b + n);
 
 		int res1 = 0;
 		clr(flag);
 		REP(i,n)
 		{
 			int temp = 0;
 			int ff = 1;
 			rep(j,i,n)
 			{
 				if (a[j] < b[j - i])
 				{
 					ff = 0;
 					break;
 				}
 			}
 
 			if (ff == 1)
 			{
 				res1 = max(res1,n - i);
 			}
 		}
 
 		int res2 = 0;
 		clr(flag);
 		REP(i,n)
 		{
 			int ff = 1;
 			REP(j,n)
 			{
 				if (flag[j] == 0)
 				{
 					if (b[j] > a[i])
 					{
 						
 						flag[j] = 1;
 						ff = 0;
 						break;
 					}
 				}
 			}
 
 			if (ff)
 			{
 				REP(j,n)
 				{
 					if (flag[j] == 0)
 					{
 						res2++;
 						flag[j] = 1;
 						break;
 					}
 				}
 			}
 		}
 		
 
 		printf("Case #%d: ",K);
 		printf("%d %d\n",res1,res2);
 	}
 
 	return 0;
 }
