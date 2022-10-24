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

int x1, y1, x2, y2;
int cnt;
int g[1001][1001];

int kkk = 0;

ii ask (int x, int y) {
	printf ("%d %d\n", x, y); fflush (stdout);
	kkk++;
	if (x >= 2 && y >= 2 && x <= 999 && y <= 999) {
		int xx, yy;
		xx = x + rand () % 3 - 1;
		yy = y + rand () % 3 - 1;
		x1 = min (xx, x1);
		x2 = max (xx, x2);
		y1 = min (yy, y1);
		y2 = max (yy, y2);
		cnt += 1 - g[xx][yy];
		g[xx][yy] = 1;
//		printf ("%d: put %d %d = %d | %d\n", kkk, xx, yy, cnt, (x2 - x1 + 1) * (y2 - y1 + 1));
		if (cnt == (x2 - x1 + 1) * (y2 - y1 + 1) && cnt >= n) re mp (0, 0);
		re mp (xx, yy);
	} else {
		re mp (-1, -1);
	}
}

ii ask_test (int x, int y) {
	printf ("%d %d\n", x, y); fflush (stdout);
	int xx, yy;
	scanf ("%d%d", &xx, &yy);
	re mp (xx, yy);
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		memset (g, 0, sizeof (g));
		cin >> n;
		int m = 3;
		while (m * m < n) m++;
		x1 = y1 = 1001;
		x2 = y2 = 0;
		cnt = 0;
		memset (g, 0, sizeof (g));
		kkk = 0;
		while (true) {
			pair<int, ii> best (-1, mp (0, 0));
			for (int i = 2; i < m; i++)
				for (int j = 2; j < m; j++) {
					int cur = 0;
					for (int a = -1; a <= 1; a++)
						for (int b = -1; b <= 1; b++)
							cur += 1 - g[i + a][j + b];
					best = max (best, mp (cur, mp (i, j)));						
				}
			ii p = ask_test (best.se.fi, best.se.se);
			if (p.fi == -1 && p.se == -1) assert (false);
			if (p.fi == 0 && p.se == 0) break;
			g[p.fi][p.se] = 1;
		}
//		cout << kkk << endl;
//		cout.precision (20);
//		cout << "Case #" << it << ": ";
//		cout << endl;
        cerr << kkk << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}