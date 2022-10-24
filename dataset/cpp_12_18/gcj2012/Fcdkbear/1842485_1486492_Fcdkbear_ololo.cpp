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
 #include <ctime>
 #include <memory.h>
 
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
 using namespace std;
 int x[2010];
 vector<int> h;
 int n;
 int calc(int i)
 {
 	int dx=x[i]-i;
 	int dy=h[x[i]]-h[i];
 	FOR(j,i+1,x[i])
 	{
 		int ndx=j-i;
 		int ndy=h[j]-h[i];
 		double c=dy*ndx-dx*ndy;
 		double z=dx*ndx;
 		if (c/z<=0)
 			return 1;
 	}
 	FOR(j,x[i]+1,n)
 	{
 		int ndx=j-i;
 		int ndy=h[j]-h[i];
 		double c=dy*ndx-dx*ndy;
 		double z=dx*ndx;
 		if (c/z<0)
 			return 1;
 	}
 	return 0;
 }
 int docalc()
 {
 	int res=0;
 	FOR(i,0,n-1)
 		res+=calc(i);
 	return res;
 }
 int main()
 {
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	srand(time(NULL));
 	int t;
 	scanf("%d",&t);
 	FOR(it,1,t+1)
 	{
 		scanf("%d",&n);
 		FOR(i,0,n-1)
 		{
 			scanf("%d",&x[i]);
 			x[i]--;
 		}
 		double T=300;
 		h.resize(n);
 		int cur=docalc();
 		FOR(itt,0,10000)
 		{
 			int p=rand()%n;
 			int v=rand();
 			int last=h[p];
 			h[p]=v;
 			int q=docalc();
 			if (q>=cur)
 			{
 				double prob=exp(-(double)(q-cur)/(double)T);
 				int r=rand()%10000;
 				if (r<=prob*10000)
 					cur=q;
 				else
 					h[p]=last;
 			}
 			else
 				cur=q;
 			T*=0.95;
 		}
 		printf("Case #%d:",it);
 		if (cur)
 			printf(" Impossible\n");
 		else
 		{
 			FOR(i,0,h.size())
 				printf(" %d",h[i]);
 			printf("\n");
 		}
 		fprintf(stderr,"Case #%d done\n",it);
 	}
 	return 0;
 }