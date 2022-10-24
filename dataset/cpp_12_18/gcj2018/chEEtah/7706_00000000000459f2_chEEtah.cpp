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

int nt, N;
int a[100];
int need[100];
int p[100];
int q[100];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		printf("Case #%d: ", tt);

		scanf("%d", &N);
		for(int i = 0; i < N; i++) { scanf("%d", &a[i]); need[i] = a[i]; }

		int k = 0;
		int res = 0;
		for(int i = 0; i < N; i++)
		{
			while(!need[k]) k++;
			p[i] = k;
			res = max(res, abs(p[i] - i));
			need[k]--;
		}

		if (p[0] != 0 || p[N - 1] != N - 1) { puts("IMPOSSIBLE"); continue; }

		printf("%d\n", res + 1);
		while(1)
		{
			bool done = true;
			for(int i = 0; i < N; i++) if (p[i] != i) done = false;
			if (done) break;

			for(int i = 0; i < N; i++) q[i] = i;

			for(int i = 0; i < N; i++)
			if (p[i] > i) { printf("\\"); q[i + 1] = p[i]; }
			else
			if (p[i] < i) { printf("/"); q[i - 1] = p[i]; }
			else
			printf(".");

			puts("");
			for(int i = 0; i < N; i++) p[i] = q[i];
		}

		for(int i = 0; i < N; i++) printf("."); puts("");
	}
	return 0;
}