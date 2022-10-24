#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <queue>
 #include <algorithm>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <memory.h>
 #include <ctime>
 
 using namespace std;
  
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.14159265358979
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 
 LL gw (LL num, int n)
 {
 	LL w=0;
 	LL add=(1ll<<n)/2;
 	LL st=2;
 	while (add)
 	{
 		if (num>=st-1)
 		{
 			w+=add;
 			add>>=1;
 			st+=st;
 		}
 		else
 			break;
 	}
 	return w+1;
 }
 LL gb(LL num, int n)
 {
 	LL b=(1ll<<n);
 	LL add=(1ll<<n)/2;
 	LL st=2;
 	LL c=(1ll<<n);
 	while (b>1)
 	{
 		if (st-1<=c-num-1)
 		{
 			add>>=1;
 			st+=st;
 			b/=2;
 		}
 		else
 			break;
 	}
 	return b;
 }
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	double beg=clock();
 #else
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 #endif
 
 	int t;
 	scanf("%d",&t);
 	FOR(itt,1,t+1)
 	{
 		//printf("ok\n");
 		LL n,p;
 		cin>>n>>p;
 		LL l=0;
 		LL r=(1ll<<n)-1;
 		LL res1=0,res2=0;
 		while (l<=r)
 		{
 			LL m=(l+r)/2;
 			LL val=gw(m,n);
 			if (val<=p)
 			{
 				res1=m;
 				l=m+1;
 			}
 			else
 				r=m-1;
 		}
 		l=0;
 		r=(1ll<<n)-1;
 		while (l<=r)
 		{
 			LL m=(l+r)/2;
 			LL val=gb(m,n);
 			if (val<=p)
 			{
 				res2=m;
 				l=m+1;
 			}
 			else
 				r=m-1;
 		}
 		printf("Case #%d: %I64d %I64d\n",itt,res1,res2);
 	}
 
 #ifdef Fcdkbear
 	double end=clock();
 	fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
 #endif
 	return 0;
 }