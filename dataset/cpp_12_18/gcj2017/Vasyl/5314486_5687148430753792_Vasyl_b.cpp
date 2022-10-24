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
 
 
 int f(VInt& cnt, int len)
 {
 	int i;
 	int res = 0;
 	int am = 0;
 	RFOR(i, SIZE(cnt), 0)
 	{
 		int zero = min(len, cnt[i]);
 		int free = len - zero;
 		am += cnt[i] - zero;
 		int r = min(am, free);
 		am -= r;
 		res += r;
 	}
 	if (am > 0) return -1;
 	return res;
 }
 
 int SolveTest(int test)
 {
 	int N, C, M;
 	scanf("%d%d%d", &N, &C, &M);
 
 	int i;
 	VInt seatCnt(N, 0);
 	VInt cnt(C, 0);
 	FOR(i, 0, M)
 	{
 		int a, b;
 		scanf("%d%d", &a, &b);
 		--a;
 		--b;
 		++seatCnt[a];
 		++cnt[b];
 	}
 
 	int Min = *max_element(ALL(cnt)) - 1, Max = M;
 	while(Max - Min > 1)
 	{
 		int Mid = (Max + Min) / 2;
 		int r = f(seatCnt, Mid);
 		if (r == -1)
 			Min = Mid;
 		else
 			Max = Mid;
 	}
 
 	printf("Case #%d: %d %d\n", test + 1, Max, f(seatCnt, Max));
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
