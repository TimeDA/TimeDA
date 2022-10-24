#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;

int n;
int x[MAXN], a[MAXN], b[MAXN];

int m;
map<pair<int, int>, int> ecnt;
map<int, int> acnt;
map<int, int> bcnt;
set<int> amany; int acur;
set<int> bmany; int bcur;

void append(int idx) {
	int aa = a[idx], bb = b[idx]; pair<int, int> key = MP(aa, bb);
	if (++ecnt[key] != 1) return;
	++m;
	if (++acnt[aa] == 2) {
		amany.insert(aa);
		if (SZ(amany) == 1) {
			assert(acur == -1);
			acur = aa;
		}
		if (SZ(amany) == 2) {
			assert(acur != -1);
			acur = -1;
		}
	}
	if (++bcnt[bb] == 2) {
		bmany.insert(bb);
		if (SZ(bmany) == 1) {
			assert(bcur == -1);
			bcur = bb;
		}
		if (SZ(bmany) == 2) {
			assert(bcur != -1);
			bcur = -1;
		}
	}

	
}
void remove(int idx) {
	int aa = a[idx], bb = b[idx]; pair<int, int> key = MP(aa, bb);
	if (--ecnt[key] != 0) return;
	--m;
	if (--acnt[aa] == 1) {
		amany.erase(aa);
		if (SZ(amany) == 1) {
			assert(acur == -1);
			acur = *amany.begin();
		}
		if (SZ(amany) == 0) {
			assert(acur != -1);
			acur = -1;
		}
	}
	if (--bcnt[bb] == 1) {
		bmany.erase(bb);
		if (SZ(bmany) == 1) {
			assert(bcur == -1);
			bcur = *bmany.begin();
		}
		if (SZ(bmany) == 0) {
			assert(bcur != -1);
			bcur = -1;
		}
	}
}
int l, r;
bool ok() {
	//printf("checking [%d..%d) -> %d / %d\n", l, r, SZ(amany), SZ(bmany));
	if (SZ(amany) >= 2 || SZ(bmany) >= 2) return false;
	int na = 0, nb = 0, nab = 0;
	if (acur != -1) na = acnt[acur];
	if (bcur != -1) nb = bcnt[bcur];
	if (acur != -1 && bcur != -1) { nab = ecnt[MP(acur, bcur)] > 0 ? 1 : 0; na -= nab; nb -= nab; }
	int rem = (acur == -1 ? 1 : 0) + (bcur == -1 ? 1 : 0);
	int have = na + nb + nab;
	return m - have <= rem;
}

pair<int, int> solve() {
	REP(i, n) a[i] = x[i] + a[i];
	REP(i, n) b[i] = x[i] - b[i];
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	//printf("b:"); REP(i, n) printf(" %d", b[i]); puts("");

	ecnt.clear(); acnt.clear(); bcnt.clear(); amany.clear(); bmany.clear(); m = 0; acur = -1; bcur = -1;

	pair<int, int> ret = MP(-1, 0); l = 0, r = 0;
	while (r < n) {
		append(r++);
		while (!ok()) remove(l++);
		int cur = r - l;
		if (cur > ret.first) ret = MP(cur, 0); if (cur == ret.first) ++ret.second;
	}
	return ret;
}

void run(int casenr) {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d", &x[i], &a[i], &b[i]);
	pair<int, int> res = solve();
	printf("Case #%d: %d %d\n", casenr, res.first, res.second);
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run(i);
	return 0;
}
