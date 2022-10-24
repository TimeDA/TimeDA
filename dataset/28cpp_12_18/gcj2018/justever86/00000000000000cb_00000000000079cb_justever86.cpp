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
		vector<int> a, b;
		REP(i, n)
		{
			int x;
			scanf("%d", &x);
			if (i % 2 == 0)
			{
				a.push_back(x);
			}
			else
			{
				b.push_back(x);
			}
		}
		sort(ALL(a));
		sort(ALL(b));

		vector<int> v;
		int la = a.size();
		int lb = b.size();
		for (int i = 0; i < la; i++)
		{
			v.push_back(a[i]);
			if (i < lb)
			{
				v.push_back(b[i]);
			}
		}
		int res = -1;
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && v[i] < v[i - 1])
			{
				res = i;
				break;
			}
			if (i < n - 1 && v[i] > v[i + 1])
			{
				res = i;
				break;
			}
		}

		printf("Case #%d: ", K);
		if (res == -1)
		{
			printf("OK\n");
		}
		else
		{
			printf("%d\n", res);
		}
	}

	return 0;
}
