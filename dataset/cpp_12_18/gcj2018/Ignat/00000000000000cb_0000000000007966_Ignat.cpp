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

int getDamage(const string& str)
{
    int res = 0;
    int curDamange = 1;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'C') {
            curDamange *= 2;
        } else {
            res += curDamange;
        }
    }
    return res;
}

int main()
{
    //initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int d;
        string str;
        cin >> d >> str;

        int res = 0;
        bool found = true;
        while (found && getDamage(str) > d) {
            found = false;
            for (int i = 0; i + 1 < str.size(); ++i) {
                int pos = str.size() - i - 1;
                if (str[pos] == 'S' && str[pos - 1] == 'C') {
                    found = true;
                    swap(str[pos], str[pos - 1]);
                    res += 1;
                    break;
                }
            }
        }

        cout << "Case #" << tt << ": ";
        if (found) {
            cout << res;
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << "\n";
    }
    
    return 0;
}
