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

void initialize()
{
    freopen("_.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

struct State
{
    vector<ii> m;
    int num;
    int r;
    int b;
};

bool operator < (const State& a, const State& b) {
    return a.r + a.b > b.r + b.b;
}

int solveStupid(int r, int b) {
    multiset<State> states;

    State start;
    start.m = vector<ii>(1, ii(0, 0));
    start.r = r;
    start.b = b;
    start.num = 0;
    states.insert(start);

    int best = 0;
    int limit = b + r;

    while (!states.empty()) {
        State state = *states.begin();
        states.erase(states.begin());

        best = max(best, state.num);

        int minM = 0;
        for (auto x : state.m) {
            minM = min(minM, x.first + x.second);
        }

        if (minM > 0) {
            if ((state.num + (state.r + state.b) / minM) < best) {
                continue;
            }
        }

        for (int i = 0; i <= state.r; ++i) {
            for (int j = 0; j <= state.b; ++j) {
                bool ok = true;
                for (auto x : state.m) {
                    if (i <= x.first && j <= x.second) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    continue;
                }

                vector<ii> newM(1, ii(i, j));
                for (auto x : state.m) {
                    if (x.first > i ||  x.second > j) {
                        newM.pb(x);
                    }
                }
                State newState;
                newState.r = state.r - i;
                newState.b = state.b - j;
                newState.num = state.num + 1;
                newState.m = newM;
                states.insert(newState);
            }
        }
    }

    return best;
}

int solveFast(int r, int b) {
    int res = 0;

    set<ii> taken;

    int s = 1;
    while (true) {
        vector<ii> pairs;
        for (int i = s; i >= 0; --i) {
            if (i <= r && s -i <= b) {
                if (!taken.count(ii(i, s - i))) {
                    pairs.pb(ii(i, s - i));
                }
            }
        }
        if (pairs.empty()) {
            if (r < s && b < s) {
                cerr << "RET: " << s << " (" << r << " " << b << ")" << endl;
                return res;
            } else {
                ++s;
                continue;
            }
        }

        int best = 0;
        for (int j = 0; j < pairs.size(); ++j) {
            if (abs((r - pairs[j].first) - (b - pairs[j].second)) > abs((r - pairs[best].first) - (b - pairs[best].second))) {
                 best = j;
            }
        }
        r -= pairs[best].first;
        b -= pairs[best].second;
        taken.insert(ii(pairs[best].first, pairs[best].second));
        res += 1;
        cerr << "TAKEN: " << pairs[best].first << " " << pairs[best].second << endl;
        
        vector<ii> remPairs;
        for (int j = 0; j < pairs.size(); ++j) {
            if (j != best && pairs[j].first <= r  && pairs[j].second <= b) {
                remPairs.pb(pairs[j]);
            }
        }
        pairs = remPairs;
    }
}

std::map<iiii, int> solution;

int dfs(int r, int b, int curR, int maxB)
{
    if (curR > r) {
        return 0;
    }

    //cerr << "START (" << r << " " << b << ") " << curR << " " << maxB << endl;
    auto key = iiii(ii(r, b), ii(curR, maxB));

    auto it = solution.find(key);
    if (it != solution.end()) {
        //cerr << "RET" << endl;
        return it->second;
    }

    int res = 0;
    int curB = 0;
    for (int i = 0; i <= maxB; ++i) {
        if ((i + 1) * curR > r) {
            //cerr << "br 1" << endl;
            break;
        }

        curB += i;
        if (curB > b) {
            //cerr << "br 2" << endl;
            break;
        }

        int add = i + 1;
        if (curR == 0) {
            add -= 1;
        }

        res = max(res, add + dfs(r - (i + 1) * curR, b - curB, curR + 1, i));
    }

    solution[key] = res;
    //cerr << "END (" << r << " " << b << ") " << curR << " " << maxB << ", res=" << res << endl;

    return res;
}

int solveDyn(int r, int b)
{
    //solution.clear();
    return dfs(r, b, 0, b);
}

int main()
{
    //initialize();

    //for (int i = 100; i <= 500; i += 100) {
    //    for (int j = 100; j <= 500; j += 100) {
    //        cerr << i << " " << j << solveDyn(i, j) << endl;
    //        //if (solveDyn(i, j) != solveStupid(i, j)) {
    //        //    cerr << endl;
    //        //    cerr << i << " " << j << " " << solveDyn(i, j) << " " << solveStupid(i, j) << endl;
    //        //    return 0;
    //        //}
    //    }
    //}
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int r, b;
        cin >> r >> b;

        int best = solveDyn(r, b);
        cout << "Case #" << tt << ": " << best << endl;
    }
    
    return 0;
}
