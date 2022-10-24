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
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 
 	int CASE;
 	scanf("%d",&CASE);
 
 	for (int K = 1;K <= CASE;K++)
 	{
 		int n,m;
 		int a[2005][2];
 		clr(a);
 		vector<pair<int,int> > v;
 		priority_queue<pair<int,int> > u;
 
 		scanf("%d %d",&n,&m);
 		long long cnt1 = 0;
 		long long cnt2 = 0;
 		REP(i,m)
 		{
 			int x,y,z;
 			scanf("%d %d %d",&x,&y,&z);
 			v.push_back(make_pair(y,z));
 			v.push_back(make_pair(x,-z));
 			//u.push(make_pair(-x,z));
 			int t = y - x;
 			cnt1 += 1LL * ((long long)n + n - t + 1) * t / 2LL * z;
 		}
 
 		sort(v.begin(),v.end());
 
 		int j = 0;
 		REP(i,2 * m)
 		{
 			if (v[i].second > 0)
 			{
 				pair<int,int> p = u.top();
 				int k = v[i].second;
 				if (p.second >= k)
 				{
 					int t = v[i].first - p.first;
 					cnt2 += 1LL * ((long long)n + n - t + 1) * t / 2LL * k;
 					u.pop();
 					p.second -= k;
 					if (p.second != 0)
 					{
 						u.push(p);
 					}
 				}
 				else
 				{
 					k = p.second;
 					int t = v[i].first - p.first;
 					cnt2 += 1LL * ((long long)n + n - t + 1) * t / 2LL * k;
 					u.pop();
 					v[i].second -= k;
 					i--;
 				}
 			}
 			else
 			{
 				u.push(make_pair(v[i].first,-v[i].second));
 			}
 		}
 
 
 
 		printf("Case #%d: ",K);
 		printf("%I64d\n",cnt1 - cnt2);
 	}
 
 	return 0;
 }
 
