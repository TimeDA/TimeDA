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

const int MAXN = 10000;

int n;
int sx[MAXN], sy[MAXN];

bool can(ll d) {
	ll lx = LLONG_MIN, hx = LLONG_MAX, ly = LLONG_MIN, hy = LLONG_MAX;
	REP(i, n) {
		lx = max(lx, sx[i] - d);
		hx = min(hx, sx[i] + d);
		ly = max(ly, sy[i] - d);
		hy = min(hy, sy[i] + d);
	}
	return lx <= hx&&ly <= hy;
}

ll solve() {
	ll l = -1, h = 1000000000;
	while (l + 1 < h) {
		ll m = l + (h - l) / 2;
		if (can(m)) h = m; else l = m;
	}
	return h;
}

void run(int casenr) {
	scanf("%d", &n); REP(i, n) scanf("%d%d", &sx[i], &sy[i]);

	ll ans = solve();
	printf("Case #%d: %lld\n", casenr, ans);
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run(i);
	return 0;
}
