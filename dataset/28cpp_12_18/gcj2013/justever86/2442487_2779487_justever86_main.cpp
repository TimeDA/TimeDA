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
 int b[2005];
 int c[2005];
 int d[2005];
 int e[2005];
 
 int main()
 {
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 
 	int CASE;
 	scanf("%d",&CASE);
 
 	for (int K = 1;K <= CASE;K++)
 	{
 		int n;
 		scanf("%d",&n);
 
 		REP(i,n)
 		{
 			scanf("%d",&a[i]);
 		}
 		REP(i,n)
 		{
 			scanf("%d",&b[i]);
 		}
 
 		int temp = 1;
 		clr(c);
 		while (temp <= n)
 		{
 			int l = 0;
 			int r = 0;
 			REP(i,n)
 			{
 				if (c[i] != 0)
 				{
 					l = max(l,a[i]);
 				}
 				d[i] = l;
 			}
 
 			PER(i,n)
 			{
 				if (c[i] != 0)
 				{
 					r = max(r,b[i]);
 				}
 				e[i] = r;
 			}
 
 			REP(i,n)
 			{
 				if (d[i] + 1 == a[i] &&
 					e[i] + 1 == b[i])
 				{
 					c[i] = temp;
 					temp++;
 				}
 			}
 		}
 		
 
 		printf("Case #%d: ",K);
 		REP(i,n)
 		{
 			printf("%d",c[i]);
 			if (i != n - 1)
 			{
 				printf(" ");
 			}
 			else
 			{
 				printf("\n");
 			}
 		}
 	}
 
 	return 0;
 }
 
