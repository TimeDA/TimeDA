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

int nt;

int a[100000];
int b[100000];
int c[100000];

int n;
int na, nb;

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		printf("Case #%d: ", tt);
        scanf("%d", &n);
        na = nb = 0;
        for(int i = 0; i < n; i++)
        if (i % 2 == 0) scanf("%d", &a[na++]); else scanf("%d", &b[nb++]);

        sort(a, a + na);
        sort(b, b + nb);

        na = nb = 0;
        for(int i = 0; i < n; i++)
        if (i % 2 == 0) c[i] = a[na++]; else c[i] = b[nb++];

        int res = -1;
        for(int i = 0; i < n - 1; i++) if (c[i] > c[i + 1]) { res = i; break; }
        if (res == -1) puts("OK"); else printf("%d\n", res);
	}
	return 0;
}