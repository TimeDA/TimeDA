#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 
 int cs;
 int n;
 const int N = 2005;
 vector<int> g[N];
 
 void init() {
 	for(int i=0;i<N;i++) g[i].clear();
 }
 
 int A[N], B[N];
 int u[N], ucs, st[N], stn, v[N];
 
 void go(int x) {
 	u[x]=ucs;
 	FOR(it, g[x]) if(u[*it]!=ucs) go(*it);
 	st[stn++] = x;
 }
 
 void solve() {
 	init();
 	scanf("%d", &n);
 	for(int i=1;i<=n;i++) scanf("%d", &A[i]);
 	for(int i=1;i<=n;i++) scanf("%d", &B[i]);
 	int now[N]={};
 	//, deg[N] = {};
 	for(int i=1;i<=n;i++) {
 		//printf("\ni=%d\n", i);
 		if(now[A[i]]) {
 			g[now[A[i]]].push_back(i);
 			//g[i].push_back(now[A[i]]);
 			//printf("add %d -> %d\n", i, now[A[i]]);
 		}
 		now[A[i]] = i;
 		if(now[A[i]-1]) {
 			//g[now[A[i]-1]].push_back(i);
 			g[i].push_back(now[A[i]-1]);
 		//	printf("add %d -> %d\n", now[A[i]-1], i);
 		}
 	}
 	for(int i=0;i<=n;i++) now[i]=0;
 	for(int i=n;i>=1;i--) {
 	//	printf("\ni=%d\n", i);
 		if(now[B[i]]) {
 			//g[i].push_back(now[B[i]]);
 			g[now[B[i]]].push_back(i);
 		//	printf("add %d -> %d\n", i, now[B[i]]);
 		}
 		now[B[i]] = i;
 		if(now[B[i]-1]) {
 			//g[now[B[i]-1]].push_back(i);
 			g[i].push_back(now[B[i]-1]);
 		//	printf("add %d -> %d\n", now[B[i]-1], i);
 		}
 	}
 	
 	//for(int i=1;i<=n;i++) FOR(it, g[i]) deg[*it]++;
 	++ucs;
 	stn=1;
 	for(int i=1;i<=n;i++) sort(g[i].begin(), g[i].end());
 	for(int i=1;i<=n;i++) if(u[i]!=ucs) go(i);
 //	for(int i=1;i<=n;i++) printf("st[%d]=%d\n", i, st[i]);
 	for(int i=1;i<=n;i++) v[st[i]] = i;
 	/*
 	for(int t=1;t<=n;t++) {
 		int x=0;
 		for(int i=1;i<=n;i++) if(u[i]!=ucs && deg[i]==0) {
 			x=i;
 			break;
 		}
 		if(!x) fprintf(stderr, "WARNING!\n");
 		u[x] = ucs;
 		st[stn++] = x;
 		FOR(it, g[x]) deg[*it]--;
 	}*/
 
 	printf("Case #%d:", cs);
 	fprintf(stderr, "Case #%d:", cs);
 	/*for(int i=0;i<stn;i++) {
 		printf(" %d", st[i]);
 		fprintf(stderr, " %d", st[i]);
 	}*/
 	for(int i=1;i<=n;i++) {
 		printf(" %d", v[i]);
 		fprintf(stderr, " %d", v[i]);
 	}
 	printf("\n");
 	fprintf(stderr, "\n");
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	for(cs=1;cs<=T;cs++) solve();
 	return 0;
 }
