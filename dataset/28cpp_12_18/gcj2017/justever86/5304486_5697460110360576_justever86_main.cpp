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
 
 int a[55];
 int b[55][55];
 int c[55][55][2];
 
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
 		int n,p;
 		scanf("%d %d",&n,&p);
 		REP(i,n)
 		{
 			scanf("%d",&a[i]);
 		}
 		REP(i,n)
 		{
 			REP(j,p)
 			{
 				scanf("%d",&b[i][j]);
 			}
 		}
 		REP(i,n)
 		{
 			REP(j,p)
 			{
 				c[i][j][0] = (b[i][j] * 10 + a[i] * 11 - 1) / (a[i] * 11);
 				c[i][j][1] = b[i][j] * 10 / (a[i] * 9);
 			}
 		}
 
 		
 		int res = 0;
 		if (n == 1)
 		{
 			REP(j,p)
 			{
 				if (c[0][j][0] <= c[0][j][1])
 				{
 					res++;
 				}
 			}
 		}
 		else if (n == 2)
 		{
 			vector<int> v;
 			int total = 1;
 			REP(i,p)
 			{
 				v.push_back(i);
 				total *= i + 1;
 			}
 
 			while(total--)
 			{
 				int temp = 0;
 				REP(j,p)
 				{
 					int x1 = c[0][j][0];
 					int y1 = c[0][j][1];
 					int x2 = c[1][v[j]][0];
 					int y2 = c[1][v[j]][1];
 					if (x1 <= y1 && x2 <= y2)
 					{
 						if (x1 <= y2 && x2 <= y1)
 						{
 							temp++;
 						}
 					}
 				}
 				res = max(res,temp);
 				next_permutation(v.begin(),v.end());
 			}
 		}
 
 
 		printf("Case #%d: ",K);
 		printf("%d\n",res);
 	}
 
 
 	return 0;
 }
