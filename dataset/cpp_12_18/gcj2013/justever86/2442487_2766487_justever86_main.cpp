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
 
 int cnt_bit(long long x)
 {
 	int res = 0;
 	while (x)
 	{
 		x = x & (x - 1);
 		res ++;
 	}
 
 	return res;
 }
 
 long long f1(long long x,long long y)
 {
 	if (y == (1LL << x))
 	{
 		return y - 1;
 	}
 
 	y = (1LL << x) - y;
 
 	long long t = 1LL;
 	while (t <= y)
 	{
 		t <<= 1LL;
 	}
 	t >>= 1LL;
 	t -= 1LL;
 	long long t2 = cnt_bit(t);
 	long long t3 = (1LL << ((x - (t2 + 1LL)) + 1LL)) - 2LL;
 
 
 	return t3;
 }
 
 long long f2(long long x,long long y)
 {
 	if (y == (1LL << x))
 	{
 		return y - 1;
 	}
 
 	long long t = 1LL;
 	while (t <= y)
 	{
 		t <<= 1LL;
 	}
 	t >>= 1LL;
 	t -= 1LL;
 	long long t2 = cnt_bit(t);
 	long long t3 = (1LL << (x - t2));
 	t3 = (1LL << x) - t3;
 
 	return t3;
 }
 int main()
 {
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 
 	int CASE;
 	scanf("%d",&CASE);
 
 	for (int K = 1;K <= CASE;K++)
 	{
 		long long x,y;
 		scanf("%I64d %I64d",&x,&y);
 
 		long long rx = 0,ry = 0;
 		long long temp = 1;
 		long long mask = (1LL << x) - 1;
 
 		long long cnt = 1;
 		
 		rx = f1(x,y);
 
 		ry = f2(x,y);
 
 
 		printf("Case #%d: ",K);
 		printf("%I64d %I64d\n",rx,ry);
 	}
 
 	return 0;
 }
 
