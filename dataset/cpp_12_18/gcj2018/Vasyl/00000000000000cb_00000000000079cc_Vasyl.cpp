//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int SolveTest(int test)
{
	double A;
	scanf("%lf", &A);

	double Min = 0, Max = acos(0.0);
	int i;
	FOR(i, 0, 64)
	{
		double Mid = (Max + Min) / 2;
		double s = sin(Mid);
		double c = cos(Mid);

		double x = 0.5*c + 0.5*s;
		double y = -0.5*s + 0.5*c;
		double a = 2 * max(fabs(x), fabs(y));
		if (a > A) Max = Mid;
		else Min = Mid;
	}

	double s = sin(Min);
	double c = cos(Min);

	printf("Case #%d:\n", test + 1);
	printf("%.11lf %.11lf 0\n", 0.5 * c, 0.5 * s);
	printf("%.11lf %.11lf 0\n", -0.5 * s, 0.5 * c);
	printf("0 0 0.5\n");
	return 0;
}

int main()
{
	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T) SolveTest(t);
	return 0;
};
