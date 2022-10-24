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

int rr[100][2];
long long g[100];
long long gg[100];

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
			scanf("%I64d%I64d", &rr[i][0], &rr[i][1]);
			rr[i][0]--;
			rr[i][1]--;
		}
		long long l = 0;
		long long r = 0;
		REP(i, n)
		{
			scanf("%I64d", &g[i]);
			r += g[i];
		}
		l = g[0];
		long long res = l;
		while (l <= r)
		{
			long long m = (l + r) / 2;
			REP(i, n)
			{
				gg[i] = g[i];
			}

			map<int, long long> mp[2];
			int x = 0;
			int y = 1;
			mp[x][0] = m;

			int flag[100];
			clr(flag);
			int need = 1;
			int fail = 0;
			while (!fail && need)
			{
				need = 0;
				for (map<int, long long>::iterator it = mp[x].begin(); it != mp[x].end(); it++)
				{
					int key = it->first;
					long long value = it->second;
					if (flag[key] <= n)
					{
						if (gg[key] >= value)
						{
							gg[key] -= value;
						}
						else
						{
							need = 1;
							value -= gg[key];
							gg[key] = 0;
							flag[key]++;
							mp[y][rr[key][0]] += value;
							mp[y][rr[key][1]] += value;
						}
					}
					else
					{
						fail = 1;
						break;
					}
				}
				x ^= 1;
				y ^= 1;
				mp[y].clear();
			}
			if (fail)
			{
				r = m - 1;
			}
			else
			{
				l = m + 1;
				res = m;
			}
		}

		printf("Case #%d: ", K);
		printf("%I64d\n", res);
	}

	return 0;
}
