#include <iostream>
#include <string>
using namespace std;

bool check(string s)
{
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == 'S' && s[i - 1] == 'C') return true;
    }
    return false;
}

long long fire(string s)
{
    long long cur = 1;
    long long sum = 0;
    for (char c : s)
    {
        if (c == 'C') cur <<= 1;
        else sum += cur;
    }
    return sum;
}

void solve()
{
    int d;
    string s;
    cin >> d >> s;
    int res = 0;
    while (check(s) && fire(s) > d)
    {
        ++res;
        for (int i = s.size() - 1; i > 0; --i)
        {
            if (s[i] == 'S' && s[i - 1] == 'C')
            {
                swap(s[i], s[i - 1]);
                break;
            }
        }
    }
    if (fire(s) > d) cout << "IMPOSSIBLE";
    else cout << res;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}