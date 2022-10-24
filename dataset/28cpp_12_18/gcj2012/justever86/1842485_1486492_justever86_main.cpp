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
 
 int a[2005];
 int res[2005];
 
 int main()
 {
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 
 	int T;
 	scanf("%d",&T);
 	rep(CASE,1,T + 1)
 	{
 		int n;
 		scanf("%d",&n);
 		REP(i,n-1)
 		{
 			scanf("%d",&a[i]);
 		}
 		int flag = 1;
 		REP(i,n - 1)
 		{		
 			for (int j = i + 1;j < a[i] - 1;j++)
 			{
 				if (a[j] > a[i])
 				{
 					flag = 0;
 					break;
 				}
 			}
 			if (!flag)
 			{
 				break;
 			}
 		}
 		printf("Case #%d: ",CASE);
 		if (flag)
 		{
 			REP(i,n)
 			{
 				res[i] = (i + 1) * 100;
 			}
 			REP(i,n - 1)
 			{
 				for (int j = i + 1;j < a[i] - 1;j++)
 				{
 					res[j] -= (a[i] - j - 1);
 				}
 			}
 			REP(i,n)
 			{
 				if (i != 0)
 				{
 					printf(" ");
 				}
 				printf("%d",res[i]);
 			}
 			printf("\n");
 		}
 		else
 		{
 			printf("Impossible\n");
 		}
 		
 	}
 
 	return 0;
 }
