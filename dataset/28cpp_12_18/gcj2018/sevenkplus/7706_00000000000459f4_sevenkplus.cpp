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

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int chk(const vector<string>& a, vector<string>& b) {
	int n = (int) a.size();
	int m = (int) a[0].size();
	vector<vector<bool> > v(n, vector<bool>(m, false));
	int S = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) if (a[i][j] == b[i][j] && !v[i][j]) {
			queue<PII> q;
			v[i][j] = true;
			q.push(mp(i, j));
			int T = 1;
			while (!q.empty()) {
				PII _x = q.front(); q.pop();
				int x = _x.fi, y = _x.se;
				for (int d = 0; d < 4; d ++) {
					int x1 = x+dx[d];
					int y1 = y+dy[d];
					if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] == b[x1][y1] && !v[x1][y1]) {
						T++;
						q.push(mp(x1, y1));
						v[x1][y1] = true;
					}
				}
			}
			S = max(S, T);
		}
	return S;
}

int ffB(const vector<string>& a) {
	int n = (int) a.size();
	int m = (int) a[0].size();
	int S = 0;
	vector<string> b(n, string(m, 'B'));
	S = chk(a, b);
	return S;
}

int ffBW(const vector<string>& a) {
	int n = (int) a.size();
	int m = (int) a[0].size();
	int S = 0;
	for (int mm = 1; mm < m; mm ++) {
		vector<string> b(n, string(mm, 'B') + string(m-mm, 'W'));
		S = max(S, chk(a, b));
	}
	return S;
}

int ffBBBW(const vector<string>& a) {
	int n = (int) a.size();
	int m = (int) a[0].size();
	int S = 0;
	for (int nn = 1; nn < n; nn ++)
		for (int mm = 1; mm < m; mm ++) {
			vector<string> b;
			for (int i = 0; i < nn; i ++)
				b.pb(string(m, 'B'));
			for (int i = 0; i < n-nn; i ++)
				b.pb(string(mm, 'B') + string(m-mm, 'W'));
			S = max(S, chk(a, b));
		}
	return S;
}

int ffBWWB(const vector<string>& a) {
	int n = (int) a.size();
	int m = (int) a[0].size();
	int S = 0;
	for (int nn = 1; nn < n; nn ++)
		for (int mm = 1; mm < m; mm ++) {
			vector<string> b;
			for (int i = 0; i < nn; i ++)
				b.pb(string(mm, 'B') + string(m-mm, 'W'));
			for (int i = 0; i < n-nn; i ++)
				b.pb(string(mm, 'W') + string(m-mm, 'B'));
			S = max(S, chk(a, b));
		}
	return S;
}

int ff(const vector<string>& a) {
	int n = (int) a.size();
	int m = (int) a[0].size();
	bool FB = false, FBW = false, FBBBW = false, FBWWB = false;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (a[i][j] == 'B') FB = true;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m-1; j ++)
			if (a[i][j] == 'B' && a[i][j+1] == 'W') FBW = true;
	for (int i = 0; i < n-1; i ++)
		for (int j = 0; j < m-1; j ++)
			if (a[i][j] == 'B' && a[i][j+1] == 'B' && a[i+1][j] == 'B' && a[i+1][j+1] == 'W') FBBBW = true;
	for (int i = 0; i < n-1; i ++)
		for (int j = 0; j < m-1; j ++)
			if (a[i][j] == 'B' && a[i][j+1] == 'W' && a[i+1][j] == 'W' && a[i+1][j+1] == 'B') FBWWB = true;
	int S = 0;
	if (FB) S = max(S, ffB(a));
	if (FBW) S = max(S, ffBW(a));
	if (FBBBW) S = max(S, ffBBBW(a));
	if (FBWWB) S = max(S, ffBWWB(a));
	return S;
}

vector<string> rev(const vector<string>& a) {
	vector<string> b = a;
	int n = (int) a.size();
	int m = (int) a[0].size();
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (b[i][j] == 'W') b[i][j] = 'B';
			else b[i][j] = 'W';
	return b;
}

vector<string> rot(const vector<string>& a) {
	int n = (int) a.size();
	int m = (int) a[0].size();
	vector<string> b(m, string(n, ' '));
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			b[m-j-1][i] = a[i][j];
	return b;
}

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int n, m;
		cin >> n >> m;
		vector<string> a;
		for (int i = 0; i < n; i ++) {
			string s;
			cin >> s;
			a.pb(s);
		}
		int S = 0;
		S = max(S, ff(a));
		a = rot(a); S = max(S, ff(a));
		a = rot(a); S = max(S, ff(a));
		a = rot(a); S = max(S, ff(a));
		a = rev(a); S = max(S, ff(a));
		a = rot(a); S = max(S, ff(a));
		a = rot(a); S = max(S, ff(a));
		a = rot(a); S = max(S, ff(a));
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}
