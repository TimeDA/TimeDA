#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef _WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename T1, typename T2> std::ostream& operator<<(std::ostream &out, const pair<T1, T2>& a) { out << "(" << a.first << ", " << a.second << ")"; return out; }
template<typename T> std::ostream& operator<<(std::ostream &out, const vector<T>& a) { out << "[" << a.size() << "]{ "; forn(i, a.size()) { out << a[i] << " "; } out << "}"; return out; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;

void solve() {
    string s;
    const int64 d = nextInt64();
    cin >> s;

    int64 cur = 1;
    vector<int> a;
    forn(i, s.size()) {
        if (s[i] == 'C') {
            cur *= 2;
        } else {
            a.pb(cur);
        }
    }

    int ans = 0;
    if (a.size() > d) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    while (accumulate(all(a), 0) > d) {
        assert(a.back() != 0);
        a.back() /= 2;
        sort(all(a));
        ++ans;
    }

    cout << ans << endl;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(10);
    double _startTime = clock();
#ifdef NALP_PROJECT
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#else
#endif

    const int tests = nextInt();
    forn(i, tests) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }

    cerr << "Elapsed " << (clock() - _startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
