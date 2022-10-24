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
 
 string g(int n,string s,int x,int y,int z)
 {
 	string t = s;
 	for (int i = 0;i < n;i++)
 	{
 		int l = t.length();
 		string r = "";
 		for (int j = 0;j < l;j++)
 		{
 			if (t[j] == 'P')
 			{
 				r += "PR";
 			}
 			else if (t[j] == 'R')
 			{
 				r += "RS";
 			}
 			else if (t[j] == 'S')
 			{
 				r += "PS";
 			}
 		}
 		t = r;
 	}
 
 	int tx = 0;
 	int ty = 0;
 	int tz = 0;
 	for (int i = 0;i < t.length();i++)
 	{
 		if (t[i] == 'P')
 		{
 			ty++;
 		}
 		else if (t[i] == 'R')
 		{
 			tx++;
 		}
 		else if (t[i] == 'S')
 		{
 			tz++;
 		}
 	}
 	if (tx == x && ty == y && tz == z)
 	{
 		int m = t.length();
 		int step = 1;
 		for (int i = 0;i < n;i++)
 		{
 			for (int j = 0;j < m - step;j += step * 2)
 			{
 				string aa = t.substr(j,step);
 				string bb = t.substr(j + step,step);
 				if (aa.compare(bb) > 0)
 				{
 					for (int k = 0;k < step;k++)
 					{
 						swap(t[j + k],t[j + step + k]);
 					}
 				}
 			}
 
 			step *= 2;
 		}
 
 		return t;
 	}
 	else
 	{
 		return "";
 	}
 }
 
 string f(int n,int x,int y,int z)
 {
 	string rx = g(n,"R",x,y,z);
 	string ry = g(n,"P",x,y,z);
 	string rz = g(n,"S",x,y,z);
 	string res = "Z";
 	if (rx.length() != 0)
 	{
 		res = rx;
 	}
 	if (ry.length() != 0)
 	{
 		res = min(ry,res);
 	}
 	if (rz.length() != 0)
 	{
 		res = min(rz,res);
 	}
 	if (res == "Z")
 	{
 		res = "IMPOSSIBLE";
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
 		int n,a,b,c;
 		scanf("%d %d %d %d",&n,&a,&b,&c);
 
 		string res = f(n,a,b,c);
 
 		printf("Case #%d: ",K);
 		printf("%s\n",res.c_str());
 	}
 
 
 	return 0;
 }
