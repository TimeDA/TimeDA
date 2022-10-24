#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

typedef pair<int, int> ii;

void initialize()
{
    freopen("_.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

int calc(int value, int n)
{
    int c = value * 100 / n;
    int d = value * 100 - c * n;
    if (d * 2 >= n) {
        c += 1;
    }
    return c;
}

int solve_dp(int n, const vector<int>& counts)
{
    int sum = 0;
    for (int i = 0; i < counts.size(); ++i) {
        sum += counts[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1000000));
    dp[0][n - sum] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int num = 0;
            if (i <= counts.size()) {
                num = counts[i - 1];
            }
            for (int k = 0; j + k <= n; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + k] + calc(num + k, n));
            }
            //cerr << i << " " << j << ": " << dp[i][j] << endl;
        }
    }
    
    int res = 0;
    for (int i = 0; i <= n; ++i) {
        res = max(res, dp[i][0]);
    }

    return res;
}

int solve_greedy(int n, vector<int> counts)
{
    vector<int> minNum;
    for (int i = 0; i < counts.size(); ++i) {
        int num = counts[i] * 100 / n;
        int d = counts[i] * 100 - num * n;
        if (d * 2 >= n) {
            minNum.pb(0);
        } else {
            minNum.pb(1 + (n - 2 * d - 1) / 200);
        }
    }

    for (int i = counts.size(); i < n; ++i) {
        minNum.pb(1 + ((n - 1) / 200));
        counts.pb(0);
    }

    vector<ii> pairs;
    for (int i = 0; i < n; ++i) {
        pairs.pb(ii(minNum[i], counts[i]));
    }
    
    int sum = 0;
    for (int i = 0; i < counts.size(); ++i) {
        sum += counts[i];
    }
    sum = n - sum;

    int res = 0;
        
    sort(all(pairs));

    for (int i = 0; i < pairs.size(); ++i) {
        int d = min(sum, pairs[i].first);
        sum -= d;
        int add = calc(pairs[i].second + d, n);
        res += add;
    }
    return res;
}

int main()
{
    //initialize();

    int T;
    cin >> T;
    
    for (int tt = 1; tt <= T; ++tt) {
        int n, l;
        cin >> n >> l;

        cerr << n << " " << l << endl;

        vector<int> counts(l);
        for (int i = 0; i < l; ++i) {
            cin >> counts[i];
        }

        int res = 0;
        if (n <= 300) {
            res = solve_dp(n, counts);
        } else {
            res = solve_greedy(n, counts);
        }

        cout << "Case #" << tt << ": " << res << "\n";
    }
    
    return 0;
}
