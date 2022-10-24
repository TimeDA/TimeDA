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
 
 int g(int* s, int l,int mid,int r,int flag)
 {
 	int t[1005];
 	int res = 0;
 	int x = l;
 	int y = mid + 1;
 	int z = l;
 	while (x <= mid || y <= r)
 	{
 		if (x > mid)
 		{
 			t[z] = s[y];
 			res += y - z;
 			y++;
 		}
 		else if (y > r)
 		{
 			t[z] = s[x];
 			x++;
 		}
 		else
 		{
 			if ((s[x] < s[y]) == flag)
 			{
 				t[z] = s[x];
 				x++;
 			}
 			else
 			{
 				t[z] = s[y];
 				res += y - z;
 				y++;
 			}
 		}
 		z++;
 	}
 	rep(i,l,r + 1)
 	{
 		s[i] = t[i];
 	}
 
 	return res;
 }
 
 int f(int* s,int l,int r,int flag)
 {
 	if (l == r)
 	{
 		return 0;
 	}
 
 	int ret = 0;
 	int mid = (l + r) / 2;
 	ret += f(s,l,mid,flag);
 	ret += f(s,mid + 1,r,flag);
 
 	ret += g(s,l,mid,r,flag);
 
 	return ret;
 }
 
 int check(vector<int> v)
 {
 	int n = v.size();
 
 	int state = 0;
 	REP(i,n - 1)
 	{
 		if (state == 0)
 		{
 			if (a[v[i]] > a[v[i + 1]])
 			{
 				state = 1;
 			}
 		}
 		else if (state == 1)
 		{
 			if (a[v[i]] < a[v[i + 1]])
 			{
 				return 0;
 			}
 		}
 	}
 
 	return 1;
 }
 
 int dst(vector<int> v)
 {
 	int n = v.size();
 
 	int res = 0;
 	REP(i,n)
 	{
 		rep(j,i + 1,n)
 		{
 			if (v[j] < v[i])
 			{
 				res++;
 			}
 		}
 	}
 	return res;
 }
 
 int dst2(int* v,int n)
 {
 	int res = 0;
 	REP(i,n)
 	{
 		rep(j,i + 1,n)
 		{
 			if (v[j] < v[i])
 			{
 				res++;
 			}
 		}
 	}
 	return res;
 }
 
 int solveS(int n)
 {
 	vector<int> v;
 	int cnt = 1;
 	REP(i,n)
 	{
 		v.push_back(i);
 		cnt *= i + 1;
 	}
 
 	int res = 0x7fffffff;
 	while (cnt--)
 	{
 		int x = check(v);
 		if (x)
 		{
 			res = min(res,dst(v));
 		}
 		next_permutation(v.begin(),v.end());
 	}
 
 	return res;
 }
 
 int main()
 {
 #if 1
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 #endif
 
 	int CASE;
 	scanf("%d",&CASE);
 
 	rep(K,1,CASE + 1)
 	{
 		int n;
 		scanf("%d",&n);
 
 		int maxi = 0;
 		vector<pair<int,int> > v;
 		REP(i,n)
 		{
 			scanf("%d",&a[i]);
 			if (a[i] > a[maxi])
 			{
 				maxi = i;
 			}
 			v.push_back(make_pair(a[i],i));
 		}
 		sort(v.begin(),v.end());
 		int res = 0x7fffffff;
 		REP(i,n)
 		{
 			int b[1005];
 			int l = 0;
 			int r = n - 1;
 
 			b[i] = maxi;
 
 			REP(j,n - 1)
 			{
 				int pos = v[j].second;
 				if (r == i)
 				{
 					b[l] = pos;
 					l++;
 				}
 				else if (l == i)
 				{
 					b[r] = pos;
 					r--;
 				}
 				else if (pos - l < r - pos)
 				{
 					b[l] = pos;
 					l++;
 				}
 				else if (pos - l > r - pos)
 				{
 					b[r] = pos;
 					r--;
 				}
 				else
 				{
 					b[r] = pos;
 					r--;
 				}
 			}
 
 			int temp = dst2(b,n);
 			res = min(temp,res);
 		}
 
 		//int ret = solveS(n);
 		//if (ret != res)
 		{
 			//printf("%d %d %d\n",K,ret,res);
 			//break;
 		}
 
 		printf("Case #%d: ",K);
 		printf("%d\n",res);
 	}
 
 	return 0;
 }
