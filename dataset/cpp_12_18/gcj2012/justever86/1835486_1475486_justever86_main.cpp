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
 
 int a[1005][3];
 
 int cmp(const void* a,const void* b)
 {
 	int* x = (int*)a;
 	int* y = (int*)b;
 	if (x[1] != y[1])
 	{
 		return y[1] - x[1];
 	}
 	if (x[0] != y[0] && x[1] != 0)
 	{
 		return x[0] - y[0];
 	}
 	return x[2] - y[2];
 }
 
 int main()
 {
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 	
 	int T;
 	scanf("%d",&T);
 	for (int CASE = 1;CASE <= T;CASE++)
 	{
 		int n;
 		scanf("%d",&n);
 		REP(i,n)
 		{
 			scanf("%d",&a[i][0]);
 		}
 		REP(i,n)
 		{
 			scanf("%d",&a[i][1]);
 			a[i][2] = i;
 		}
 		qsort(a,n,sizeof(int)*3,cmp);
 		
 		printf("Case #%d:",CASE);
 		REP(i,n)
 		{
 			printf(" %d",a[i][2]);	
 		}
 		printf("\n");
 	}
 	
 
 
 	return 0;
 }
