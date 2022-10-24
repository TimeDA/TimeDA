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

const int MAXN = 10;
struct P { ll x, y, z; P() {} P(ll x, ll y, ll z) :x(x), y(y), z(z) {} };
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y, a.z - b.z); }
P operator^(const P &a, const P &b) { return P(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); }

int n;
P p[MAXN];
int ans[MAXN];

int perm[MAXN];

bool pointok(int a, int b, int c, int d) {
	P u = p[b] - p[a], v = p[c] - p[a];
	P norm = u^v;
	ll A = norm.x, B = norm.y, C = norm.z, D = A*p[a].x + B*p[a].y + C*p[a].z;
	if (C < 0) A = -A, B = -B, C = -C, D = -D; assert(C != 0);
	//printf("%lld %lld %lld\n", A*p[a].x + B*p[a].y + C*p[a].z - D, A*p[b].x + B*p[b].y + C*p[b].z - D, A*p[c].x + B*p[c].y + C*p[c].z - D);
	// A*p[d].x+B*p[d].y+C*?=D -> ?=(D-A*p[d].x-B*p[d].y)/C -> D-A*p[d].x-B*p[d].y<=C*p[d].z
	return D - A*p[d].x - B*p[d].y >= C*p[d].z;
}

bool permok() {
	REP(i, n - 2) {
		REP(j, i) {
			if (!pointok(perm[i], perm[i + 1], perm[i + 2], perm[j])) return false;
		}
	}
	return true;
}

bool solve() {
	bool ret = false;
	REP(i, n) perm[i] = i;
	do {
		if (permok()) {
			//printf("sol:"); REP(i, n) printf(" %d", perm[i] + 1); puts("");
			if (!ret) {
				ret = true;
				REP(i, n) ans[i] = perm[i];
				return true;
			}
		}
	} while (next_permutation(perm, perm + n));
	return ret;
}

void run(int casenr) {
	scanf("%d", &n); REP(i, n) scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].z);
	assert(solve());
	printf("Case #%d:", casenr); REP(i, n) printf(" %d", ans[i] + 1); puts("");
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run(i);
	return 0;
}
