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

#define MAX 512

int R[2][MAX][MAX];

int SolveTest(int test, int pos)
{
	int r, b;
	scanf("%d%d", &r, &b);
	printf("Case #%d: %d\n", test + 1, R[pos][r][b]);
	return 0;
}

int main()
{
	CLEAR(R, 0);
	int limit = 0;
	while (limit*(limit + 1) / 2 < MAX) ++limit;

	int i, j, r, b;
	int prev = 0;
	int next = 1;
	FOR(r, 0, limit + 1)
		FOR(b, 0, limit + 1)
		{
			if (r + b == 0) continue;
			CLEAR(R[next], 0);
			FOR(i, 0, MAX)
				FOR(j, 0, MAX)
				{
					R[next][i][j] = R[prev][i][j];
					if (i != 0) R[next][i][j] = max(R[next][i][j], R[next][i - 1][j]);
					if (j != 0) R[next][i][j] = max(R[next][i][j], R[next][i][j - 1]);
					if (i >= r && j >= b) R[next][i][j] = max(R[next][i][j], R[prev][i - r][j - b] + 1);
				}

			swap(prev, next);
		}

	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
		SolveTest(t, prev);

	return 0;
};
