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
 #define fill(a, b) memset(a b, sizeof(a))
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef std::pair<int,int> pii;
 
 using namespace std;
 
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
 
 const ll MOD = 1000002013;
 
 struct Event {
 	int station;
 	int cnt;
 	int type;
 
 	Event(int station, int cnt, int type) : station(station), cnt(cnt), type(type)
 	{
 	}
 
 	bool operator < (const Event & e) const
 	{
 		if (station != e.station)
 			return station < e.station;
 		return type < e.type;
 	}
 };
 
 ll getCost(ll o, ll e, ll n)
 {
 	if (o == e)
 		return 0;
 	return ((e - o) * (n + (n - (e - o) + 1)) / 2) % MOD;
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
 		int n, m;
 		scanf("%d%d", &n, &m);
 		vector <int> o(m), e(m), p(m);
 
 		ll realCost = 0;
 		vector <Event> events;
 		for (int i = 0; i < m; ++i)
 		{
 			int o, e, p;
 			scanf("%d%d%d", &o, &e, &p);
 			(realCost += ll(p) * getCost(o, e, n)) %= MOD;
 			events.push_back(Event(o, p, 0));
 			events.push_back(Event(e, p, 1));
 		}
 
 		sort(events.begin(), events.end());
 		vector <pii> pool;
 		ll minCost = 0;
 		for (int i = 0; i < int(events.size()); ++i)
 		{
 			if (events[i].type == 0)
 				pool.push_back(pii(events[i].station, events[i].cnt));
 			else
 			{
 				int needCount = events[i].cnt;
 				while (needCount != 0)
 				{
 					pii & curPair = pool.back();
 					int curCnt = min(curPair.second, needCount);
 
 					(minCost += curCnt * getCost(curPair.first, events[i].station, n)) %= MOD;
 
 					curPair.second -= curCnt;
 					needCount -= curCnt;
 					if (curPair.second == 0)
 						pool.pop_back();
 				}
 			}
 		}
 
 		printf("%d\n", int((realCost - minCost + MOD) % MOD));
 	}
 
 	return 0;
 }
