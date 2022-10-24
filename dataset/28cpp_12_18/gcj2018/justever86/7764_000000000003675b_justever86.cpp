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
	int T;
	scanf("%d", &T);

	for (int K = 1; K <= T; K++)
	{
		int n;
		scanf("%d", &n);
		vector<pair<int, int> > v;
		REP(i, n)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			v.push_back(make_pair(a + b, a - c));
		}

		int resA = 0;
		int resB = 0;

		REP(i, n)
		{
			int lt = inf;
			int llen = 1;
			rep(j, i + 1, n)
			{
				if (v[j].first != v[i].first)
				{
					if (lt == inf)
					{
						lt = v[j].second;
					}
					else if (lt != v[j].second)
					{
						break;
					}
				}

				llen++;
			}
			int rt = inf;
			int rlen = 1;
			rep(j, i + 1, n)
			{
				if (v[j].second != v[i].second)
				{
					if (rt == inf)
					{
						rt = v[j].first;
					}
					else if (rt != v[j].first)
					{
						break;
					}
				}

				rlen++;
			}
			int len = max(llen, rlen);
			if (len > resA)
			{
				resA = len;
				resB = 1;
			}
			else if (len == resA)
			{
				resB++;
			}
		}

		printf("Case #%d: ", K);
		printf("%d %d\n", resA, resB);
	}

	return 0;
}
