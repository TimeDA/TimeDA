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

int nt, N, L;

long long w[100001];
long long a[100001];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		printf("Case #%d: ", tt);

		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &w[i]);
        a[0] = 0;
        int m = 1;
        for(int i = 1; i <= N; i++)
        {
            long long cur = w[i] * 6;
            int L = 0, R = m;
            while(L != R - 1)
            {
                int k = (L + R) / 2;
                if (a[k] <= cur) L = k; else R = k;
            }
            if (L == m - 1) { a[m] = a[m - 1] + w[i] + 1; m++; }
            while(L >= 0)
            {
                if (a[L + 1] > a[L] + w[i]) a[L + 1] = a[L] + w[i];
                L--;
            }
        }
		printf("%d\n", m - 1);
	}
	return 0;
}