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

int nt, n, D;

char s[20][20];
int a[1000];
int p[1000];
int used[1000];

int main()
{
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
        memset(p, 0, sizeof p);
        memset(used, 0, sizeof used);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &D);
            for(int j = 0; j < D; j++)
            {
                scanf("%d", &a[j]);
                p[a[j]]++;
            }
            int selected = -1;
            for(int j = 0; j < D; j++)
            if (!used[a[j]])
                if (selected == -1 || p[selected] > p[a[j]]) selected = a[j];

            printf("%d\n", selected); fflush(stdout);
            if (selected != -1) used[selected] = 1;
        }
	}
	return 0;
}