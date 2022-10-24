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
 
 int D[1 << 14];
 int L[1 << 14];
 int R[1 << 14];
 
 int SolveTest(int test)
 {
 	int n;
 	scanf("%d", &n);
 	
 	int i, j;
 	FOR(i, 1, n + 1)
 		scanf("%d%d", &D[i], &L[i]);
 
 	scanf("%d", &D[n + 1]);
 	L[n + 1] = 1;
 
 	CLEAR(R, 0);
 	R[0] = D[1];
 
 	FOR(i, 0, n + 1)
 	{
 		FOR(j, i + 1, n + 2)
 		{
 			if(D[i] + R[i] < D[j])
 				break;
 
 			R[j] = max(R[j], min(L[j], D[j] - D[i]));
 		}
 	}
 
 	printf("Case #%d: %s\n", test + 1, R[n + 1] == 0 ? "NO" : "YES");
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
