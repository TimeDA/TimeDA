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
 		double c,f,x;
 		scanf("%lf %lf %lf",&c,&f,&x);
 
 		double res = x / 2.0;
 		double sum = 0;
 		double ver = 2.0;
 		for (int i = 1;;i++)
 		{
 			sum += c / ver;
 			ver += f;
 			double temp = sum + x / ver;
 			if (temp > res)
 			{
 				break;
 			}
 			else
 			{
 				res = temp;
 			}
 		}
 
 		printf("Case #%d: ",K);
 		printf("%.7lf\n",res);
 	}
 
 	return 0;
 }
