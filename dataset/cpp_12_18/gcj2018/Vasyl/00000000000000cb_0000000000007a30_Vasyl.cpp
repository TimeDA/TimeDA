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

int B[32][32];

int SolveTest(int test)
{
	int A;
	scanf("%d", &A);

	int K = 3;
	while (K*K < A) ++K;

	CLEAR(B, 0);

	while(true)
	{
		int i, j, ii, jj;
		int best = 0;
		int r = 0;
		int c = 0;
		FOR(i, 2, K)
			FOR(j, 2, K)
			{
				int cnt = 0;
				FOR(ii, -1, 2)
					FOR(jj, -1, 2)
					if (B[i + ii][j + jj] == 0)
						++cnt;

				if(cnt > best)
				{
					best = cnt;
					r = i;
					c = j;
				}
			}

		printf("%d %d\n", r, c);
		fflush(stdout);
		scanf("%d%d", &r, &c);
		if (r == 0 && c == 0) break;
		B[r][c] = 1;
	}
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
