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

int n;
int m;
int p;
int x[110];
int y[110];
double z[110];
double res[25101];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> p;		
		int sum = 0, small = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			if (x[i] > y[i]) swap (x[i], y[i]);
			sum += 2 * (x[i] + y[i]);
			small += x[i];
			z[i] = sqrt (x[i] * x[i] + y[i] * y[i] + 0.0);
		}
		for (int i = 0; i <= small; i++) res[i] = -1e10;
		res[0] = 0;
		small = 0;
		for (int i = 0; i < n; i++) {
			for (int j = small; j >= 0; j--)
				res[j + x[i]] = max (res[j + x[i]], res[j] + z[i]);
			small += x[i];
		}
		double ans = sum;
		for (int i = 0; i <= small && sum + 2 * i <= p; i++)
			if (res[i] >= 0)
				ans = max (ans, min ((double)p, sum + 2 * res[i]));
//		cout.precision (20);
//		cout << "Case #" << it << ": " << ans;
//		cout << endl;
		printf ("Case #%d: %.15f\n", it, ans);
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}