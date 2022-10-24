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
 
 int n;
 double vx,rx;
 double v[105];
 double r[105];
 
 double f1()
 {
 	if (n == 1)
 	{
 		if (!(rx >= r[0] -eps && rx <= r[0] + eps))
 		{
 			return -1;
 		}
 		else
 		{
 			return vx / v[0];
 		}
 	}
 
 	if (n == 2)
 	{
 		if (r[0] >= rx - eps && r[0] <= rx + eps &&
 			r[1] >= rx - eps && r[1] <= rx + eps)
 		{
 			return vx / (v[0] + v[1]);
 		}
 		else if (r[0] >= rx - eps && r[0] <= rx + eps)
 		{
 			return vx / v[0];
 		}
 		else if (r[1] >= rx - eps && r[1] <= rx + eps)
 		{
 			return vx / v[1];
 		}
 
 		if (r[0] < rx - eps && r[1] < rx - eps)
 		{
 			return -1;
 		}
 		else if (r[0] > rx + eps && r[1] > rx + eps)
 		{
 			return -1;
 		}
 		double p0 = r[0];
 		double p1 = r[1];
 
 		double t0 = rx * vx - r[1] * vx;
 		double t1 = t0 / (p0 - p1);
 		double t2 = t1 / v[0];
 		double t3 = (vx - t1) / v[1];
 		return max(t2,t3);
 	}
 
 	return -1;
 }
 
 double f2()
 {
 	if (n == 1)
 	{
 		if (rx != r[0])
 		{
 			return -1;
 		}
 		else
 		{
 			return vx / v[0];
 		}
 	}
 
 	int temp = 0;
 	REP(i,n)
 	{
 		if (r[i] < rx)
 		{
 			temp |= 1;
 		}
 		else if (r[i] > rx)
 		{
 			temp |= 2;
 		}
 		else
 		{
 			temp = 0;
 			break;
 		}
 	}
 	if (temp == 3)
 	{
 		return -1;
 	}
 
 	return -1;
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
 		scanf("%d %lf %lf",&n,&vx,&rx);
 
 		REP(i,n)
 		{
 			scanf("%lf %lf",&v[i],&r[i]);
 		}
 
 		double res1 = f1();
 		//double res2 = f2();
 
 		double res = res1;
 		
 		printf("Case #%d: ",K);
 		if (res < 0)
 		{
 			printf("IMPOSSIBLE\n");
 		}
 		else
 		{
 			printf("%.6lf\n",res1);
 		}
 		
 	}
 
 
 	return 0;
 }
