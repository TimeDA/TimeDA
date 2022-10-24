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
 
 ll fun(vector<pair<ll,ll> > v,ll tt,ll m,ll f,ll n)
 {
 	ll temp = f;
 	ll i = 0;
 	ll j = -1;
 	while (i < n && j <= tt)
 	{
 		if (v[i].first < tt)
 		{
 			ll tr = v[i].first - j;
 			temp += tr * v[i].second;
 			j = v[i].first;
 			i++;
 		}
 		else
 		{
 			ll tr = tt - j;
 			temp += tr * v[i].second;
 			j = tt;
 			break;
 		}
 	}
 	ll ff = (m / temp) * (tt + 1);
 	m %= temp;
 	m -= f;
 	i = 0;
 	j = -1;
 	while (m > 0 && i < n)
 	{
 		if (v[i].first < j)
 		{
 			i++;
 		}
 		ll  tr = v[i].first - j;
 		if (m >= tr * v[i].second)
 		{
 			m -= tr * v[i].second;
 			ff += tr;
 			i++;
 		}
 		else
 		{
 			ff += m / v[i].second;
 			return ff;
 		}
 	}
 	return ff;
 }
 vector<pair<ll,ll> > v;
 int main()
 {
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 	
 	int T;
 	scanf("%d",&T);
 	for (int CASE = 1;CASE <= T;CASE++)
 	{
 		v.clear();
 		ll m,f,n;
 		scanf("%I64d %I64d %I64d",&m,&f,&n);
 		REP(i,n)
 		{
 			ll x,y;
 			scanf("%I64d %I64d",&x,&y);
 			v.push_back(make_pair(y,x));
 		}
 		sort(v.begin(),v.end());
 		
 		ll res = 0LL;
 		REP(i,n)
 		{
 			ll r1 = fun(v,v[i].first,m,f,n);
 			res = max(res,r1);
 		}
 
 		printf("Case #%d: %I64d\n",CASE,res);
 		cerr << CASE << endl;
 	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }