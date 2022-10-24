#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const double pi = 2 * asin (1.0);

int n;
double m;

double calc (double ang) {
	re (sqrt (2.0) * (cos (ang) * sqrt (2.0) / 2 + sin (ang)));
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%lf", &m);		
		cout.precision (20);
		cout << "Case #" << it << ": " << endl;
		double l = 0, r = 0.955316618124509278;
//		printf ("%.10f %.10f\n", calc (l), calc (r));
		for (int i = 0; i < 50; i++) {
			double s = (l + r) / 2;
//			printf ("%.10f = %.10f\n", s, calc (s));
			if (calc (s) < m) l = s; else r = s;
		}
		double ang = (l + r) / 2;
//		printf ("%.10f\n", ang);
		double x1 = 0.5 * cos (pi / 4);
		double y1 = 0.5 * sin (pi / 4);
		double z1 = 0;
		double x2 = -0.5 * sin (pi / 4);
		double y2 = 0.5 * cos (pi / 4);
		double z2 = 0;
		double x3 = 0;
		double y3 = 0;
		double z3 = 0.5;
		double x4 = x1;
		double y4 = y1 * cos (ang) - z1 * sin (ang);
		double z4 = y1 * sin (ang) + z1 * cos (ang);
		double x5 = x2;
		double y5 = y2 * cos (ang) - z2 * sin (ang);
		double z5 = y2 * sin (ang) + z2 * cos (ang);
		double x6 = x3;
		double y6 = y3 * cos (ang) - z3 * sin (ang);
		double z6 = y3 * sin (ang) + z3 * cos (ang);
		printf ("%.10f %.10f %.10f\n", x4, z4, y4);
		printf ("%.10f %.10f %.10f\n", x5, z5, y5);
		printf ("%.10f %.10f %.10f\n", x6, z6, y6);
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}