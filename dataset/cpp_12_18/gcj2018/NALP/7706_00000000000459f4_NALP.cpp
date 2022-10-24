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

#ifdef _WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Cerr cerr
#define Endl endl

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T Sqr(T x) { return x * x; }
template<typename T> inline string ToString(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int Bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename T1, typename T2> std::ostream& operator<<(std::ostream &out, const pair<T1, T2>& a) { out << "(" << a.first << ", " << a.second << ")"; return out; }
template<typename T> std::ostream& operator<<(std::ostream &out, const vector<T>& a) { out << "[" << a.size() << "]{ "; forn(i, a.size()) { out << a[i] << " "; } out << "}"; return out; }

inline int NextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 NextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
inline double NextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 10;

int n, m;
string a[MAXN];
bool c[MAXN][MAXN], used[MAXN][MAXN];

bool Valid(int x, int n) {
    return 0 <= x && x < n;
}

int Go(int x, int y) {
    if (!Valid(x, n) || !Valid(y, m)) {
        return 0;
    }

    if (!c[x][y] || used[x][y]) {
        return 0;
    }

    used[x][y] = true;
    return Go(x + 1, y) + Go(x - 1, y) + Go(x, y + 1) + Go(x, y - 1) + 1;
}

int GetMax() {
    int ans = 0;
    memset(used, 0, sizeof used);
    forn(i, n) {
        forn(j, m) {
            ans = max(ans, Go(i, j));
        }
    }

    return ans;
}

bool Good(const string& s) {
    int c = 0;
    forn(i, int(s.size()) - 1) {
        if (s[i] != s[i + 1]) {
            ++c;
        }
    }

    return c <= 1;
}

const string SSS = "WB";

bool Good(int c1, int c2, int c3, int c4, int X, int Y) {
    forn(x, n) {
        forn(y, m) {
            if (!c[x][y]) continue;

            if (x < X && y < Y) {
                if (a[x][y] != SSS[c1]) return false;
            }

            if (x < X && y >= Y) {
                if (a[x][y] != SSS[c2]) return false;
            }

            if (x >= X && y < Y) {
                if (a[x][y] != SSS[c3]) return false;
            }

            if (x >= X && y >= Y) {
                if (a[x][y] != SSS[c4]) return false;
            }

        }
    }

    return true;
}

bool Good(int c1, int c2, int c3, int c4) {
    forn(x, n + 1) {
        forn(y, m + 1) {
            if (Good(c1, c2, c3, c4, x, y)) {
                return true;
            }
        }
    }

    return false;
}

bool Good() {
    forn(c1, 2) {
        forn(c2, 2) {
            forn(c3, 2) {
                forn(c4, 2) {
                    if (Good(c1, c2, c3, c4)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Good2() {
    forn(i, n) {
        string s;
        forn(j, m) {
            if (c[i][j]) {
                s += a[i][j];
            }
        }

        if (!Good(s)) {
            return false;
        }
    }

    forn(j, m) {
        string s;
        forn(i, n) {
            if (c[i][j]) {
                s += a[i][j];
            }
        }

        if (!Good(s)) {
            return false;
        }
    }

    return true;
}

int StupidSolution() {
    int ans = 0;
    forn(mask, 1 << (n *m)) {
        int bits = 0;
        forn(i, n * m) {
            c[i / m][i % m] = bool(Bit(mask, i));
            if (Bit(mask, i)) {
                ++bits;
            }

        }

        if (GetMax() == bits && Good()) {
            ans = max(ans, bits);
        }
    }

    return ans;
}

void Solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        n = NextInt();
        m = NextInt();
        forn(i, n) {
            cin >> a[i];
        }
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        // generate test.
    }

    int ans = StupidSolution();
    cout << ans << endl;
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#else
#endif

    int minTest = 1, maxTest = INF;
    if (argc == 3) {
        minTest = atoi(argv[1]);
        maxTest = atoi(argv[2]);
    }

    cout.precision(10);
    cout.setf(ios::fixed);

    cerr.precision(10);
    cerr.setf(ios::fixed);

    srand((unsigned int)time(0));
    const int tests = NextInt();
    clock_t totalStartTime = clock();
    for (int test = 1; test <= tests; test++) {
        clock_t startTime = clock();
        cerr << "Case #" << test << endl;
        const bool skipThisTest = (test < minTest || test > maxTest);
        if (!skipThisTest) cout << "Case #" << test << ": ";
        Solve(skipThisTest);

        char formattedTime[100];
        const clock_t time = clock() - startTime;
        sprintf(formattedTime, "%d.%03d", int(time / CLOCKS_PER_SEC), int(time % CLOCKS_PER_SEC));
        cerr << "time for test is " << formattedTime << " s." << endl << endl;
    }

    char formattedTime[100];
    const clock_t totalTime = clock() - totalStartTime;
    sprintf(formattedTime, "%d.%03d", int(totalTime / CLOCKS_PER_SEC), int(totalTime % CLOCKS_PER_SEC));
    cerr << string(20, '=') << endl;
    cerr << "TOTAL TIME IS " << formattedTime << " s." << endl;

    return 0;
}
