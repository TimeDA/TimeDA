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

int a[100];
int d[100];
int c[100];

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
			scanf("%d", &a[i]);
			d[i] = i;
		}

		int r = 0;
		REP(i, n)
		{
			if (a[i] > 0)
			{
				for (int j = r; j < r + a[i]; j++)
				{
					c[j] = i;
				}
				r += a[i];
			}
		}
		

		printf("Case #%d: ", K);
		if (a[0] == 0 || a[n - 1] == 0)
		{
			printf("IMPOSSIBLE");
		}
		else
		{
			char mp[100][100];
			memset(mp, '.', sizeof(mp));
			int row = 1;
			REP(i, n)
			{
				if (c[i] > i)
				{
					for (int j = i,k = 0; j < c[i]; j++,k++)
					{
						mp[k][j] = '\\';
					}
					row = max(row, c[i] - i + 1);
				}
				if (c[i] < i)
				{
					for (int j = i, k = 0; j > c[i]; j--, k++)
					{
						mp[k][j] = '\/';
					}
					row = max(row, i - c[i] + 1);
				}
			}
			printf("%d\n", row);
			REP(i, row)
			{
				mp[i][n] = 0;
				printf("%s\n", mp[i]);
			}
		}
		printf("\n");
	}

	return 0;
}
