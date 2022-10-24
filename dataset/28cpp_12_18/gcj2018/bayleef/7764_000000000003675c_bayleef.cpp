#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int a[200], b[200];
long long g[200];

struct TT
{
	int i;
	long long diff;
};

bool operator <(TT t1, TT t2)
{
	if (t1.diff != t2.diff)
		return t1.diff > t2.diff;
	return t1.i < t2.i;
}

set<TT>s;
long long req[200];
int hm[200];

int main()
{
	int T;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		int n, i;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
			--a[i];
			--b[i];
		}
		long long sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &g[i]);
			sum += g[i];
		}
		long long l = 0;
		long long r = sum;
		while (l < r)
		{
			long long m = (l + r + 1) / 2;
			TT t;
			s.clear();
			for (i = 1; i < n; i++)
			{
				req[i] = 0;
				t.i = i;
				t.diff = -g[i];
				s.insert(t);
				hm[i] = n;
			}
			t.i = 0;
			t.diff = m - g[0];
			s.insert(t);
			req[0] = m;
			hm[0] = n;
			long long all = m;
			while (all <= sum)
			{
				if (s.begin()->diff <= 0)
					break;
				t = *s.begin();
				s.erase(t);
				i = t.i;
				if (a[i] == i || b[i] == i || !hm[i])
				{
					all = sum + 1;
					break;
				}
				--hm[i];
				t.i = a[i];
				t.diff = req[t.i] - g[t.i];
				s.erase(s.find(t));
				t.diff += req[i] - g[i];
				req[t.i] += req[i] - g[i];
				s.insert(t);

				t.i = b[i];
				t.diff = req[t.i] - g[t.i];
				s.erase(s.find(t));
				t.diff += req[i] - g[i];
				req[t.i] += req[i] - g[i];
				s.insert(t);

				t.i = i;
				t.diff = 0;
				s.insert(t);
				all += req[i] - g[i];				
				req[i] = g[i];
			}
			if (all <= sum)
				l = m;
			else
				r = m - 1;
		}
		printf("Case #%d: %lld\n", ts, l);
	}
	return 0;
}