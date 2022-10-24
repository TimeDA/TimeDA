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

char s[20][20];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
        memset(s, 0, sizeof s);
        // int cnt = 0;
        int A;
        scanf("%d", &A);
        while(1)
        {
            int x = -1, y;
            for(int i = 1; i <= 15 && x == -1; i++)
            for(int j = 1; j <= 14 && x == -1; j++)
                if (!s[i][j]) { x = i; y = j; }

            if (x == -1) break;

            if (x == 1) x = 2;
            if (x == 15) x = 14;
            if (y == 1) y = 2;
            if (y == 14) y = 13;

            printf("%d %d\n", x, y); fflush(stdout);
            // cnt++;
            // int dx = rand() % 3 - 1;
            // int dy = rand() % 3 - 1;
            // s[x + dx][y + dy] = 1;

            scanf("%d %d", &x, &y);
            if (!x && !y) break;
            s[x][y] = 1;
        }
        // printf("%d\n", cnt);
	}
	return 0;
}