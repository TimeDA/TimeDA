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
string s;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> m >> s;
		n = sz (s);
		int ans = 0;
		int cur = 0, base = 1;
		for (int i = 0; i < n; i++)
			if (s[i] == 'C')
				base *= 2;
			else
				cur += base;	
		while (cur > m) {
			ans++;
			ii best (-1, -1);
			base = 1;
			for (int i = 0; i + 1 < n; i++)
				if (s[i] == 'C') {
					if (s[i + 1] == 'S')
						best = mp (i, base);
					base *= 2;	
				}
			if (best.fi == -1) break;
			swap (s[best.fi], s[best.fi + 1]);
			cur -= best.se;
		}
		cout.precision (20);
		cout << "Case #" << it << ": ";
		if (cur > m) cout << "IMPOSSIBLE"; else cout << ans;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}