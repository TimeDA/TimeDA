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

int B[128];
char R[128][128];

int f(int C)
{
	if (B[0] == 0 || B[C - 1] == 0) return -1;

	int prev = 0;
	int i, j;
	int res = 0;
	FOR(i, 0, C)
		if(B[i] != 0)
		{
			int a = prev;
			prev += B[i];
			int b = prev - 1;
			res = max(res, abs(a - i));
			res = max(res, abs(b - i));
		}

	FOR(i, 0, res + 1)
		FOR(j, 0, C)
		R[i][j] = '.';
	FOR(i, 0, res + 1)
		R[i][C] = 0;

	prev = 0;
	FOR(i, 0, C)
		if (B[i] != 0)
		{
			int a = prev;
			prev += B[i];
			int b = prev - 1;

			int cnt = res;
			RFOR(j, i, a)
			{
				--cnt;
				R[cnt][j] = '\\';
			}

			cnt = res;
			FOR(j, i + 1, b + 1)
			{
				--cnt;
				R[cnt][j] = '/';
			}
		}

	return res + 1;
}

int SolveTest(int test)
{
	int C;
	scanf("%d", &C);
	int i;
	FOR(i, 0, C) scanf("%d", &B[i]);
	int res = f(C);
	if (res == -1)
		printf("Case #%d: IMPOSSIBLE\n", test + 1);
	else
	{
		printf("Case #%d: %d\n", test + 1, res);
		FOR(i, 0, res)
			printf("%s\n", R[i]);
	}
	return 0;
}

int main()
{
	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
