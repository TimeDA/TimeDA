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

int nt, D;
char s[100];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		printf("Case #%d: ", tt);

		scanf("%d %s", &D, s);

		int n = strlen(s);
		int res = 0, damage, cur;
		while(1)
		{
			damage = 0; cur = 1;
			int i;
			for(i = 0; i < n; i++) if (s[i] == 'C') cur *= 2; else damage += cur;
			if (damage <= D) break;

			for(i = n - 1; i > 0; i--)
				if (s[i] == 'S' && s[i - 1] == 'C') { swap(s[i], s[i - 1]); break;}
			if (!i) break;
			res++;
		}
		if (damage <= D) printf("%d\n", res); else puts("IMPOSSIBLE");
	}
	return 0;
}