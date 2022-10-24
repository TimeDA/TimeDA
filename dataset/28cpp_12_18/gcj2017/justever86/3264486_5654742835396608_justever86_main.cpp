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
 		long long n,m;
 		scanf("%I64d %I64d",&n,&m);
 
 		priority_queue<long long> q;
 		map<long long,long long> mp;
 		q.push(n);
 		mp[n] = 1;
 
 		long long k = 0;
 		long long res = -1;
 		while (k < m)
 		{
 			long long d = q.top();
 			q.pop();
 			long long c = mp[d];
 			k += c;
 			if (k >= m)
 			{
 				res = d;
 				break;
 			}
 			else
 			{
 				if (d % 2 == 1)
 				{
 					long long x = (d - 1) / 2;
 					long long y = c * 2;
 					if (mp[x] == 0)
 					{
 						q.push(x);
 					}
 					mp[x] += y;
 				}
 				else
 				{
 					long long x = d / 2;
 					long long y = c;
 					if (mp[x] == 0)
 					{
 						q.push(x);
 					}
 					mp[x] += y;
 
 					x = (d - 1) / 2;
 					if (mp[x] == 0)
 					{
 						q.push(x);
 					}
 					mp[x] += y;
 				}
 			}
 		}
 
 
 		printf("Case #%d: ",K);
 		printf("%I64d %I64d\n",res / 2,(res - 1) / 2);
 	}
 
 
 	return 0;
 }
