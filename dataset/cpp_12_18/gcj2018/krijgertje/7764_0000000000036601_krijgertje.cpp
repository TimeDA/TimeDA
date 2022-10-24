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
const int MAXL = 100000;

int n, nl;
int a[MAXL];

int nxt[MAXN];
vector<int> prv[MAXN];
int need[MAXN];
int q[MAXN], qhead, qtail;

int b[MAXL];
int opt[MAXL], nopt;

int solve() {
	int have = 0; REP(i, nl) have += a[i];
	int rem = n - have;
	int full = 100 / n, part = 100 % n;
	if (part == 0) return 100;
	//printf("have=%d rem=%d full=%d part=%d\n", have, rem, full, part);

	REP(i, n) nxt[i] = (i + part) % n;
	REP(i, n) prv[nxt[i]].PB(i);
	REP(i, n) need[i] = -1; qhead = qtail = 0;
	REP(i, n) if (2 * i >= n) need[i] = 0, q[qhead++] = i;
	while (qtail < qhead) {
		int at = q[qtail++];
		REPSZ(i, prv[at]) {
			int to = prv[at][i];
			if (need[to] != -1) continue;
			need[to] = need[at] + 1, q[qhead++] = to;
		}
	}
	//printf("need:"); REP(i, n) printf(" %d", need[i]); puts("");


	int extra0 = 0, extra1 = 0, extra2 = 0, extra3 = 0;
	REP(i, nl) { ll cur = (ll)a[i] * part; extra0 += cur / n; b[i] = cur%n; }
	nopt = 0; REP(i, nl) if (need[b[i]] > 0) opt[nopt++] = need[b[i]]; else ++extra1;
	//printf("b:"); REP(i, nl) printf(" %d", b[i]); puts("");
	//printf("opt:"); REP(i, nopt) printf(" %d", opt[i]); puts("");

	sort(opt, opt + nopt);
	int left = rem;
	REP(i,nopt) {
		if (opt[i] >= need[0]) continue;
		if (opt[i] > left) continue;
		left -= opt[i]; ++extra2;
	}
	extra3 = left / need[0];
	//printf("extra = %d+%d+%d+%d\n", extra0, extra1, extra2, extra3);
	return n*full + extra0 + extra1 + extra2 + extra3;
}

void run(int casenr) {
	scanf("%d%d", &n, &nl);
	REP(i, nl) scanf("%d", &a[i]);
	printf("Case #%d: %d\n", casenr, solve());
	REP(i, n) prv[i].clear();
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run(i);
	return 0;
}
