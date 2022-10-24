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

const int res[40] = {
0,1,
0,2,
0,3,
0,4,
1,2,
1,3,
1,5,
2,4,
2,6,
3,5,
3,7,
4,7,
4,8,
5,8,
5,9,
6,7,
6,8,
6,9,
7,9,
8,9};

int n;
int m;
int g[50][50];
int cnt[50];
int was[50];
int p[50];
int q[50];
int u[50][50];

int dfs (int x) {
	if (was[x]) re 0;
	was[x] = 1;
	int cur = 1;
	for (int i = 0; i < n; i++)
		if (g[x][i] && !was[i])
			cur += dfs (i);
	re cur;
}

int gen (int i, int j) {
	if (i == n) {
		memset (was, 0, sizeof (was));
		int ok = int (dfs (0) == n);
		for (int k = 0; k < n && ok; k++)
			if (cnt[k] != 4)
				ok = 0;
		if (ok) {
			for (int k = 0; k < n; k++) p[k] = k;
			int cnt = 0;
			do {
				int ok2 = 1;
				for (int i = 0; i < n && ok2; i++)
					for (int j = i + 1; j < n && ok2; j++)
						if (g[i][j] != g[p[i]][p[j]]) 
							ok2 = 0;
				if (ok2) {
					cnt++;
					if (cnt > 1) {
						ok = 0;
						break;
					}
				}
			} while (next_permutation (p, p + n));
			if (ok) {
				for (int i = 0; i < n; i++) printf ("%d ", ::cnt[i]);
				printf ("\n");
				for (int i = 0; i < n; i++)
					for (int j = i + 1; j < n; j++)
						if (g[i][j])
							printf ("%d %d\n", i, j);
				re 1;
			}	
		}
		re 0;
	}
	if (j == n) re gen (i + 1, i + 2);
	if (cnt[i] < 4 && cnt[j] < 4) {
		g[i][j] = g[j][i] = 1;
		cnt[i]++;
		cnt[j]++;
		if (gen (i, j + 1)) re 1;
		cnt[i]--;
		cnt[j]--;
		g[i][j] = g[j][i] = 0;
	}
	g[i][j] = g[j][i] = 0;
	re gen (i, j + 1);
}

int main () {
	n = 10;
	for (int i = 0; i < 20; i++) g[res[2 * i]][res[2 * i + 1]] = g[res[2 * i + 1]][res[2 * i]] = 1;
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		int a, b;
		scanf ("%d", &a);
		assert (a != -1);
		scanf ("%d", &b);
		printf ("%d\n", n);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (g[i][j])
					printf ("%d %d\n", i + 1, j + 1);
		fflush (stdout);
		scanf ("%d", &m);
		assert (m != -1);
		memset (u, 0, sizeof (u));
		for (int i = 0; i < 2 * n; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			u[a][b] = u[b][a] = 1;
		}
		for (int k = 0; k < n; k++) p[k] = k;
		do {
			int ok2 = 1;
			for (int i = 0; i < n && ok2; i++)
				for (int j = i + 1; j < n && ok2; j++)
					if (u[p[i]][p[j]] != g[i][j]) 
						ok2 = 0;
			if (ok2) {
				for (int i = 0; i < n; i++) printf ("%d%c", p[i] + 1, " \n"[i + 1 == n]);
				break;
			}
		} while (next_permutation (p, p + n));
		fflush (stdout);
//		cout.precision (20);
//		cout << "Case #" << it << ": ";
//		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}