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
 
 char mp[105][105];
 
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
 		int n,m;
 		scanf("%d %d",&n,&m);
 
 		REP(i,n)
 		{
 			scanf("%s",mp[i]);
 		}
 
 		int res = 0;
 
 		REP(i,n)
 		{
 			REP(j,m)
 			{
 				if (mp[i][j] != '.')
 				{
 					int t = 0;
 					int r = 1;
 					for (int k = i - 1;k >= 0;k--)
 					{
 						if (mp[k][j] != '.')
 						{
 							t |= 1;
 							if (mp[i][j] == '^')
 							{
 								r = 0;
 							}
 							break;
 						}
 					}
 					for (int k = i + 1;k < n;k++)
 					{
 						if (mp[k][j] != '.')
 						{
 							t |= 2;
 							if (mp[i][j] == 'v')
 							{
 								r = 0;
 							}
 							break;
 						}
 					}
 					for (int k = j - 1;k >= 0;k--)
 					{
 						if (mp[i][k] != '.')
 						{
 							t |= 4;
 							if (mp[i][j] == '<')
 							{
 								r = 0;
 							}
 							break;
 						}
 					}
 					for (int k = j + 1;k < m;k++)
 					{
 						if (mp[i][k] != '.')
 						{
 							t |= 8;
 							if (mp[i][j] == '>')
 							{
 								r = 0;
 							}
 							break;
 						}
 					}
 
 					if (t == 0)
 					{
 						res = -1;
 						break;
 					}
 					else
 					{
 						res += r;
 					}
 					
 				}
 			}
 
 			if (res == -1)
 			{
 				break;
 			}
 		}
 		
 		printf("Case #%d: ",K);
 		if (res == -1)
 		{
 			printf("IMPOSSIBLE\n");
 		}
 		else
 		{
 			printf("%d\n",res);
 		}
 	}
 
 
 	return 0;
 }
