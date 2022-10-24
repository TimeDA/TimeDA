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

int main()
{
    //initialize();

    int T;
    cin >> T;

    for (int tt = 1; tt <= T; ++tt) {
        int s;
        cin >> s;
        vector<int> d(s), a(s), b(s);
        for (int i = 0; i < s; ++i) {
            cin >> d[i] >> a[i] >> b[i];
        }

        map<int, vector<int>> backA, backB;

        for (int i = 0; i < s; ++i) {
             backA[d[i] + a[i]].pb(i);
             backB[d[i] - b[i]].pb(i);
        }
        //vector<int> indexes;
        //int value = 0;

        //for (int i = 0; i < s; ++i) {
        //    if (d[i] + a[i] != value) {
        //        if (!indexes.empty()) {
        //            backA.insert(make_pair(value, indexes));
        //            indexes.clear();
        //        }
        //    }
        //    value = d[i] + a[i];
        //    indexes.pb(i);
        //}
        //if (!indexes.empty()) {
        //    backA.insert(make_pair(value, indexes));
        //    indexes.clear();
        //}
        //
        //for (int i = 0; i < s; ++i) {
        //    if (d[i] - b[i] != value) {
        //        if (!indexes.empty()) {
        //            backB.insert(make_pair(value, indexes));
        //            indexes.clear();
        //        }
        //    }
        //    value = d[i] - b[i];
        //    indexes.pb(i);
        //}
        //if (!indexes.empty()) {
        //    backB.insert(make_pair(value, indexes));
        //    indexes.clear();
        //}
            
        int res = 0;
        std::set<std::vector<int>> resVars;

        //cerr << "TEST " << tt << endl;

        for (auto it : backA) {
            for (auto jt : backB) {
                vector<int> x;
                for (auto index : it.second) {
                    x.pb(index);
                }
                for (auto index : jt.second) {
                    x.pb(index);
                }
                sort(all(x));
                x.erase(unique(all(x)), x.end());

                vector<int> var;
                //int c = 0;
                for (int i = 0; i < x.size(); ++i) {
                    if (i == 0 || x[i] != x[i - 1] + 1) {
                        if (var.size() > 0) {
                            //cerr << it.first << " " << jt.first << " " << var.size() << endl;
                            //cerr << it.first << " " << jt.first << ": ";
                            //for (auto x : var) {
                            //    cerr << x << " ";
                            //}
                            //cerr << endl;
                        }
                        if (var.size() > res) {
                            res = var.size();
                            resVars.clear();
                        }
                        if (var.size() >= res) {
                            resVars.insert(var);
                        }
                        var.clear();
                    }
                    var.pb(x[i]);
                }
                //if (var.size() > 0) {
                //    cerr << it.first << " " << jt.first << ": ";
                //    for (auto x : var) {
                //        cerr << x << " ";
                //    }
                //    cerr << endl;
                //}
                if (var.size() > res) {
                    resVars.clear();
                    res = var.size();
                }
                if (var.size() >= res) {
                    resVars.insert(var);
                }
            }
        }
        cout << "Case #" << tt << ": " << res << " " << resVars.size() << "\n";
    }
    
    return 0;
}
