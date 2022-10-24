#include <algorithm>   n
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

const int MAXEDGE = 300;
const int MAXN = 2 * MAXEDGE;
struct E { int ax, ay, bx, by; };

int nedge, nfixed;
E e[MAXEDGE];
int ans[MAXEDGE], nans;

pair<int, int> p[MAXN]; int np;
map<pair<int, int>, int> mp;
vector<pair<int, int> > nodeadj[MAXN];

int lfaceid[2 * MAXEDGE]; int nface;
vector<int> faceadj[2 * MAXEDGE];
int src[2 * MAXEDGE], dst[2 * MAXEDGE];

int getp(int x, int y) {
	pair<int, int> cur = MP(x, y);
	if (mp.count(cur)) return mp[cur];
	int ret = np++; nodeadj[ret].clear(); p[ret]=cur; mp[cur] = ret; return ret;
}
int cid;
bool angcmp(const pair<int, int> &a, const pair<int, int> &b) {
	int aid = a.first, bid = b.first;
	int ax = p[aid].first - p[cid].first, ay = p[aid].second - p[cid].second;
	int bx = p[bid].first - p[cid].first, by = p[bid].second - p[cid].second;
	bool aup = ay > 0 || ay == 0 && ax > 0, bup = by > 0 || by == 0 && bx > 0;
	if (aup != bup) return aup;
	return (ll)ax*by - (ll)ay*bx > 0;
}

bool exists[MAXEDGE];
bool reachface[2 * MAXEDGE];
bool reachedge[2 * MAXEDGE];

void bfs(int s) {
	REP(i, 2 * nedge) reachedge[i] = false;
	REP(i, nface) reachface[i] = false;
	queue<int> q; reachface[s] = true; REPSZ(i, faceadj[s]) { int id = faceadj[s][i]; reachedge[id] = true; q.push(id); }
	while (!q.empty()) {
		int atid = q.front(); q.pop();
		if (exists[atid >> 1]) continue;
		if (reachedge[atid ^ 1]) continue;
		int toface = lfaceid[atid ^ 1];
		assert(!reachface[toface]);
		reachface[toface] = true; REPSZ(i, faceadj[toface]) { int id = faceadj[toface][i]; assert(!reachedge[id]); reachedge[id] = true; q.push(id); }
	}
}

void process(int atface, queue<int> todo) {
	//queue<int> tmp = todo; printf("process (atface=%d):", atface); while (!tmp.empty()) { int cur = tmp.front(); tmp.pop(); printf(" %d", cur + 1); } puts("");
	int nfail = 0;
	while(!todo.empty()&&nfail<SZ(todo)) {
		int cur = todo.front(); todo.pop();
		//printf("trying %d\n", cur + 1);
		exists[cur] = true;
		bfs(atface);
		bool ok = true; REP(i, nedge) if (!exists[i] && !reachedge[2 * i + 0]) ok = false;
		if (!ok) { 
			exists[cur] = false; todo.push(cur); ++nfail; 
		} else {
			ans[nans++] = cur; nfail = 0; 
			//printf("success\n");
		}
	}
	if (!todo.empty()) { printf("failed\n"); assert(false); }
}

bool solve() {
	mp.clear(); np = 0;
	REP(i, nedge) {
		int a = getp(e[i].ax, e[i].ay);
		int b = getp(e[i].bx, e[i].by);
		nodeadj[a].PB(MP(b, 2 * i + 0)); nodeadj[b].PB(MP(a, 2 * i + 1));
		src[2 * i + 0] = a, dst[2 * i + 0] = b, src[2 * i + 1] = b, dst[2 * i + 1] = a;
	}
	REP(i, np) {
		cid = i;
		sort(nodeadj[i].begin(), nodeadj[i].end(), angcmp);
	}
	//REP(i, np) { printf("%d = (%d,%d):", i, p[i].first, p[i].second); REPSZ(j, nodeadj[i]) { int toid = nodeadj[i][j].first; printf(" (%d,%d)", p[toid].first, p[toid].second); } puts(""); }

	REP(i, 2 * nedge) lfaceid[i] = -1; nface = 0;
	REP(s, np) REPSZ(si, nodeadj[s]) {
		int sid = nodeadj[s][si].second; if (lfaceid[sid] != -1) continue;
		lfaceid[sid] = nface++; faceadj[lfaceid[sid]].clear();
		int c = s, ci = si, cid = sid;
		while (true) {
			faceadj[lfaceid[sid]].PB(cid);
			int to = nodeadj[c][ci].first;
			int toi = -1; REPSZ(i, nodeadj[to]) if (nodeadj[to][i].second == (cid ^ 1)) { assert(toi == -1); toi = (i + 1) % SZ(nodeadj[to]); } assert(toi != -1);
			c = to, ci = toi, cid = nodeadj[to][toi].second;
			if (lfaceid[cid] != -1) { assert(cid == sid); break; } else lfaceid[cid] = lfaceid[sid];
		}
	}
	//printf("nface=%d\n", nface);
	//REP(i, nface) { printf("face%d:", i); REPSZ(j, faceadj[i]) { int id = faceadj[i][j]; printf(" (%d,%d)-(%d,%d)", p[src[id]].first, p[src[id]].second, p[dst[id]].first, p[dst[id]].second); } puts(""); }

	int atface = 0; nans = 0; REP(i, nedge) exists[i] = false;
	REP(i, nfixed) {
		exists[i] = true;
		bfs(atface);
		assert(reachedge[2 * i + 0] || reachedge[2 * i + 1]);
		if (reachedge[2 * i + 0] && reachedge[2 * i + 1]) { 
			//printf("safely adding fixed %d\n", i + 1);
			ans[nans++] = i; continue; 
		}
		int nfixedhere = 0, nfixedthere = 0;
		FOR(j, i + 1, nfixed) if (reachedge[2 * j + 0]) ++nfixedhere; else ++nfixedthere;
		if (nfixedhere > 0 && nfixedthere > 0) return false;
		atface = nfixedhere > 0 ? lfaceid[2 * i + 0] : lfaceid[2 * i + 1];
		bfs(atface);
		queue<int> todo;
		FOR(j, nfixed, nedge) if (!exists[j] && !reachedge[2 * j + 0]) todo.push(j);
		exists[i] = false;
		process(atface, todo);
		//printf("adding fixed after processing %d\n", i + 1);
		exists[i] = true; ans[nans++] = i;
	}
	{
		queue<int> todo;
		FOR(j, nfixed, nedge) if (!exists[j]) todo.push(j);
		process(atface, todo);
	}
	//REP(i, nans) { int id = ans[i]; printf("ans %d: (%d,%d)-(%d,%d)\n", id + 1, e[id].ax, e[id].ay, e[id].bx, e[id].by); }
	return true;
}

void run(int casenr) {
	scanf("%d%d", &nedge, &nfixed);
	REP(i, nedge) scanf("%d%d%d%d", &e[i].ax, &e[i].ay, &e[i].bx, &e[i].by);
	assert(solve());
	printf("Case #%d:", casenr); REP(i, nedge) printf(" %d", ans[i] + 1); puts("");
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run(i);
	return 0;
}
