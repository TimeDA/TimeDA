#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& e : v) cin >> e;
    if (!v[0] || !v[n - 1])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> f(n, -1);
    int mx = 1;
    for (int i = 0, j = 0; i < n; ++i)
    {
        if (v[i])
        {
            for (int k = 0; k < v[i]; ++k)
            {
                f[j] = i;
                if (mx < abs(j - i) + 1) mx = abs(j - i) + 1;
                ++j;
            }
        }
    }
    char res[100][109];
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 109; ++j) res[i][j] = '.';
        res[i][n] = '\0';
    }
    for (int i = 0; i < n; ++i)
    {
        if (f[i] != i)
        {
            if (f[i] > i)
            {
                for (int j = i, k = 0; j < f[i]; ++j, ++k) res[k][j] = '\\';
            }
            else
            {
                for (int j = i, k = 0; j > f[i]; --j, ++k) res[k][j] = '/';
            }
        }
    }
    cout << mx << endl;
    for (int i = 0; i < mx; ++i) cout << res[i] << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        //cout << endl;
    }
    return 0;
}
