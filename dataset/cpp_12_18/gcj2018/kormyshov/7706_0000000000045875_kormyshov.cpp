#include <iostream>
#include <memory.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int mm[5][5];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mm[i][j];
        }
    }
    int res = n * n;
    int cc[5][5];
    for (int i = 0; i < (1LL << (n*n)); ++i)
    {
        int cnt = 0;
        int a = i;
        while (a)
        {
            ++cnt;
            a &= a - 1;
        }
        if (cnt >= res) continue;

        memcpy(cc, mm, sizeof(cc));
        for (int j = 0; j < n*n; ++j)
        {
            if (i >> j & 1)
            {
                cc[j / n][j % n] = 0;
            }
        }

        bool f = false;
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (cc[j][k])
        {
            for (int q = 0; q < n; ++q)
            {
                if (q == j) continue;
                if (cc[j][k] == cc[q][k]) f = true;
            }
            for (int q = 0; q < n; ++q)
            {
                if (q == k) continue;
                if (cc[j][k] == cc[j][q]) f = true;
            }
        }
        if (!f) res = cnt;
    }
    cout << res;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i<= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
