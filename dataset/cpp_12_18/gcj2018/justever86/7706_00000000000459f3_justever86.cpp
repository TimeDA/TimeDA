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

int f(int n, int m, int d)
{
	int x = 0;
	int y = 0;
	int res = 0;
	while (true)
	{
		if (n >= x && m >= y)
		{
			res++;
			n -= x;
			m -= y;
			x++;
			if (x > d)
			{
				x = 0;
				y++;
			}
		}
		else if (x == 0)
		{
			break;
		}
		else
		{
			x = 0;
			y++;
		}
	}
	return res;
}
int g(int n, int m, int x, int y, int r)
{
	if (n >= x && m >= y)
	{
		n -= x;
		m -= y;

		x--;
		y++;
		if (y > r)
		{
			r++;
			x = r;
			y = 0;
		}
		return g(n, m, x, y, r) + 1;
	}
	else if (n + m < r)
	{
		return 0;
	}
	else
	{
		x--;
		y++;
		if (y > r)
		{
			r++;
			x = r;
			y = 0;
		}
		return g(n, m, x, y, r);
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int K = 1; K <= T; K++)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		int res = 0;
		REP(i, n + 1)
		{
			res = max(f(n, m, i), res);
		}
		REP(i, m + 1)
		{
			res = max(f(m, n, i), res);
		}

		int t = g(n, m, 0, 0, 0);
		if (t > res)
		{
			//printf("%d %d %d %d\n", n, m, t, res);
			res = t;
		}

		printf("Case #%d: ", K);
		printf("%d\n", res - 1);
	}

	return 0;
}
