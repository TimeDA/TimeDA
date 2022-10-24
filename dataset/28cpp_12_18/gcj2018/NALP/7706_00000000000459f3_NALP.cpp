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

const int MAXN = 510;
const int MAXR = 50;

int d[MAXR][MAXN][MAXN];

int Get(int x, int n, int m) {
    assert(x < MAXR);
    assert(n < MAXN);
    assert(m < MAXN);

    int& ans = d[x][n][m];
    if (ans != -1) {
        return ans;
    }

    ans = 0;
    int cy = 0;
    for (int y = 0; ; ++y) {
        cy += y;
        const int cx = x * (y + 1);
        if (cy <= m && cx <= n) {
            ans = max(ans, Get(x + 1, n - cx, m - cy) + y + 1);
        } else {
            break;
        }
    }

    return ans;
}

int StupidSolution() {
    return 0;
}

void Solve(bool skipThisTest) {
    int n, m;
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        n = NextInt();
        m = NextInt();
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        n = rand() % 500 + 1;
        m = rand() % 500 + 1;
    }

    const int ans = Get(0, n, m) - 1;
    cout << ans << endl;

    cerr << "\tclever answer is '" << ans << "'." << endl;
    if (n * m <= -1) {
        const int stupidAnswer = StupidSolution();
        cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
        assert(ans == stupidAnswer);
    }
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#else
#endif

    memset(d, 255, sizeof d);

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
