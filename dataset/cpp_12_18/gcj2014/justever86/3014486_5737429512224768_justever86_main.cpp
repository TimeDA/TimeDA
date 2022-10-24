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
 
 int a[10005];
 int b[10005];
 
 int main()
 {
 #if 1
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 #endif
 
 	int CASE;
 	scanf("%d",&CASE);
 
 	rep(K,1,CASE + 1)
 	{
 		int n,m;
 		scanf("%d %d",&n,&m);
 		REP(i,n)
 		{
 			scanf("%d",&a[i]);
 			b[i] = 0;
 		}
 
 		sort(a,a + n);
 
 		int res = 0;
 		PER(i,n)
 		{
 			if (b[i] == 0)
 			{
 				b[i] = 1;
 				PER(j,i)
 				{
 					if (b[j] == 0)
 					{
 						if (a[i] + a[j] <= m)
 						{
 							b[j] = 1;
 							break;
 						}
 					}
 				}
 				res++;
 			}	
 		}
 
 		printf("Case #%d: ",K);
 		printf("%d\n",res);
 	}
 
 	return 0;
 }
