#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <queue>
 #include <deque>
 #include <stack>
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
 int was[3010][3010][4];
 const int N=1000;
 char s[32][32];
 set <pnt > q;
 double eps=1e-9;
 int gcd(int a, int b)
 {
 	if (b==0)
 		return a;
 	return (gcd(b,a%b));
 }
 int main()
 {
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	int t;
 	scanf("%d",&t);
 	int cur=1;
 	FOR(test,1,t+1)
 	{
 		q.clear();
 		int n,m,d;
 		scanf("%d%d%d",&n,&m,&d);
 		FOR(i,0,n)
 			scanf("%s",&s[i]);
 		double x=0,y=0;
 		FOR(i,0,n)
 			FOR(j,0,m)
 				if (s[i][j]=='X')
 				{
 					x=(i-1)+0.5;
 					y=(j-1)+0.5;
 				}
 		int res=0;
 		int cnt=0;
 		for (double a=0; a<359; a+=0.01)
 		{
 			double alpha=2*PI*a/360.0;
 			cnt++;
 			double dx=cos(alpha);
 			double dy=sin(alpha);
 			double k;
 			if (ABS(dx)>ABS(dy))
 				k=0.1/dx;
 			else
 				k=0.1/dy;
 			k=ABS(k);
 			dx*=k;
 			dy*=k;
 			double toadd=sqrt(dx*dx+dy*dy);
 			double sum=0;
 			double curx=x,cury=y;
 			while (1)
 			{
 				sum+=toadd;
 				curx+=dx;
 				cury+=dy;
 				if (sum>d)
 					break;
 				if ((ABS(x-curx)<=eps) && (ABS(y-cury)<=eps))
 				{
 					a+=1.23;
 					res++;
 					break;
 				}
 				if ((curx-eps<=0) || (curx+eps>=n-2))
 					dx=-dx;
 				if ((cury-eps<=0) || (cury+eps>=m-2))
 					dy=-dy;
 			}
 		}
 		printf("Case #%d: %d\n",test,res);
 	}
 	return 0;
 }
