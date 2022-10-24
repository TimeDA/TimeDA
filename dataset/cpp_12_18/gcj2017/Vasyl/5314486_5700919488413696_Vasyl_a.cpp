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
 
 int A[101][101][101][4];
 
 int SolveTest(int test)
 {
 	int N, P;
 	scanf("%d%d", &N, &P);
 
 	int i, j, j1, j2, j3;
 	int cnt[] = { 0, 0, 0, 0 };
 	FOR(i, 0, N)
 	{
 		int a;
 		scanf("%d", &a);
 		++cnt[a % P];
 	}
 
 	CLEAR(A, -1);
 	A[cnt[1]][cnt[2]][cnt[3]][0] = cnt[0];
 	RFOR(j1, cnt[1] + 1, 0)
 		RFOR(j2, cnt[2] + 1, 0)
 		RFOR(j3, cnt[3] + 1, 0)
 		FOR(i, 0, P)
 		if(A[j1][j2][j3][i] != -1)
 		{
 			int k[] = { 0, j1, j2, j3 };
 			FOR(j, 1, P)
 				if(k[j] != 0)
 				{
 					int r = A[j1][j2][j3][i] + (i == 0 ? 1 : 0);
 					int i2 = (i + j) % P;
 					--k[j];
 					A[k[1]][k[2]][k[3]][i2] = max(A[k[1]][k[2]][k[3]][i2], r);
 					++k[j];
 				}
 		}
 
 	int res = -1;
 	FOR(i, 0, P)
 		res = max(res, A[0][0][0][i]);
 
 	printf("Case #%d: %d\n", test + 1, res);
 	return 0;
 }
 
 int main()
 {
 	freopen("", "r", stdin);
 	freopen("", "w", stdout);
 
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
