#include <iostream>
#include <memory.h>
#include <vector>
#include <ctime>
using namespace std;

bool solve2(int n, int m, int h, int v, char ss[101][101])
{
    int sum = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (ss[i][j] == '@') sum++;
    if (!sum) return true;
    if (sum % 4) return false;
    sum /= 4;
    for (int i = 0; i < n - 1; ++i) for (int j = 0; j < m - 1; ++j)
        {
            int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
            for (int ii = 0; ii <= i; ++ii) for (int jj = 0; jj <= j; ++jj) if (ss[ii][jj] == '@') s1++;
            for (int ii = 0; ii <= i; ++ii) for (int jj = j+1; jj < m; ++jj) if (ss[ii][jj] == '@') s2++;
            for (int ii = i+1; ii <n; ++ii) for (int jj = 0; jj <= j; ++jj) if (ss[ii][jj] == '@') s3++;
            for (int ii = i+1; ii <n; ++ii) for (int jj = j+1; jj <m; ++jj) if (ss[ii][jj] == '@') s4++;
            if (s1 == sum && s2 == sum && s3 == sum && s4 == sum) return true;
        }
    return false;
}

bool solve(int n, int m, int h, int v, char ss[101][101])
{
    int mm[101][101];
    memset(mm, 0, sizeof(mm));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (ss[i][j] == '@') mm[i][j] = 1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            mm[i][j] += (i ? mm[i - 1][j] : 0) + (j ? mm[i][j - 1] : 0) - (i && j ? mm[i - 1][j - 1] : 0);
        }
    }
    int sum = mm[n - 1][m - 1];
    //cout << "sum = " << sum << endl;
    if (sum % ((h + 1) * (v + 1))) return false;
    if (!sum) return true;
    int sum1 = sum / (h + 1);
    vector<int> a;
    int c = 1;
    for (int i = 0; i < n; ++i)
    {
        if (mm[i][m - 1] == c * sum1) a.push_back(i), ++c;
    }
    if (a.size() != h + 1) return false;

    int sum2 = sum1 / (v + 1);
    for (c = 1; c <= v + 1; ++c)
    {
        //cout << "c = " << c << endl;
        vector<int> b;
        for (int j = 0; j < m; ++j)
        {
            if (mm[a[0]][j] == c * sum2) b.push_back(j);
        }

        //cout << "b :";
        //for (int e : b) cout << e << " ";
        //cout << endl;

        bool ff = false;

        for (int e : b)
        {
            bool f = true;
            for (int i = 0; i < a.size(); ++i)
            {
                //cout << i << " " << a[i] << " " << mm[a[i]][e] << " " << c * sum2 * (i + 1) << endl;
                if (mm[a[i]][e] != c * sum2 * (i + 1))
                {
                    f = false;
                    break;
                }
            }
            //cout << "f = " << f << endl;
            if (f)
            {
                ff = true;
                break;
            }
        }

        if (!ff) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int ii = 1; ii <= t; ++ii)
    {
        int n, m, h, v;
        cin >> n >> m >> h >> v;
        char ss[101][101];
        for (int i = 0; i < n; ++i) {
            cin >> ss[i];
        }

        cout << "Case #" << ii << ": ";
        cout << (solve(n, m, h, v, ss) ? "POSSIBLE" : "IMPOSSIBLE");
        cout << endl;
    }
/*
    int n = 10, m = 10, h = 1, v = 1;
    char ss[101][101];
    srand(time(0));
    for (int ii = 0; ii < 100; ++ii)
    {
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ss[i][j] = '.';
        int c = rand() % 13;
        for (int i = 0; i < c; ++i)
        {
            ss[rand() % n][rand() % m] = '@';
        }
        if (solve(n, m, h, v, ss) != solve2(n, m, h, v, ss))
        {
            cout << "ERROR!!!" << endl;
            cout << solve2(n, m, h, v, ss) << " " << solve(n, m, h, v, ss) << endl;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j) cout << ss[i][j];
                cout << endl;
            }
        }
    }
     */
    return 0;
}