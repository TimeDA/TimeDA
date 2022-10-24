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
 
 using namespace std;
 
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
 
 bool solve2(int n, vector <pii> v)
 {
 	int inHouse = 0;
 	vector <int> st(3000, -1);
 	vector <int> enteredInMask;
 	bool imp = false;
 	for (int i = 0; i < n; ++i)
 	{
 		int type = v[i].first;
 		int id = v[i].second;
 		dbg("%c %d\n", type == 0 ? 'L' : 'E', id);
 		if (type == 1)
 		{
 			if (id == 0)
 			{
 				enteredInMask.push_back(i);
 				inHouse++;
 			}
 			else
 			{
 				if (st[id] == 1)
 				{
 					imp = true;
 //					dbg("crash on i = %d\n", i);
 //					throw 42;
 				}
 				st[id] = 1;
 				inHouse++;
 			}
 		}
 		else if (type == 0)
 		{
 			if (id == 0)
 			{
 				if (!enteredInMask.empty())
 				{
 					enteredInMask.pop_back();
 					--inHouse;
 				}
 			}
 			else
 			{
 				if (st[id] == 0)
 				{
 					imp = true;
 //					dbg("crash on i = %d\n", i);
 //					throw 42;
 				}
 				if (st[id] != -1)
 					--inHouse;
 				st[id] = 0;
 			}
 		}
 		else
 			throw 42;
 	}
 	if (imp)
 	{
 		printf("CRIME TIME\n");
 		return true;
 	}
 
 	printf("%d\n", inHouse);
 	return false;
 }
 
 bool dfs(const vector < vector <int> > & ed, vector <int> & match, vector <int> & used, int TIME, int s)
 {
 	if (used[s] == TIME)
 		return false;
 	used[s] = TIME;
 	for (int i = 0; i  < int(ed[s].size()); ++i)
 	{
 		int v = ed[s][i];
 		if (match[v] == -1 || dfs(ed, match, used, TIME, match[v]))
 		{
 			match[v] = s;
 			return true;
 		}
 	}
 	return false;
 }
 
 void add(int n, vector <pii> & v)
 {
 	vector <pair<int, pii> > seg;
 	for (int i = 0; i < n; ++i)
 	{
 		if (v[i].first == 1 && v[i].second != 0)
 		{
 			int j = i + 1;
 			while (j < n && v[j].second != v[i].second)
 				++j;
 			if (j == n || v[j].first == 1)
 				continue;
 			seg.push_back(make_pair(j, pii(i, j)));
 		}
 	}
 	sort(seg.begin(), seg.end());
 	for (int i = 0; i < int(seg.size()); ++i)
 	{
 		int L = seg[i].second.first;
 		int R = seg[i].second.second;
 		int l0 = -1;
 		for (int j = L + 1; j < R; ++j)
 		{
 			if (l0 == -1)
 			{
 				if (v[j] == pii(0, 0))
 				{
 					l0 = j;
 				}
 			}
 			else
 			{
 				if (v[j] == pii(1, 0))
 				{
 					v[l0].second = v[L].second;
 					v[j].second = v[L].second;
 					l0 = -1;
 				}
 			}
 		}
 	}
 }
 
 void solve()
 {
 	int n;
 	scanf("%d", &n);
 	vector <pii> v(n);
 	for (int i = 0; i < n; ++i)
 	{
 		char ch;
 		int id;
 		scanf(" %c %d", &ch, &id);
 		dbg("%c %d\n", ch, id);
 		v[i] = pii((ch == 'E') ? 1 : 0, id);
 	}
 
 	vector < vector <int> > ed(n);
 	for (int i = 0; i < n; ++i)
 	{
 		int type = v[i].first;
 		int id = v[i].second;
 		if (type == 1)
 		{
 			if (id != 0)
 			{
 				int j = i + 1;
 				while (j < n && v[j].second != id)
 					++j;
 				if (j < n && v[j].first == 0)
 					continue;
 				for (int k = i + 1; k < j && k < n; ++k)
 					if (v[k].first == 0 && v[k].second == 0)
 					{
 						ed[i].push_back(k);
 						dbg("%d -> %d\n", i, k);
 					}
 			}
 		}
 		else if (type == 0)
 		{
 			if (id != 0)
 			{
 				int j = i - 1;
 				while (j >= 0 && v[j].second != id)
 					--j;
 				if (j >= 0 && v[j].first == 1)
 					continue;
 				for (int k = i - 1; k > j && k >= 0; --k)
 					if (v[k].first == 1 && v[k].second == 0)
 					{
 						ed[k].push_back(i);
 						dbg("%d -> %d\n", k, i);
 					}
 			}
 		}
 		else
 			throw 42;
 	}
 
 	vector <int> match(n, -1);
 	vector <int> used(n, 0);
 	int TIME = 1;
 	for (int i = 0; i < n; ++i)
 		if (v[i].first == 1)
 		{
 			++TIME;
 			dfs(ed, match, used, TIME, i);
 		}
 	for (int i = 0; i < n; ++i)
 		if (match[i] != -1)
 		{
 			dbg("%d <-> %d\n", match[i], i);
 			if (v[i].second == 0)
 				v[i].second = v[match[i]].second;
 			else
 				v[match[i]].second = v[i].second;
 		}
 
 	add(n, v);
 	solve2(n, v);
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
 		printf("Case #%d: ", ii);
 		dbg("Case #%d:\n", ii);
 		solve();
 		fflush(stdout);
 	}
 
 	return 0;
 }
