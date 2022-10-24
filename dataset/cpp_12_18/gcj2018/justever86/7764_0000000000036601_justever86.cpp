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

int flag[100001];
int dp[100001];
int mp[100001];

int main()
{
	int T;
	scanf("%d", &T);

	for (int K = 1; K <= T; K++)
	{
		int n, l;
		scanf("%d%d", &n, &l);
		
		clr(flag);
		clr(dp);
		REP(i, n + 1)
		{
			int x = i * 100 / n;
			int t0 = x * n;
			int t1 = (x + 1) * n;
			if (i * 100 > t0 && t1 - i * 100 <= i * 100 - t0)
			{
				flag[i] = 1;
			}
			else
			{
				flag[i] = 0;
			}
		}
		int temp = -1;
		PER(i, n + 1)
		{
			if (flag[i] == 1)
			{
				temp = i;
				dp[i] = 0;
			}
			else
			{
				if (temp == -1)
				{
					dp[i] = n;
				}
				else
				{
					dp[i] = temp - i;
				}
			}
		}
		int c = n;
		vector<pair<int,int> > v;
		REP(i, l)
		{
			int y;
			scanf("%d", &y);
			v.push_back(make_pair(dp[y],y));
			c -= y;
		}
		sort(ALL(v));

		int res = 0;
		REP(i, l)
		{
			int p = v[i].first;
			int q = v[i].second;
			if (c >= p)
			{
				c -= p;
				q += p;
				
			}
			res += round(100.0 * q / n);
		}
		if (c > 0)
		{
			int cc = c / temp;
			res += round(100.0 * temp / n) * cc;
			c -= cc * temp;
			res += round(100.0 * c / n);
		}

		printf("Case #%d: ", K);
		printf("%d\n", res);
	}

	return 0;
}
