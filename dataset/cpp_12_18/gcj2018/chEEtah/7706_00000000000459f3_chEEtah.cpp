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

int d[64][512][512];
int len[512];

int calc(int k, int R, int B)
{
    if (k == 0)
    {
        return len[R] + len[B] - 1;
    }

    if (R > B) swap(R, B);

    int &res = d[k][R][B];
    if (res != -1) return res;

    res = 0;

    int sr = 0;
    for(int nr = k; ; nr++)
    {
        sr += nr;
        if (sr > R) break;
        int sb = k * (nr - k);
        for(int nb = k; ; nb++)
        {
            int sr2 = sr + k * (nb - k);
            if (sr2 > R) break;
            sb += nb;
            if (sb > B) break;

            int cur = calc(k - 1, R - sr2, B - sb) + (nr - k + 1) + (nb - k + 1) - 1;
            res = max(res, cur);
        }
    }

    // printf("%d %d %d -> %d\n", k, R, B, res);

    return res;
}

int main()
{
    for(int i = 0; i < 512; i++)
    {
        int left = i;
        int cnt = 0;
        while(1)
        {
            left -= cnt;
            if (left < 0) break;
            cnt++;
        }
        len[i] = cnt;
    }

    memset(d, -1, sizeof d);
	int R, B;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		printf("Case #%d: ", tt);

		scanf("%d %d", &R, &B);

        int res = 0;
        for(int k = 0; k < 64; k++) res = max(res, calc(k, R, B));
        printf("%d\n", res - 1);
	}
	return 0;
}