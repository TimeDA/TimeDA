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
#define pi 3.1415926535

#define	MAXN		3
#define MODN		(1000000007)

typedef long long ll;

#define fabs(x) ((x)>0?(x):-(x))
#define zero(x) (fabs(x)<1e-10)

struct mat {
	int n, m;
	double data[MAXN][MAXN];
};

int mul(mat& c, const mat& a, const mat& b) {
	int i, j, k;
	if (a.m != b.n)
		return 0;
	c.n = a.n, c.m = b.m;
	for (i = 0; i<c.n; i++)
		for (j = 0; j<c.m; j++)
			for (c.data[i][j] = k = 0; k<a.m; k++)
				c.data[i][j] += a.data[i][k] * b.data[k][j];
	return 1;
}


int main()
{
	int T;
	scanf("%d", &T);

	for (int K = 1; K <= T; K++)
	{
		double x;
		scanf("%lf", &x);

		mat s[3];
		mat res[3];
		for (int i = 0; i < 3; i++)
		{
			s[i].n = 1;
			s[i].m = 3;
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
				{
					s[i].data[0][j] = 0.5;
				}
				else
				{
					s[i].data[0][j] = 0;
				}
			}
		}


		if (x <= sqrt(2))
		{
			double t = sqrt(2);
			double theta = pi / 4 - acos(x / t);

			double t1 = sin(pi / 4);
			double t2 = cos(pi / 4);
			double t4 = x / t;
			double t30 = x / t;
			double t3 = sqrt(1 - t30 * t30);
			double t6 = t2 * t4 + t1 * t3;
			double t5 = t1 * t4 - t2 * t3;

			mat r;
			r.n = r.m = 3;
			r.data[0][0] = cos(theta);
			r.data[0][0] = t6;
			r.data[0][1] = -sin(theta);
			r.data[0][1] = -t5;
			r.data[0][2] = 0;
			r.data[1][0] = sin(theta);
			r.data[1][0] = t5;
			r.data[1][1] = cos(theta);
			r.data[1][1] = t6;
			r.data[1][2] = 0;
			r.data[2][0] = 0;
			r.data[2][1] = 0;
			r.data[2][2] = 1;

			for (int i = 0; i < 3; i++)
			{
				mul(res[i], s[i], r);
			}
		}
		else
		{
			return -1;
		}

		printf("Case #%d: ", K);
		printf("\n");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j != 0)
				{
					printf(" ");
				}
				printf("%.8lf", res[i].data[0][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
