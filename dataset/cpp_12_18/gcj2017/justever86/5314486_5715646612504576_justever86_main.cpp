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
 
 char s[50][51];
 
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
 			scanf("%s",s[i]);
 		}
 // 		printf("\n");
 // 		REP(i,n)
 // 		{
 // 			printf("%s\n",s[i]);
 // 		}
 // 		printf("\n");
 		int flag[50][50][2];
 		clr(flag);
 
 
 		bool res = true;
 		vector<pair<int,int> > v;
 		REP(i,n)
 		{
 			REP(j,m)
 			{
 				if (s[i][j] == '|' || s[i][j] == '-')
 				{
 					rep(ii,i + 1,n)
 					{
 						if (s[ii][j] == '|' || s[ii][j] == '-')
 						{
 							flag[i][j][0] |= 1;
 						}
 						else if(s[ii][j] == '.')
 						{
 							flag[i][j][0] |= 2;
 						}
 						else if (s[ii][j] == '#')
 						{
 							break;
 						}
 					}
 					PER(ii,i)
 					{
 						if (s[ii][j] == '|' || s[ii][j] == '-')
 						{
 							flag[i][j][0] |= 1;
 						}
 						else if(s[ii][j] == '.')
 						{
 							flag[i][j][0] |= 2;
 						}
 						else if (s[ii][j] == '#')
 						{
 							break;
 						}
 					}
 
 					rep(jj,j + 1,m)
 					{
 						if (s[i][jj] == '-' || s[i][jj] == '|')
 						{
 							flag[i][j][1] |= 1;
 						}
 						else if (s[i][jj] == '.')
 						{
 							flag[i][j][1] |= 2;
 						}
 						else if (s[i][jj] == '#')
 						{
 							break;
 						}
 					}
 					PER(jj,j)
 					{
 						if (s[i][jj] == '-' || s[i][jj] == '|')
 						{
 							flag[i][j][1] |= 1;
 						}
 						else if (s[i][jj] == '.')
 						{
 							flag[i][j][1] |= 2;
 						}
 						else if (s[i][jj] == '#')
 						{
 							break;
 						}
 					}
 					if (flag[i][j][1] == 2)
 					{
 						s[i][j] = '-';
 					}
 					else if (flag[i][j][0] == 2)
 					{
 						s[i][j] = '|';
 					}
 					else if (flag[i][j][1] == 0)
 					{
 						s[i][j] = '-';
 					}
 					else if (flag[i][j][0] == 0)
 					{
 						s[i][j] = '|';
 					}
 					else
 					{
 						res = false;
 					}
 				}
 				if (!res)
 				{
 					break;
 				}
 			}
 			if (!res)
 			{
 				break;
 			}
 		}
 		
 		if (res)
 		{
 			REP(i,n)
 			{
 				REP(j,m)
 				{
 					if (s[i][j] == '.')
 					{
 						rep(ii,i + 1,n)
 						{
 							if (s[ii][j] == '|')
 							{
 								flag[i][j][0] = 1;
 							}
 							else if (s[ii][j] == '#')
 							{
 								break;
 							}
 						}
 						PER(ii,i)
 						{
 							if (s[ii][j] == '|')
 							{
 								flag[i][j][0] = 1;
 							}
 							else if (s[ii][j] == '#')
 							{
 								break;
 							}
 						}
 
 						rep(jj,j + 1,m)
 						{
 							if (s[i][jj] == '-')
 							{
 								flag[i][j][1] = 1;
 							}
 							else if (s[i][jj] == '#')
 							{
 								break;
 							}
 						}
 						PER(jj,j)
 						{
 							if (s[i][jj] == '-')
 							{
 								flag[i][j][1] = 1;
 							}
 							else if (s[i][jj] == '#')
 							{
 								break;
 							}
 						}
 
 						if (flag[i][j][1] == 1)
 						{
 						}
 						else if (flag[i][j][0] == 1)
 						{
 						}
 						else
 						{
 							res = false;
 						}
 					}
 				}
 			}
 		}
 
 		printf("Case #%d: ",K);
 		if (res)
 		{
 			printf("POSSIBLE\n");
 			REP(i,n)
 			{
 				printf("%s\n",s[i]);
 			}
 		}
 		else
 		{
 			printf("IMPOSSIBLE\n");
 // 			REP(i,n)
 // 			{
 // 				printf("%s\n",s[i]);
 // 			}
 		}
 		cerr<<"Case #"<<K<<" Done"<<endl;
 		
 	}
 
 	return 0;
 }
