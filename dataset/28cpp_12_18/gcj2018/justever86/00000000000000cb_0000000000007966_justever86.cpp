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

int main()
{
	int T;
	scanf("%d", &T);

	for (int K = 1; K <= T; K++)
	{
		int d;
		scanf("%d", &d);
		char s[31];
		scanf("%s", s);
		int len = strlen(s);
		vector<int> v;
		int now = 0;
		int p = 1;
		REP(i, len)
		{
			if (s[i] == 'C')
			{
				v.insert(v.begin(), i);
				p *= 2;
			}
			else
			{
				now += p;
			}
		}
		int res = 0;
		int cur = 0;
		while (now > d && cur < v.size())
		{
			if (v[cur] < len - cur - 1)
			{
				v[cur] ++;
				now -= p / 2;
				res++;
			}
			else
			{
				cur++;
				p /= 2;
			}
		}


		printf("Case #%d: ", K);
		if (now <= d)
		{
			printf("%d\n", res);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
		//cerr << "Case #" << K << " Done" << endl;
	}

	return 0;
}
