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
int v[100];
string g[200];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &v[i]);
		for (int i = 0; i < 200; i++) g[i] = string (n, '.');
		cout << "Case #" << it << ": ";
		if (v[0] == 0 || v[n - 1] == 0) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			int pos = 0;
			int row = 0;
			for (int i = 0; i < n; i++) {
				if (v[i] == 0) continue;
				int l = pos, r = pos + v[i] - 1;
				if (i < l) {
					row = max (row, r - i);
					for (int j = 0; j < r - i; j++)
						g[j][r - j] = '/'; 
				} else 
				if (i > r) {
					row = max (row, i - l);
					for (int j = 0; j < i - l; j++)
						g[j][l + j] = '\\'; 
				} else {
					row = max (row, max (i - l, r - i));
					for (int j = l; j <= r; j++)
						if (j < i)
							g[j - l][j] = '\\'; 
						else
						if (j > i)
							g[r - j][j] = '/';
				}
				pos += v[i];
			}
			cout << row + 1 << endl;
			for (int i = 0; i <= row; i++) cout << g[i] << endl;
		}
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}