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

char A[32][32];
int B[32][32];
int Square[3][3][3][3];
int R, C;

int getType(int r, int c)
{
	if (r < 0 || R <= r || c < 0 || C <= c) return 2;
	return A[r][c] == 'B' ? 0 : 1;
}

int dfs(int r, int c)
{
	if (r < 0 || R <= r || c < 0 || C <= c) return 0;
	if (B[r][c] != 0) return 0;
	int res = 1;
	B[r][c] = 1;
	res += dfs(r + 1, c);
	res += dfs(r - 1, c);
	res += dfs(r, c + 1);
	res += dfs(r, c - 1);
	return res;
}

int SolveTest(int test)
{
	scanf("%d%d", &R, &C);
	int i, j, r, c;
	FOR(i, 0, R)
		scanf("%s", &A[i]);

	CLEAR(Square, 0);
	int i00, i01, i10, i11;
	FOR(i, 0, R + 1)
		FOR(j, 0, C + 1)
		{
			i00 = getType(i - 1, j - 1);
			i01 = getType(i - 1, j);
			i10 = getType(i, j - 1);
			i11 = getType(i, j);
			Square[i00][i01][i10][i11] = 1;
		}

	int res = 0;
	FOR(i00, 0, 3)
		FOR(i01, 0, 3)
		FOR(i10, 0, 3)
		FOR(i11, 0, 3)
		if(Square[i00][i01][i10][i11] != 0)
		{
			int type[][2] = { {i00, i01}, {i10, i11} };
			FOR(r, 0, R + 1)
				FOR(c, 0, C + 1)
				{
					FOR(i, 0, R)
						FOR(j, 0, C)
							B[i][j] = getType(i, j) == type[i < r ? 0 : 1][j < c ? 0 : 1] ? 0 : -1;

					FOR(i, 0, R)
						FOR(j, 0, C)
						if (B[i][j] == 0)
							res = max(res, dfs(i, j));
				}
		}

	printf("Case #%d: %d\n", test + 1, res);
	return 0;
}

int main()
{
	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
		SolveTest(t);

	return 0;
};
