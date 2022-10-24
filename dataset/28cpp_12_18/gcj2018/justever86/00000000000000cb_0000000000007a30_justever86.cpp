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

int mp[1001][1001];
FILE* f;

void out(int x, int y)
{
	printf("%d %d\n", x + 1, y + 1);
	//fprintf(f, "out %d %d\n", x + 1, y + 1);
	fflush(stdout);
}

int in()
{
	int x, y;
	int res = 0;
	scanf("%d%d", &x, &y);
	//fprintf(f, "in %d %d\n", x, y);
	if (x == 0 && y == 0)
	{
		return 2;
	}
	else if (x == 1 && y == -1)
	{
		return 3;
	}
	x--;
	y--;
	res = mp[x][y];
	mp[x][y] = 1;
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);

	//f = fopen("data.out", "w");

	for (int K = 1; K <= T; K++)
	{
		
		clr(mp);
		int a;
		scanf("%d", &a);
		//fprintf(f, "TEST %d %d\n", K, a);

		int ax, ay;
		int t = 1000 * 1000;
		for (int i = 3; i * i <= a; i++)
		{
			int tx = i;
			int ty = (a + tx - 1) / tx;
			if (tx * ty < t)
			{
				ax = tx;
				ay = ty;
				t = tx * ty;
			}
		}

		int flag = 1;
		while (flag == 1)
		{
			flag = 0;
			for (int i = 0; i < ax && flag == 0; i++)
			{
				for (int j = 0; j < ay && flag == 0; j++)
				{
					if (mp[i][j] == 0)
					{
						int ti = i;
						int tj = j;
						if (ti == 0)
						{
							ti++;
						}
						else if (ti == ax - 1)
						{
							ti--;
						}
						if (tj == 0)
						{
							tj++;
						}
						else if (tj == ay - 1)
						{
							tj--;
						}
						out(ti, tj);
						int r = in();
						if (r > 2)
						{
							return 0;
						}
						if (r == 2)
						{
							flag = 2;
						}
						else
						{
							flag = 1;
						}
					}
				}
			}
		}
	}
	//fclose(f);

	return 0;
}
