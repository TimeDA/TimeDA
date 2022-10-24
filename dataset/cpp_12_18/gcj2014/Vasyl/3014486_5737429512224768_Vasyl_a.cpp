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
 
 int A[1 << 16];
 int B[1 << 16];
 
 int SolveTest(int test)
 {
 	int N, X;
 	scanf("%d%d", &N, &X);
 
 	int i;
 	FOR(i, 0, N)
 		scanf("%d", &A[i]);
 
 	sort(A, A + N);
 
 	CLEAR(B, 0);
 	int pos = N - 1;
 	int res = 0;
 	FOR(i, 0, N)
 	if (B[i] == 0)
 	{
 		B[i] = 1;
 		while (pos > i && A[pos] + A[i] > X)
 			--pos;
 
 		if (pos > i)
 		{
 			B[pos] = 1;
 			--pos;
 		}
 
 		++res;
 	}
 
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
