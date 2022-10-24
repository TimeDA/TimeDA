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
 
 int A[1 << 11];
 int R[1 << 11][1 << 11][2];
 
 int SolveTest(int test)
 {
 	int ac, aj;
 	scanf("%d%d", &ac, &aj);
 
 	CLEAR(A, -1);
 	int i, j, k;
 	FOR(i, 0, ac + aj)
 	{
 		int c, d;
 		scanf("%d%d", &c, &d);
 		int who = i < ac ? 0 : 1;
 		FOR(j, c, d) A[j] = who;
 	}
 
 	int n = 60 * 24;
 	int inf = 2 * n;
 	FOR(i, 0, n + 1)
 		FOR(j, 0, n + 1)
 		FOR(k, 0, 2)
 		R[i][j][k] = inf;
 
 	R[0][0][0] = R[0][0][1] = 0;
 	FOR(i, 0, n)
 		FOR(j, 0, n + 1)
 		FOR(k, 0, 2)
 		if(R[i][j][k] != inf)
 		{
 			int i2 = i + 1;
 			int j2, k2;
 			FOR(k2, 0, 2)
 			{
 				if (A[i] == (k2 ^ 1)) continue;
 				j2 = j + (k2 == 0 ? 1 : 0);
 				R[i2][j2][k2] = min(R[i2][j2][k2], R[i][j][k] + (k != k2 ? 1 : 0));
 			}
 		}
 
 	int res = min(R[n][n/2][0], R[n][n/2][1]);
 	if (res % 2 != 0) ++res;
 	printf("Case #%d: %d\n", test + 1, res);
 	return 0;
 }
 
 int main()
 {
 	freopen("b.in", "r", stdin);
 	freopen("b.out", "w", stdout);
 
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
