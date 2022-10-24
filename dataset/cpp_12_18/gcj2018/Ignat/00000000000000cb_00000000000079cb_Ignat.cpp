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
        int n;
        cin >> n;

        vector<int> even, odd;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if (i % 2 == 0) {
                even.pb(num);
            } else {
                odd.pb(num);
            }
        }

        sort(all(even));
        sort(all(odd));
        
        vector<int> common(n);
        for (int i = 0; i < even.size(); ++i) {
            common[i * 2] = even[i];
        }
        for (int i = 0; i < odd.size(); ++i) {
            common[i * 2 + 1] = odd[i];
        }

        int res = 0;
        while (res + 1 < n && common[res] <= common[res + 1]) {
            ++res;
        }

        cout << "Case #" << tt << ": ";
        if (res == n - 1) {
            cout << "OK";
        } else {
            cout << res;
        }
        cout << "\n";
    }
    
    return 0;
}
