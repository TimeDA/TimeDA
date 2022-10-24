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

const int MAXN = 100;

int n;
int x[MAXN][2];
ll shave[MAXN];

ll sum;
ll have[MAXN];

queue<pair<int, ll> > q;

bool can(ll want) {
	q = queue<pair<int, ll> >();
	REP(i, n) have[i] = shave[i];
	ll rem = sum;
	ll qsum = want; q.push(MP(0, want));
	while (!q.empty()) {
		if (qsum > rem) return false;
		int at = q.front().first; ll need = q.front().second; q.pop(); qsum -= need;
		ll cur = min(have[at], need);
		have[at] -= cur; rem -= cur; need -= cur;
		if (need == 0) continue;
		REP(j, 2) {
			q.push(MP(x[at][j], need)); qsum += need;
		}
	}
	return true;
}

ll solve() {
	sum = 0; REP(i, n) sum += shave[i];
	ll l = 0, r = sum + 1;
	while (l + 1 < r) {
		ll m = l + (r - l) / 2;
		if (can(m)) l = m; else r = m;
	}
	return l;
}


void run(int casenr) {
	scanf("%d", &n);
	REP(i, n) REP(j, 2) scanf("%d", &x[i][j]), --x[i][j];
	REP(i, n) scanf("%lld", &shave[i]);
	printf("Case #%d: %lld\n", casenr, solve());
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run(i);
	return 0;
}
