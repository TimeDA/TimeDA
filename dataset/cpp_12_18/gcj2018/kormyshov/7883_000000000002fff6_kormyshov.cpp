#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long max(long long a, long long b)
{
    return (a > b ? a : b);
}

void solve()
{
    long long r, b, c;
    cin >> r >> b >> c;
    vector<long long> m(c), s(c), p(c);
    for (int i = 0; i < c; ++i)
    {
        cin >> m[i] >> s[i] >> p[i];
    }
    long long L = 0, R = 1000000000LL * 1000000000LL + 2000000000LL;
    while (L < R)
    {
        long long mid = (L + R) / 2;

        vector<long long> v;
        for (int i = 0; i < c; ++i)
        {
            long long a = max(0, min(m[i], (mid - p[i]) / s[i]));
            v.push_back(a);
        }
        sort(v.rbegin(), v.rend());
        bool f = false;
        long long sum = 0;
        for (int i = 0; i < r; ++i)
        {
            sum += v[i];
            if (sum >= b) f = true;
        }

        if (!f) L = mid + 1;
        else R = mid;
    }
    cout << L;
}

int main() {
int t;
cin >> t;
for (int ii = 1; ii <= t; ++ii)
{
    cout << "Case #" << ii << ": ";
    solve();
    cout << endl;
}
    return 0;
}