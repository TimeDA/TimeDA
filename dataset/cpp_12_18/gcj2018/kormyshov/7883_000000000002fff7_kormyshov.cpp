#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
using namespace std;

vector<int> w, h;

map<int, double> mp[101];

double rec(int i, int p)
{
    if (i < 0)
    {
        if (p < 0) return -1e9;
        return 0;
    }
    if (mp[i].count(p)) return mp[i][p];
    double res = rec(i - 1, p);
    if (h[i] * 2 <= p)
    {
        double a = rec(i - 1, p - h[i] * 2) + 2 * sqrt(.0 + w[i] * w[i] + h[i] * h[i]);
        if (a > res) res = a;
    }
    if (res > p) res = p;
    return (mp[i][p] = res);
}

void solve2()
{
    int n, p;
    cin >> n >> p;
    w.assign(n, 0);
    h.assign(n, 0);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i] >> h[i];
        if (w[i] < h[i]) swap(w[i], h[i]);
        sum += 2 * (w[i] + h[i]);
        mp[i].clear();
    }
    p -= sum;
    printf("%.9f", rec(n - 1, p) + sum);
}

void solve()
{
    int n, p;
    cin >> n >> p;
    int w, h;
    for (int i = 0; i < n; ++i)
    {
        cin >> w >> h;
    }
    if (w < h) swap(w, h);

    double sum = 2 * (w + h) * n;
    double res = sum;

    for (int i = 0; i <= n; ++i)
    {
        double s = sum + i * 2 * h;
        if (s > p) break;
        s = sum + i * 2 * sqrt(.0 + w * w + h * h);
        if (s > p) s = p;
        if (s > res) res = s;
    }
    printf("%.9f", res);
}

int main() {
    int t;
    cin >> t;
    for (int ii = 1; ii <= t; ++ii)
    {
        printf("Case #%d: ", ii);
        solve2();
        printf("\n");
    }
    return 0;
}