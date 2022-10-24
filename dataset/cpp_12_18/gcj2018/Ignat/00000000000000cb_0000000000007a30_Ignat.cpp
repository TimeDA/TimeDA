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
        int area;
        cin >> area;

        int maxShift = 1 + max(3, (area + 2) / 3);
        
        vector<vector<bool>> field(1000, vector<bool>(5));
        
        int index = 2;
        while (true) {
            cout << index << " " << 2 << std::endl;

            int x, y;
            cin >> x >> y;
            if (x == 0 && y == 0) {
                break;
            }
            field[x][y] = true;

            if (field[index - 1][1] && field[index - 1][2] && field[index - 1][3] && index < maxShift) {
                ++index;
            }
        }
    }
    
    return 0;
}
