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
 
 int main()
 {
 #if 1
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 #endif
 
 	int T;
 	scanf("%d",&T);
 
 	for (int K = 1;K <= T;K++)
 	{
 		int a[4][4],b[4][4];
 		int x,y;
 		scanf("%d",&x);
 		x--;
 		REP(i,4)
 		{
 			REP(j,4)
 			{
 				scanf("%d",&a[i][j]);
 			}
 		}
 		scanf("%d",&y);
 		y--;
 		REP(i,4)
 		{
 			REP(j,4)
 			{
 				scanf("%d",&b[i][j]);
 			}
 		}
 
 		int res = 0;
 		int resk = -1;
 
 		REP(i,4)
 		{
 			REP(j,4)
 			{
 				if (a[x][i] == b[y][j])
 				{
 					res++;
 					resk = a[x][i];
 					break;
 				}
 			}
 		}
 
 		printf("Case #%d: ",K);
 		if (res == 0)
 		{
 			printf("Volunteer cheated!\n");
 		}
 		else if (res == 1)
 		{
 			printf("%d\n",resk);
 		}
 		else
 		{
 			printf("Bad magician!\n");
 		}
 	}
 
 	return 0;
 }
