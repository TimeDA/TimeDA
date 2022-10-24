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
 
 string SS[16][4];
 int C[16][4][4];
 
 int SolveTest(int test)
 {
 	int N, R, P, S;
 	scanf("%d%d%d%d", &N, &R, &P, &S);
 
 	int i, j, k;
 
 	CLEAR(C, 0);
 	string s = "PRS";
 	int have[] = { P, R, S };
 	FOR(i, 0, 3)
 	{
 		SS[0][i] = string(1, s[i]);
 		C[0][i][i] = 1;
 	}
 
 	FOR(i, 0, N)
 	{
 		FOR(j, 0, 3)
 		{
 			int jj = (j + 1) % 3;
 			string l = SS[i][j];
 			string r = SS[i][jj];
 			FOR(k, 0, 3)
 				C[i + 1][j][k] = C[i][j][k] + C[i][jj][k];
 
 			if (l > r) swap(l, r);
 			SS[i + 1][j] = l + r;
 		}
 	}
 
 	string res = "Z";
 	FOR(i, 0, 3)
 	{
 		FOR(j, 0, 3)
 			if (C[N][i][j] != have[j]) break;
 
 		if (j == 3) res = min(res, SS[N][i]);
 	}
 
 	if (res == "Z") res = "IMPOSSIBLE";
 	printf("Case #%d: %s\n", test + 1, res.c_str());
 
 	return 0;
 }
 
 int main()
 {
 	freopen("a.in", "r", stdin);
 	freopen("a.out", "w", stdout);
 
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
