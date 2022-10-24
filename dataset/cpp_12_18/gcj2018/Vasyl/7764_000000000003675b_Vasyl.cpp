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

int A[2][1 << 18];
int Next[2][1 << 18];
int R[2][1 << 18];

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);
	int i, j;
	FOR(i, 0, N)
	{
		int d, a, b;
		scanf("%d%d%d", &d, &a, &b);
		A[0][i] = d + a;
		A[1][i] = d - b;
	}

	Next[0][N - 1] = Next[1][N - 1] = N;
	RFOR(i, N - 1, 0)
		FOR(j, 0, 2)
		{
			if (A[j][i] == A[j][i + 1])
				Next[j][i] = Next[j][i + 1];
			else
				Next[j][i] = i + 1;
		}

	R[0][N - 1] = R[1][N - 1] = 1;
	RFOR(i, N - 1, 0)
		FOR(j, 0, 2)
		{
			int i2 = Next[j][i];
			if(i2 == N)
			{
				R[j][i] = i2 - i;
				continue;
			}
			int i3 = Next[j ^ 1][i2];
			if(i3 == N)
			{
				R[j][i] = i3 - i;
				continue;
			}

			if (A[j][i] == A[j][i3])
				R[j][i] = R[j ^ 1][i2] + i2 - i;
			else
				R[j][i] = i3 - i;
		}
	
	int best = 0;
	FOR(i, 0, N)
		FOR(j, 0, 2)
			best = max(best, R[j][i]);

	int cnt = 0;
	FOR(i, 0, N)
		if (R[0][i] == best || R[1][i] == best)
			++cnt;

	printf("Case #%d: %d %d\n", test + 1, best, cnt);
	return 0;
}

int main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);

	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
//		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
