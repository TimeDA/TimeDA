#include <cstdio>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <cstdarg>
 
 #define clr(a) memset(a, 0, sizeof(a))
 #define fill(a, b) memset(a, b, sizeof(a))
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef std::pair<int,int> pii;
 
 #define DBG2 1
 
 void dbg(const char * fmt, ...)
 {
 #ifdef DBG1
 #if DBG2
 	FILE* file = stderr;
 	va_list args;
 	va_start(args, fmt);
 	vfprintf(file, fmt, args);
 	va_end(args);
 
 	fflush(file);
 #endif
 #endif
 }
 
 using namespace std;
 
 const int root = 0;
 
 struct Node {
 	bool end;
 	int cnt;
 	int next[26];
 
 	Node()
 	{
 		cnt = 0;
 		end = false;
 		fill(next, 0xFF);
 	}
 };
 
 vector <Node> nodes;
 
 void initTrie()
 {
 	nodes.clear();
 	nodes.push_back(Node());
 }
 
 void addInTrie(const char * s)
 {
 	dbg("add '%s'\n", s);
 	int t = root;
 	for (int i = 0; s[i]; ++i)
 	{
 		nodes[t].cnt++;
 		if (nodes[t].next[s[i] - 'A'] == -1)
 		{
 			int newNum = nodes.size();
 			nodes.push_back(Node());
 			nodes[t].next[s[i] - 'A'] = newNum;
 			t = newNum;
 		}
 		else
 			t = nodes[t].next[s[i] - 'A'];
 	}
 	nodes[t].cnt++;
 	nodes[t].end = true;
 }
 
 struct Result {
 	int cntDiff;
 	int space;
 	ll cnt;
 };
 
 const int MAX = 120;
 ll C[MAX + 1][MAX + 2];
 const ll P = ll(1e9) + 7;
 
 ll calcDp(int n, const vector <int> & v)
 {
 	int k = int(v.size());
 	dbg("dp for n = %d, v = (", n);
 	for (int j = 0; j < k; ++j)
 		dbg("%d, ", v[j]);
 	dbg(")\n");
 
 	vector < vector <ll> > dp(2, vector <ll> (n + 1, 0));
 	dp[0][0] = 1;
 	for (int i = 0; i < k; ++i)
 	{
 		for (int j = 0; j <= n; ++j)
 		{
 			ll & cur = dp[i&1][j];
 			cur %= P;
 			if (cur == 0) continue;
 			dbg("dp[%d][%d] = %d\n", i, j, cur);
 			for (int p = min(v[i], j); p >= 0; --p)
 			{
 				int q = j + v[i] - p;
 				if (q <= n)
 				{
 					dp[1^i&1][q] += (cur * (C[j][p] * C[n - j][v[i] - p]) % P) % P;
 				}
 			}
 			cur = 0;
 		}
 	}
 	return dp[k&1][n] % P;
 }
 
 Result solve(int t, int k)
 {
 	vector <Result> childRes;
 	vector <int> childCnt;
 	for (int i = 0; i < 26; ++i)
 	{
 		if (nodes[t].next[i] != -1)
 		{
 			childRes.push_back(solve(nodes[t].next[i], k));
 			childCnt.push_back(childRes.back().cntDiff);
 		}
 	}
 
 	if (nodes[t].end)
 	{
 		childCnt.push_back(1);
 	}
 
 	Result res;
 	res.cntDiff = min(k, nodes[t].cnt);
 	res.space = res.cntDiff;
 	res.cnt = calcDp(res.cntDiff, childCnt) % P;
 	for (int i = 0; i < int(childRes.size()); ++i)
 	{
 		res.space += childRes[i].space;
 		(res.cnt *= childRes[i].cnt) %= P;
 	}
 	dbg("t = %d, cntDiff = %d, space = %d, cnt = %lld\n", t, res.cntDiff, res.space, res.cnt);
 	return res;
 }
 
 int main()
 {
 #ifdef DBG1
 	freopen(".in", "r", stdin);
 	freopen(".out", "w", stdout);
 
 	freopen(".err", "w", stderr);
 #endif
 
 	for (int i = 0; i <= MAX; ++i)
 	{
 		C[i][0] = C[i][i] = 1;
 		for (int j = 1; j < i; ++j)
 			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
 	}
 
 	int tt;
 	scanf("%d", &tt);
 	for (int ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d: ", ii);
 		initTrie();
 		int n, k;
 		scanf("%d%d", &n, &k);
 		for (int i = 0; i < n; ++i)
 		{
 			static char s[1000];
 			scanf("%s", s);
 			addInTrie(s);
 		}
 		dbg("Read success\n");
 		Result res = solve(root, k);
 		ll ans = (res.cnt * C[k][res.cntDiff]) % P;
 		printf("%d %lld\n", res.space, ans);
 	}
 
 	return 0;
 }
