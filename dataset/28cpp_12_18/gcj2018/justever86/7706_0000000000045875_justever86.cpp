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

int a[100][100];
int d[100][100];

int main()
{
	int T;
	scanf("%d", &T);

	for (int K = 1; K <= T; K++)
	{
		int n;
		scanf("%d", &n);

		REP(i, n)
		{
			REP(j, n)
			{
				scanf("%d", &a[i][j]);
				d[i][j] = a[i][j];
			}
		}

		int mask = 1 << (n * n);
		int res = n * n;
		REP(o, mask)
		{
			int cnt = 0;

			REP(x, n)
			{
				REP(y, n)
				{
					a[x][y] = d[x][y];
				}
			}

			REP(i, n * n)
			{
				if (o & (1 << i))
				{
					int s[101][2];
					memset(s, 0, sizeof(s));


					int x = i / n;
					int y = i % n;
					REP(j, n)
					{
						if (j != x)
						{
							if (a[j][y] > 0)
							{
								s[a[j][y]][0] = 1;
							}
							else
							{
								s[-a[j][y]][1] = 1;
							}
						}
					}
					REP(j, n)
					{
						if (j != y)
						{
							if (a[x][j] > 0)
							{
								s[a[x][j]][0] = 1;
							}
							else
							{
								s[-a[x][j]][1] = 1;
							}
						}
					}

					if ((a[x][y] > 0 && s[a[x][y]][0] == 1) || (a[x][y] < 0 && s[-a[x][y]][1] == 1))
					{
						rep(j, 1, n + 1)
						{
							if (s[j][0] == 0)
							{
								a[x][y] = j;
								break;
							}
							if (s[j][1] == 0)
							{
								a[x][y] = -j;
								break;
							}
						}
						cnt++;
					}
				}
			}

			int flag = true;
			REP(x, n)
			{
				REP(y, n)
				{
					REP(z, n)
					{
						if (a[x][y] == a[x][z] && y != z)
						{
							flag = false;
						}
						if (a[x][y] == a[z][y] && x != z)
						{
							flag = false;
						}

						if (!flag)
						{
							break;
						}
					}
					if (!flag)
					{
						break;
					}
				}
				if (!flag)
				{
					break;
				}
			}

			if (flag)
			{
				res = min(res, cnt);
			}
		}

		printf("Case #%d: ", K);
		printf("%d\n", res);
	}

	return 0;
}
