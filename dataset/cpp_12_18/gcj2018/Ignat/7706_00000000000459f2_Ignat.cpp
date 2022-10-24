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
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        if (nums[0] == 0 || nums[n - 1] == 0) {
            cout << "Case #" << tt << ": IMPOSSIBLE\n";
            continue;
        }

        int m = 0;
        int pos = 0;
        
        vector<int> shift(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                m = max(m, abs(pos - i));
                shift[pos] = i - pos;
                pos += 1;
            }
        }

        vector<vector<int>> res(m + 1, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < abs(shift[i]); ++j) {
                int sign = shift[i] > 0 ? 1 : -1;
                res[j][i + sign * j] = sign;
            }
        }

        cout << "Case #" << tt << ": " << m + 1 << "\n";
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                if (res[i][j] == 0) {
                    cout << '.';
                } else if (res[i][j] == 1) {
                    cout << '\\';
                } else {
                    cout << '/';
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
