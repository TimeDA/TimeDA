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
 
 int b[25];
 int a[25];
 
 int d[25];
 
 void init(int k,int n)
 {
 	REP(i,n)
 	{
 		if (i != k)
 		{
 			d[i] = i;
 		}
 		else
 		{
 			d[i] = -1;
 		}
 	}
 }
 
 int p(int x)
 {
 	if (d[x] == -1)
 	{
 		return -1;
 	}
 	int temp = x;
 	while (temp != d[temp])
 	{
 		temp = d[temp];
 	}
 	d[x] = temp;
 	return temp;
 }
 
 void u(int x,int y)
 {
 	int xx = p(x);
 	int yy = p(y);
 	if (xx != yy)
 	{
 		d[yy] = xx;
 	}
 }
 
 int cb(int x)
 {
 	int res = 0;
 	while (x)
 	{
 		res += x % 2;
 		x /= 2;
 	}
 
 	return res;
 }
 
 bool check(int k,int n)
 {
 	init(k,n);
 
 	REP(i,n)
 	{
 		REP(j,n)
 		{
 			if (d[i] != -1 && d[j] != -1)
 			{
 				if (a[i] & a[j])
 				{
 					u(i,j);
 				}
 			}
 		}
 	}
 
 	vector<pair<int,int> > v;
 	REP(i,n)
 	{
 		if (d[i] != -1)
 		{
 			int temp = 0;
 			int cnt = 0;
 			int x = p(i);
 			REP(j,n)
 			{
 				if (d[j] != -1 && p(j) == x)
 				{
 					temp |= a[j];
 					d[j] = -1;
 					cnt++;
 				}
 			}
 			v.push_back(make_pair(temp,cnt));
 		}
 	}
 
 	int vc = v.size();
 	int tc = 0;
 	int cc = 0;
 	REP(i,vc)
 	{
 		int x = v[i].first;
 		int y = v[i].second;
 		tc |= x & a[k];
 		cc += y;
 	}
 	if (cb(a[k]) == 0)
 	{
 		return false;
 	}
 	if (tc == a[k] && cc >= cb(tc))
 	{
 		return false;
 	}
 	return true;
 }
 
 bool dfs(int idx,vector<int> v,int n,int t)
 {
 	if (idx == n)
 	{
 		return true;
 	}
 	int x = v[idx];
 	bool ret = false;
 	REP(i,n)
 	{
 		if (!(t & (1 << i)))
 		{
 			if (a[x] & (1 << i))
 			{
 				if (!dfs(idx + 1,v,n,t | (1 << i)))
 				{
 					return false;
 				}
 				ret = true;
 			}
 		}
 	}
 	return ret;
 }
 
 bool check2(int n)
 {
 	vector<int> v;
 	int c = 1;
 	REP(i,n)
 	{
 		v.push_back(i);
 		c *= i + 1;
 	}
 
 	while (c--)
 	{
 		bool ret = dfs(0,v,n,0);
 
 		if (!ret)
 		{
 			return false;
 		}
 
 		next_permutation(v.begin(),v.end());
 	}
 	return true;
 }
 
 int f(int n)
 {
 	int mask = 1 << (n * n);
 	int lmask= (1 << n) - 1;
 	int res = n * n;
 	REP(i,mask)
 	{
 		int s = i;
 		int flag = 1;
 		REP(j,n)
 		{
 			int t = s & lmask;
 			if (t & b[j])
 			{
 				flag = 0;
 				break;
 			}
 			a[j] = b[j] | t;
 			s >>= n;
 		}
 		if (flag)
 		{
 // 			REP(j,n)
 // 			{
 // 				if (!check(j,n))
 // 				{
 // 					flag = 0;
 // 					break;
 // 				}
 // 			}
 			if (!check2(n))
 			{
 				flag = 0;
 			}
 		}
 		if (flag)
 		{
 			res = min(res,cb(i));
 		}
 	}
 	return res;
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
 		int n;
 		scanf("%d",&n);
 		REP(i,n)
 		{
 			char s[26];
 			scanf("%s",s);
 			int t = 0;
 			REP(j,n)
 			{
 				t *= 2;
 				t += s[j] - '0';
 			}
 			b[i] = t;
 		}
 
 		int res = f(n);
 
 		printf("Case #%d: ",K);
 		printf("%d\n",res);
 	}
 
 
 	return 0;
 }
