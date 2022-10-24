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
 
 int a[1005];
 double pos[1005][2];
 
 int main()
 {
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 
 	int T;
 	scanf("%d",&T);
 	rep(CASE,1,T + 1)
 	{
 		int n,w,l;
 		vector<pair<double,int> > vec;
 		scanf("%d %d %d",&n,&w,&l);
 		REP(i,n)
 		{
 			scanf("%d",&a[i]);
 			vec.push_back(make_pair(a[i],i));
 		}
 		sort(vec.begin(),vec.end());
 		double x = 0.0;
 		double y = 0.0;
 		int r = vec[n - 1].first;
 		double f = r;
 		PER(i,n)
 		{
 			pos[vec[i].second][0] = x;
 			pos[vec[i].second][1] = y;
 			if (i != 0)
 			{
 				x += vec[i].first + vec[i - 1].first;
 			}
 			if (x > w)
 			{
 				x = 0.0;
 				y += f + vec[i - 1].first;
 				f = vec[i - 1].first;
 			}
 			if (y > l)
 			{
 				exit(1);
 			}
 		}
 		
 		printf("Case #%d:",CASE);
 		REP(i,n)
 		{
 			printf(" %.1lf %.1lf",pos[i][0],pos[i][1]);
 		}
 		printf("\n");
 	}
 
 	return 0;
 }
