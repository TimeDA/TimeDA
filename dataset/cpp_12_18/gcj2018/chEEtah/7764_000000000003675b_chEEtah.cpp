#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt, n;
int a[100000];
int b[100000];
int d[100000];
const int wildcard = 1000000000;

struct S
{
	int M, N;
	set<int> sM, sN;
	bool operator<(const S &x) const
	{
		if (M != x.M) return M < x.M;
		if (N != x.N) return N < x.N;
		if (sM != x.sM) return sM < x.sM;
		return sN < x.sN;
	}
};

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		printf("Case #%d: ", tt);

		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d %d %d", &d[i], &a[i], &b[i]);

		int best = 0, bestCount = 0;
		set<S> s;
		S empty;
		empty.N = empty.M = wildcard;
		s.insert(empty);
		int L = 0, R = 0;
		while(L < n)
		{
			assert(s.size() > 0);
			set<S> newS;
			set<S>::iterator p = s.begin(), q = s.end();
			// printf("%d %d\n", L, R);
			// while(p != q)
			// {
			// 	printf("| %d %d\n", p->M, p->N);
			// 	p++;
			// }
			// p = s.begin(); q = s.end();
			// try grow using R
			if (R < n)
			{
				while(p != q)
				{
					// try M
					S si = *p;
					if (si.M == wildcard || si.M == d[R] + a[R])
					{
						si.M = d[R] + a[R];
						si.sM.insert(R);
						if (si.N == d[R] - b[R]) si.sN.insert(R);
						newS.insert(si);
					}
					// try N
					si = *p;
					if (si.N == wildcard || si.N == d[R] - b[R])
					{
						si.N = d[R] - b[R];
						si.sN.insert(R);
						if (si.M == d[R] + a[R]) si.sM.insert(R);
						newS.insert(si);
					}
					// try N and M
					si = *p;
					if (si.M == wildcard || si.M == d[R] + a[R])
					if (si.N == wildcard || si.N == d[R] - b[R])
					{
						si.M = d[R] + a[R];
						si.N = d[R] - b[R];
						si.sM.insert(R);
						si.sN.insert(R);
						newS.insert(si);
					}
					p++;
				}

				if (newS.size() > 0)
				{
					R++; s = newS;
					if (best == R - L) bestCount++;
					else
					if (best < R - L) { best = R - L; bestCount = 1; }
					continue;
				}
			}

			// shrink using L
			p = s.begin(); q = s.end();
			while(p != q)
			{
				S si = *p;
				si.sM.erase(L);
				si.sN.erase(L);
				if (si.sM.size() == 0) si.M = wildcard;
				if (si.sN.size() == 0) si.N = wildcard;
				newS.insert(si);
				// wildcard N
				S t = si;
				if (si.sM.size() == R - L - 1)
				{
					t.N = wildcard;
					t.sN.clear();
					newS.insert(t);
				}
				// wildcard M
				t = si;
				if (si.sN.size() == R - L - 1)
				{
					t.M = wildcard;
					t.sM.clear();
					newS.insert(t);
				}
				p++;
			}
			L++;
			s = newS;
		}

		printf("%d %d\n", best, bestCount);
	}
	return 0;
}