#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

int main()
{
	int nt;
	cin >> nt;
    std::cout.precision(11);
	for(int tt = 1; tt <= nt; tt++)
	{
		cout << "Case #" << tt << ":" << endl;
        long double A;
        cin >> A;
        long double al = acosl(1.0 / A);
        long double cosa = 1.0 / A;
        long double sina = sqrt(1.0 - cosa * cosa);

        cout <<  cosa / 2 << " " << sina / 2 << " " << 0.0L << endl;
        cout << -sina / 2 << " " << cosa / 2 << " " << 0.0L << endl;
        cout << 0.0L     << " " << 0.0L      << " " << 0.5L << endl;
	}
	return 0;
}