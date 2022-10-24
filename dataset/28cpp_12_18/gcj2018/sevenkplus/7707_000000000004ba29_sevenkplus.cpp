#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 55
int n;
bool v[N][N];

vector<PII> rand_gen() {
	vector<PII> S;
	vector<int> a;
	for (int i = 0; i < n*4; i ++) a.pb(i);
	memset(v, 0, sizeof v);
	for (int i = 0; i < n*2; i ++) {
		int xx = 0, yy = 0;
		while (xx == yy) {
			xx = rand()%((int)a.size());
			yy = rand()%((int)a.size());
		}
		if (xx < yy) swap(xx, yy);
		int x = a[xx], y = a[yy];
		if (x/4 == y/4 || v[x/4][y/4]) return vector<PII>();
		a.erase(a.begin()+xx);
		a.erase(a.begin()+yy);
		v[x/4][y/4] = v[y/4][x/4] = true;
		S.pb(mp(x/4, y/4));
	}
	return S;
}

int d[N][N];

vector<int> color(vector<PII> S) {
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (i != j) d[i][j] = n-1;
	for (int i = 0; i < n*2; i ++)
		d[S[i].fi][S[i].se] = d[S[i].se][S[i].fi] = 1;
	for (int k = 0; k < n; k ++)
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	vector<int> b;
	for (int i = 0; i < n; i ++) b.pb(0);
	vector<vector<vector<int> > > a;
	for (int _ = 0; _ < 10; _++) {
		a.clear();
		for (int i = 0; i < n; i ++) {
			vector<vector<int> > c(n, vector<int>());
			for (int j = 0; j < n; j ++)
				c[d[i][j]].pb(b[j]);
			for (int j = 0; j < n; j ++)
				sort(c[j].begin(), c[j].end());
			a.pb(c);
		}
		vector<vector<vector<int> > > p = a;
		sort(p.begin(), p.end());
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (a[i] == p[j]) {
					b[i] = j;
					break;
				}
	}
	return b;
}

bool chk(vector<PII> S) {
	if (S.size() != n*2) return false;
	vector<int> b = color(S);
	for (int i = 0; i < n; i ++)
		for (int j = i+1; j < n; j ++)
			if (b[i] == b[j]) return false;
	return true;
}

bool chk2(vector<PII> S) {
	if (S.size() != n*2) return false;
	memset(d, 0, sizeof d);
	for (int i = 0; i < n*2; i ++)
		d[S[i].fi][S[i].se] = d[S[i].se][S[i].fi] = 1;
	vector<int> p;
	for (int i = 0; i < n; i ++) p.pb(i);
	bool F = true;
	do {
		if (F) {
			F = false;
			continue;
		}
		bool G = true;
		for (int i = 0; i < n*2; i ++)
			if (!d[p[S[i].fi]][p[S[i].se]]) G = false;
		if (G) {
			//for (int i = 0; i < n; i ++) printf ("%d%c", p[i], i == n-1?'\n':' ');
			return false;
		}
	} while (next_permutation(p.begin(), p.end()));
	return true;
}


int main() { 
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int L, U;
		cin >> L >> U;
		n = U;
		vector<PII> S;
		if (n != 10) {
			while (S.empty() || !chk(S)) S = rand_gen();
			printf ("%d\n", n);
			for (int i = 0; i < n*2; i ++)
				printf ("%d %d\n", S[i].fi+1, S[i].se+1);
			fflush(stdout);
			cin >> n;
			vector<PII> T;
			for (int i = 0; i < n*2; i ++) {
				int x, y;
				cin >> x >> y;
				x --;
				y --;
				T.pb(mp(x, y));
			}
			vector<int> bS = color(S);
			vector<int> bT = color(T);
			for (int i = 0; i < n; i ++) {
				int s = 0;
				for (int j = 0; j < n; j ++)
					if (bS[i] == bT[j]) s = j;
				printf ("%d%c", s+1, i == n-1?'\n':' ');
			}
			fflush(stdout);
		} else {
			while (S.empty() || !chk2(S)) S = rand_gen();
			printf ("%d\n", n);
			for (int i = 0; i < n*2; i ++)
				printf ("%d %d\n", S[i].fi+1, S[i].se+1);
			fflush(stdout);
			cin >> n;
			vector<PII> T;
			for (int i = 0; i < n*2; i ++) {
				int x, y;
				cin >> x >> y;
				x --;
				y --;
				T.pb(mp(x, y));
			}
			memset(d, 0, sizeof d);
			for (int i = 0; i < n*2; i ++)
				d[T[i].fi][T[i].se] = d[T[i].se][T[i].fi] = 1;
	vector<int> p;
	for (int i = 0; i < n; i ++) p.pb(i);
	do {
		bool G = true;
		for (int i = 0; i < n*2; i ++)
			if (!d[p[S[i].fi]][p[S[i].se]]) G = false;
		if (G) break;
	} while (next_permutation(p.begin(), p.end()));
	for (int i = 0; i < n; i ++)
		printf ("%d%c", p[i]+1, i == n-1?'\n':' ');
	fflush(stdout);
		}
	}
	return 0;
}
