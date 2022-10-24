#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
#endif

#include <iostream>
#include <iomanip>
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

const double PI = 3.1415925;

// + PI / 4.0
// + PI / 4.0
int main()
{
    //initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        double A;
        cin >> A;
        double alpha = asin(A / sqrt(2));
        double x = sin(alpha + PI / 4.0) / 2.0;
        double y = cos(alpha + PI / 4.0) / 2.0;
        double xp = sin(alpha - PI / 4.0) / 2.0;
        double yp = cos(alpha - PI / 4.0) / 2.0;
        cout << "Case #" << tt << ":\n" << setprecision(10) 
            << x << " " << y << " " << 0 << "\n"
            << xp  << " " << yp << " " << 0 << "\n"
            << 0 << " " << 0 << " " << 0.5 << "\n";
    }
    
    return 0;
}
