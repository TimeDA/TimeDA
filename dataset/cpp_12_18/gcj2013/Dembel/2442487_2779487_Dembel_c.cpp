#include <cstdio>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <cstdarg>
 
 using namespace std;
 
 #define clr(a) memset(a, 0, sizeof(a))
 #define fill(a, b) memset(a b, sizeof(a))
 
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
 
 void dfs(int s, vector< vector<int> > & ed, vector <bool> & used, vector <int> & topsort)
 {
 	if (used[s])
 		return;
 	used[s] = true;
 	for (int i = 0; i < int(ed[s].size()); ++i)
 		dfs(ed[s][i], ed, used, topsort);
 	topsort.push_back(s);
 }
 
 void checkAnswer(vector<int> &a, vector<int>&b, vector<int>&ans)
 {
 	int n = int(a.size());
 	for (int i = 0; i < n; ++i)
 	{
 		int curA = 1;
 		for (int j = 0; j < i; ++j)
 			if (ans[j] < ans[i])
 				curA = max(curA, a[j] + 1);
 		if (curA != a[i])
 		{
 			dbg("a[%d] = %d\n", i, curA);
 			throw 42;
 		}
 	}
 
 	for (int i = n - 1; i >= 0; --i)
 	{
 		int curB = 1;
 		for (int j = n - 1; j > i; --j)
 			if (ans[j] < ans[i])
 				curB = max(curB, b[j] + 1);
 		if (curB != b[i])
 		{
 			dbg("b[%d] = %d\n", i, curB);
 			throw 42;
 		}
 	}
 }
 
 int n;
 
 bool good(int k, vector<int>&ans, vector<int>&a, vector<int>&b, vector < vector<int> > &prev, vector<int>&curB, vector<int>&last)
 {
 	int curA = 1;
 	for (int i = 0; i < k; ++i)
 	{
 		if (ans[i] < ans[k] && curA < a[i] + 1)
 			curA = a[i] + 1;
 	}
 	if (curA != a[k])
 		return false;
 
 	for (int j = 0; j < int(prev[k].size()); ++j)
 	{
 		int curJ = prev[k][j];
 
 		if (ans[k] < ans[curJ] && curB[curJ] < b[k] + 1)
 			curB[curJ] = b[k] + 1;
 		if (curB[curJ] != b[curJ] && last[curJ] <= k)
 			return false;
 	}
 	return true;
 }
 
 bool brute(int k, vector<int>&ans, vector<int>&a, vector<int>&b, vector<bool>&used, vector < vector<int> > &prev, vector<int>&curB, vector<int>&last)
 {
 	if (k == n)
 		return true;
 	for (int cur = a[k] + b[k] - 2; cur < n; ++cur)
 	{
 		if (used[cur])
 			continue;
 		ans[k] = cur;
 		dbg("ans[%d] = %d\n", k, cur);
 		vector <int> _curB = curB;
 		if (good(k, ans, a, b, prev, curB, last))
 		{
 			used[cur] = true;
 			if (brute(k + 1, ans, a, b, used, prev, curB, last))
 				return true;
 			used[cur] = false;
 		}
 		curB = _curB;
 		ans[k] = 0;
 	}
 	return false;
 }
 
 int main()
 {
 #ifdef DBG1
 	freopen(".in", "r", stdin);
 	freopen(".out", "w", stdout);
 	freopen(".err", "w", stderr);
 #endif
 
 	int tt;
 	scanf("%d", &tt);
 	for (int ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d:", ii);
 		dbg("Case #%d:\n", ii);
 
 		scanf("%d", &n);
 		vector <int> a(n), b(n);
 		for (int i = 0; i < n; ++i)
 			scanf("%d", &a[i]);
 		for (int i = 0; i < n; ++i)
 			scanf("%d", &b[i]);
 
 	    vector < vector<int> > prev(n);
 	    vector <int> last(n);
 		for (int i = 0; i < n; ++i)
 			for (int j = i + 1; j < n; ++j)
 			{
 				if (b[j] + 1 == b[i] || b[j] == b[i])
 					prev[j].push_back(i);
 				if (b[j] + 1 == b[i])
 					last[i] = j;
 			}
 
 		vector <int> ans(n);
 		vector <bool> used(n, false);
 		vector <int> curB(n, 1);
 		if (!brute(0, ans, a, b, used, prev, curB, last))
 			throw 42;
 
 	    checkAnswer(a, b, ans);
 	    	
 	    for (int i = 0; i < n; ++i)
 	    	printf(" %d", ans[i] + 1);
 	    printf("\n");
 	    fflush(stdout);
 	}
 
 	return 0;
 }
