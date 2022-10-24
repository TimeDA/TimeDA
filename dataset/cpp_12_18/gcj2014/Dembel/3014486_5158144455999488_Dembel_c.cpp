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
 
 struct Flow {
 	int L, R;
 
 	Flow(int L, int R) : L(L), R(R) {}
 
 	bool operator != (const Flow & f) const
 	{
 		return L != f.L || R != f.R;
 	}
 };
 
 struct Event {
 	int type;
 	int y, x1, x2;
 
 	Event(int type, int y, int x1, int x2) : type(type), y(y), x1(x1), x2(x2) {}
 
 	bool operator < (const Event & e) const
 	{
 		if (y != e.y)
 			return y < e.y;
 	   	if (type != e.type)
 	   		return type < e.type;
 	}
 };
 
 struct RangeTree {
 	vector <int> sum;
 	int kk;
 	int n;
 public:
 	RangeTree(int _n)
 	{
 		n = _n;
 		kk = 1;
 		while (kk <= n)
 			kk *= 2;
 		sum.assign(2 * kk + 10, 0);
 	}
 
 	void add(int x, int delta)
 	{
 		x += kk;
 		sum[x] += delta;
 		while (x > 1)
 		{
 			x /= 2;
 			sum[x] = sum[x * 2] + sum[2 * x + 1];
 		}
 	}
 
 	int getSum(int L, int R)
 	{
 		L += kk, R += kk;
 		int res = 0;
 		while (L <= R)
 		{
 			if (L % 2 == 1)
 			{
 				res += sum[L];
 				++L;
 			}
 			if (R % 2 == 0)
 			{
 				res += sum[R];
 				--R;
 			}
 			L /= 2;
 			R /= 2;                                             	
 		}
 		return res;
 	}
 
 	int moveToLeft(int cur, int maxL)
 	{
 		int sum = getSum(0, cur);
 		return max(maxL, min(cur, getMinPrefix(1, 0, n - 1, sum) + 1));
 	}
 
 	int moveToRight(int cur, int maxR)
 	{
 		int sum = getSum(cur, n - 1);
 		return min(maxR, max(cur, getMinSuffix(1, 0, n - 1, sum) - 1));
 	}
 
 	int moveToRight1(int cur)
 	{
 		int left = cur;
 		int right = n - 1;
 		while (left < right)
 		{
 			int middle = (left + right) / 2;
 			if (getSum(cur, middle) != middle - cur + 1)
 				right = middle;
 			else
 				left = middle + 1;
 		}
 		return left;
 	}
 
 	int moveToLeft1(int cur)
 	{
 		int left = 0;
 		int right = cur;
 		while (left < right)
 		{
 			int middle = (left + right + 1) / 2;
 			if (getSum(middle, cur) != cur - middle + 1)
 				left = middle;
 			else
 				right = middle - 1;
 		}
 		return left;
 	}
 private:
 	int getMinPrefix(int t, int L, int R, int minSum)
 	{
 		if (L == R)
 			return L;
 	    if (sum[2 * t] < minSum)
 	    	return getMinPrefix(2 * t + 1, (L + R) / 2 + 1, R, minSum - sum[2 * t]);
 	    else
 	    	return getMinPrefix(2 * t, L, (L + R) / 2, minSum);
 	}
 
 	int getMinSuffix(int t, int L, int R, int minSum)
 	{
 		if (L == R)
 			return L;
 	    if (sum[2 * t + 1] < minSum)
 	    	return getMinSuffix(2 * t, L, (L + R) / 2, minSum - sum[2 * t + 1]);
 	    else
 	    	return getMinSuffix(2 * t + 1, (L + R) / 2 + 1, R, minSum);
 	}
 };
 
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
 		int w, h, n;
 		scanf("%d%d%d", &w, &h, &n);
 		vector <Event> events;
 		for (int i = 0; i < n; ++i)
 		{
 			int x0, y0, x1, y1;
 			scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
 			events.push_back(Event(1, y0, x0, x1));
 			events.push_back(Event(-1, y1 + 1, x0, x1));
 		}
 		events.push_back(Event(1, h + 2, 0, -1));
 		sort(events.begin(), events.end());
 
 		RangeTree row(w);
 		vector <Flow> flows;
 		vector <Flow> newFlows;
 		for (int i = 0; i < w; ++i)
 			flows.push_back(Flow(i, i));
 		int curY = -1;
 		bool canMove = false;
 		for (int i = 0; i < int(events.size()); ++i)
 		{
 			if (flows.empty())
 				break;
 /*			dbg("i = %d, curY = %d\n", i, curY);
 			for (int j = 0; j < int(flows.size()); ++j)
 				dbg("[%d, %d], ", flows[j].L, flows[j].R);
 			dbg("\n");
 			for (int j = 0; j < w; ++j)
 				dbg("%d", row.getSum(j, j));
 			dbg("\n");
 			dbg("moveToRight(1, 2) = %d\n", row.moveToRight(1, 2));*/
 
 			Event & ev = events[i];
 			dbg("start move\n");
 			while (curY + 1 < ev.y)
 			{
 				bool changed = false;
 				newFlows.clear();
 				for (int i = 0; i < int(flows.size()); ++i)
 				{
 					newFlows.push_back(flows[i]);
 					newFlows[i].L = row.moveToLeft(flows[i].L, (i == 0) ? 0 : flows[i - 1].L + 1);
 					newFlows[i].R = row.moveToRight(flows[i].R, (i == int(flows.size()) - 1) ? w - 1 : flows[i + 1].R - 1);
 					changed |= newFlows[i] != flows[i];
 				}
 				dbg("move curY = %d\n", curY);
 				flows.swap(newFlows);
 				if (!changed)
 					curY = ev.y - 1;
 				else
 					++curY;
 			}
 			dbg("end Move\n");
 			if (ev.type == 1)
 			{
 				for (int x = ev.x1; x <= ev.x2; ++x)
 					row.add(x, 1);
 				newFlows.clear();
 				dbg("start kill\n");
 				for (int j = 0; j < int(flows.size()); ++j)
 					if (row.getSum(flows[j].L, flows[j].R) != flows[j].R - flows[j].L + 1)
 					{
 						newFlows.push_back(flows[j]);
 						newFlows.back().L = row.moveToRight1(newFlows.back().L);
 						newFlows.back().R = row.moveToLeft1(newFlows.back().R);
 					}
 				dbg("end kill\n");
 				newFlows.swap(flows);
 			}
 			else if (ev.type == -1)
 			{
 				for (int x = ev.x1; x <= ev.x2; ++x)
 					row.add(x, -1);
 			}
 		}
 		printf("%d\n", (int)flows.size());
 	}
 
 	return 0;
 }
