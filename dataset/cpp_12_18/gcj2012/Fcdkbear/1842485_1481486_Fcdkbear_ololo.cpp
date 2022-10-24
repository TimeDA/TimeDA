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
 int l[10010];
 int d[10010];
 int max1[10010];
 int main()
 {
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	int t;
 	scanf("%d",&t);
 	FOR(it,1,t+1)
 	{
 		int n;
 		scanf("%d",&n);
 		FOR(i,0,n)
 			scanf("%d%d",&d[i],&l[i]);
 		int D;
 		cin>>D;
 		FOR(i,0,n)
 			max1[i]=0;
 		max1[0]=d[0];
 		FOR(i,1,n)
 			FOR(j,0,i)
 				if (max1[j]+d[j]>=d[i])
 				{
 					int v=MIN(l[i],d[i]-d[j]);
 					max1[i]=MAX(max1[i],v);
 				}
 		bool f=false;
 		FOR(i,0,n)
 			if (d[i]+max1[i]>=D)
 				f=true;
 		if (f)
 			printf("Case #%d: YES\n",it);
 		else
 			printf("Case #%d: NO\n",it);
 	}
 	return 0;
 }