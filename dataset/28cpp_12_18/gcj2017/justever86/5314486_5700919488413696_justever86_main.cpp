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
 		int a[5] = {0,0,0,0,0};
 		int n,p;
 		scanf("%d %d",&n,&p);
 		REP(i,n)
 		{
 			int t;
 			scanf("%d",&t);
 			a[t % p]++;
 		}
 		int res = 0;
 		if (p == 2)
 		{
 			res = a[1] / 2;
 		}
 		else if (p == 3)
 		{
 			res += min(a[1],a[2]);
 			int x = abs(a[1] - a[2]);
 			res += x / 3 * 2;
 			x %= 3;
 			if (x == 2)
 			{
 				res++;
 			}
 		}
 		else if (p == 4)
 		{
 			res += a[2] / 2;
 			a[2] %= 2;
 			int x = min(a[1],a[3]);
 			res += x;
 			a[1] -= x;
 			a[3] -= x;
 			int y = a[1] + a[3];
 			if (a[2] == 1)
 			{
 				if (y >= 2)
 				{
 					res += 2;
 					y -= 2;
 
 					res += y / 4 * 3;
 					y %= 4;
 					if (y > 1)
 					{
 						res += y - 1;
 					}
 				}
 				else
 				{
 					res += y;
 				}
 			}
 		}
 
 		printf("Case #%d: ",K);
 		printf("%d\n",n - res);
 		cerr<<"Case #"<<K<<" Done"<<endl;
 	}
 
 	return 0;
 }
