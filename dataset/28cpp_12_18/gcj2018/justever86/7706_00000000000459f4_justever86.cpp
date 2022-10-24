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

char s[20][20];

int dr[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int f(int n, int m, int x, int y)
{

	int mp[20][20];
	memset(mp, 0, sizeof(mp));
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	if (x < n - 1)
	{
		q.push(make_pair(x + 1, y));
		if (y < m - 1)
		{
			q.push(make_pair(x + 1, y + 1));
		}
	}
	if (y < m - 1)
	{
		q.push(make_pair(x, y + 1));
	}

	int res = 0;
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		if (mp[xx][yy] == 1)
		{
			continue;
		}
		mp[xx][yy] = 1;
		res++;

		REP(i, 4)
		{
			int nx = xx + dr[i][0];
			int ny = yy + dr[i][1];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (nx <= x && ny <= y && s[nx][ny] == s[x][y])
				{
					q.push(make_pair(nx, ny));
				}
				if (nx <= x && ny > y && s[nx][ny] == s[x][y + 1])
				{
					q.push(make_pair(nx, ny));
				}
				if (nx > x && ny <= y && s[nx][ny] == s[x + 1][y])
				{
					q.push(make_pair(nx, ny));
				}
				if (nx > x && ny > y && s[nx][ny] == s[x + 1][y + 1])
				{
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int K = 1; K <= T; K++)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		REP(i, n)
		{
			scanf("%s", s[i]);
		}

		int res = 0;
		REP(i, n)
		{
			REP(j, m)
			{
				int t = f(n, m, i, j);
				res = max(res, t);
			}
		}

		printf("Case #%d: ", K);
		printf("%d\n", res);
	}

	return 0;
}
