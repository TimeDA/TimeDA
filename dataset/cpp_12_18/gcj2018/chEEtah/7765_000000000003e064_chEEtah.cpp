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
char s[2000][11];

set<string> S;

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		printf("Case #%d: ", tt);

		scanf("%d %d", &N, &L);
		S.clear();
		for(int i = 0; i < N; i++) { scanf("%s", s[i]); S.insert(s[i]); }

		bool ok = false;
		for(int i = 0; i < N && !ok; i++)
		for(int j = 0; j < N && !ok; j++)
		{
			string res = s[i];
			for(int k = 0; k < L && !ok; k++)
			{
				res[k] = s[j][k];
				if (!S.count(res))
				{
					printf("%s\n", res.c_str());
					ok = true;
				}
			}
		}

		if (!ok) printf("-\n");
	}
	return 0;
}