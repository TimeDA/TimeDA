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
 
 const int DX[] = { -1, 1, 0, 0 };
 const int DY[] = { 0, 0, -1, 1 };
 const char DC[] = { '^', 'v', '<', '>' };
 
 char A[128][128];
 
 int SolveTest(int test)
 {
 	int N, M;
 	scanf("%d%d", &N, &M);
 
 	int i, j, k;
 	FOR(i, 0, N)
 		scanf("%s", A[i]);
 
 	int impossible = 0;
 	int res = 0;
 	FOR(i, 0, N)
 		FOR(j, 0, M)
 		if (A[i][j] != '.')
 		{
 			int found[] = { 0, 0, 0, 0 };
 			FOR(k, 0, 4)
 			{
 				int x = i + DX[k];
 				int y = j + DY[k];
 				while (0 <= x && x < N && 0 <= y && y < M)
 				{
 					if (A[x][y] != '.')
 					{
 						found[k] = 1;
 						break;
 					}
 
 					x += DX[k];
 					y += DY[k];
 				}
 			}
 
 			int cnt = 0;
 			int match = 0;
 			FOR(k, 0, 4)
 				if (found[k] != 0)
 				{
 					++cnt;
 					if (DC[k] == A[i][j])
 						match = 1;
 				}
 
 			if (cnt == 0)
 				impossible = 1;
 			else if (match == 0)
 				++res;
 		}
 
 	if (impossible != 0)
 		printf("Case #%d: IMPOSSIBLE\n", test + 1);
 	else
 		printf("Case #%d: %d\n", test + 1, res);
 	
 	return 0;
 }
 
 int main()
 {
 	freopen("a.in", "r", stdin);
 	freopen("a.out", "w", stdout);
 
 	int T, t;
 	char buf[1 << 7];
 	gets(buf);
 	sscanf(buf, "%d", &T);
 	FOR(t, 0, T)
 	{
 		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
 		SolveTest(t);
 	}
 
 	return 0;
 };
