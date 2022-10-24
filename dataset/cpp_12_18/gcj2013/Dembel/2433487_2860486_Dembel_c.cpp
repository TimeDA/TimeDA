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
 
 struct Dist {
 	int minD, maxD;
 
 	Dist(int minD, int maxD) : minD(minD), maxD(maxD) {}
 
 	Dist operator + (const Dist & d) const
 	{
 		return Dist(minD + d.minD, maxD + d.maxD);
 	}
 };
 
 struct Edge {
 public:	
 	int u, v;
 private:
 	int a, b;
 public:
 	int w;
 	Edge(int u, int v, int a, int b) : u(u), v(v), a(a), b(b), w(b) {}
 
 	void setShort()
 	{
 		w = a;
 	}
 
 	void setLong()
 	{
 		w = b;
 	}
 
 	void print() const
 	{
 		dbg("%d -> %d, [%d, %d]\n", u, v, w);
 	}
 };
 
 const int INF = 1 << 30;
 
 vector <int> findDist(int s, vector<Edge>&edges, vector<vector<int> > & ed)
 {
 	int n = int(ed.size());
 	vector <int> d(n, INF);
 	vector <bool> used(n, false);
 	d[s] = 0;
 	for (int i = 0; i < n; ++i)
 	{
 		int v = -1;
 		for (int j = 0; j < n; ++j)
 			if (!used[j] && (v == -1 || d[v] > d[j]))
 				 v = j;
 		dbg("d[%d] = %d\n", v, d[v]);
 		used[v] = true;
 		for (int j = 0; j < int(ed[v].size()); ++j)
 		{
 			Edge& e = edges[ed[v][j]];
 			int u = e.u != v ? e.u : e.v;
 			int w = e.w;
 			if (d[u] > d[v] + w)
 			{
 				d[u] = d[v] + w;
 			}
 		}
 	}
 	return d;
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
 		int n, m, p;
 		scanf("%d%d%d", &n, &m, &p);
 		vector <vector <int> > ed(n);
 		vector <vector <int> > revEd(n);
 		vector <Edge> edges;
 		for (int i = 0; i < m; ++i)
 		{
 			int u, v, a, b;
 			scanf("%d%d%d%d", &u, &v, &a, &b);
 			--u, --v;
 			ed[u].push_back(edges.size());
 			revEd[v].push_back(edges.size());
 			edges.push_back(Edge(u, v, a, b));
 		}
 		vector <int> path(p);
 		for (int i = 0; i < p; ++i)
 		{
 			scanf("%d", &path[i]);
 			--path[i];
 //			edges[path[i]].setShort();
 		}
 
 		for (int i = 0; i < m; ++i)
 			edges[i].setShort();
 		vector<int> minD = findDist(1, edges, revEd);
 		for (int i = 0; i < m; ++i)
 			edges[i].setLong();
 
 		for (int i = 0; i < p; ++i)
 			edges[path[i]].setShort();
 
 		int ans = -1;
 		int curD = 0;
 		for (int i = 0; i < int(path.size()); ++i)
 		{
 			Edge & e = edges[path[i]];
 			e.setShort();
 			curD += e.w;
 			vector<int> maxD1 = findDist(1, edges, revEd);
 			vector<int> maxD0 = findDist(0, edges, ed);
 			if (maxD0[e.v] != curD || minD[e.v] + curD > maxD1[0])
 			{
 				ans = i;
 				break;
 			}
 		}
 		if (ans == -1)
 			printf("Looks Good To Me\n");
 		else
 			printf("%d\n", path[ans] + 1);
 		fflush(stdout);
 	}
 
 	return 0;
 }
