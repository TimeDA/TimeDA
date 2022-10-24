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
 char s[15005];
 int tt[3000];
 
 vector<string> f(char* x)
 {
 	string t = "";
 	vector<string> ret;
 	while (true)
 	{
 		if (*x == ' ')
 		{
 			ret.push_back(t);
 			t = "";
 		}
 		else if (*x == '\0')
 		{
 			ret.push_back(t);
 			break;
 		}
 		else
 		{
 			t += *x;
 		}
 		x++;
 	}
 
 	return ret;
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
 		clr(tt);
 		int n;
 		scanf("%d",&n);
 		gets(s); //
 		vector<string> v;
 		map<string,int> mp;
 		int N = 0;
 		int len;
 		gets(s);
 		v = f(s);
 		len = v.size();
 		REP(i,len)
 		{
 			if (mp.find(v[i]) == mp.end())
 			{
 				mp[v[i]] = N;
 				N++;
 			}
 			tt[mp[v[i]]] |= 1;
 		}
 
 		gets(s);
 		v = f(s);
 		len = v.size();
 		REP(i,len)
 		{
 			if (mp.find(v[i]) == mp.end())
 			{
 				mp[v[i]] = N;
 				N++;
 			}
 			tt[mp[v[i]]] |= 2;
 		}
 
 		REP(i,n - 2)
 		{
 			gets(s);
 			v = f(s);
 			int l = v.size();
 			REP(j,l)
 			{
 				if (mp.find(v[j]) == mp.end())
 				{
 					mp[v[j]] = N;
 					N++;
 				}
 				tt[mp[v[j]]] |= 4 << i;
 			}
 		}
 		int res = 0x7fffffff;
 		for (int i = 0;i < (1 << (n - 2));i++)
 		{
 			int temp = 0;
 			REP(j,N)
 			{
 				int x = tt[j];
 				int y = (i << 2) | 1;
 				int z = ((1 << (n)) - 1) & (~y);
 				if ((x & y) != 0 && (x & z) != 0)
 				{
 					temp++;
 				}
 			}
 
 			res = min(res,temp);
 		}
 		if (N > 3000)
 		{
 			//printf("error\n");
 		}
 
 		printf("Case #%d: ",K);
 		printf("%d\n",res);
 	}
 
 
 	return 0;
 }
