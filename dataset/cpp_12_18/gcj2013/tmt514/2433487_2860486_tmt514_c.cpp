#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 
 int cs;
 int n, m, p;
 
 int e[50][4];
 int path[50];
 int good[50];
 int r[50][50], nr[50];
 int Q[1000000];
 void solve() {
 	scanf("%d%d%d", &n, &m, &p);
 	memset(nr,0,sizeof(nr));
 	for(int i=0;i<m;i++) {
 		int x, y, ai, bi;
 		scanf("%d%d%d%d", &x, &y, &ai, &bi);
 		--x; --y;
 		e[i][0]=x;
 		e[i][1]=y;
 		e[i][2]=ai*21;
 		e[i][3]=bi*21;
 		r[x][nr[x]++] = i;
 	}
 	memset(good, 0, sizeof(good));
 	const int INF = 1e9+7;
 	int qb, qe, onpath[20]={};
 	for(int i=0;i<p;i++) { scanf("%d", &path[i]); --path[i]; }//ans++
 	
 	for(int i=0;i<p;i++) onpath[path[i]] = 1;
 
 	for(int i=0;i<(1<<m);i++) {
 		int d[20]={}, f[20]={}, elen[20]={}, inq[20]={};
 
 		for(int j=0;j<m;j++)
 			if(i&(1<<j)) elen[j] = (e[j][2]-onpath[j]); else elen[j]=e[j][3];
 		for(int j=0;j<n;j++) d[j]=INF;
 		d[0]=0;
 		qb=qe=0;
 		Q[qe++]=0;
 		while(qb<qe) {
 			int x=Q[qb++];
 			for(int j=0;j<nr[x];j++) {
 				int id=r[x][j];
 				int y=e[id][1];
 				if(d[y] > d[x] + elen[id]) {
 					d[y] = d[x]+elen[id];
 					f[y] = id;
 					if(!inq[y]) {
 						inq[y]=1;
 						Q[qe++]=y;
 					}
 				}
 			}
 		}
 		int epa[20], em=0, ex=1;
 		while(ex!=0) {
 			epa[em++]=f[ex];
 			ex=e[f[ex]][0];
 		}
 //		printf("%d vs %d; %d\n", elen[1] + elen[3] + elen[4], elen[0], d[1]);
 //		for(int i=0;i<em;i++) printf("%d ", epa[em-1-i]+1); puts("");
 		for(int x=0;x<p && x<em && path[x] == epa[em-1-x];x++) {
 			good[x]=1;
 //			printf("x=%d\n", x);
 		}
 	}
 	int ans=-1;
 	for(int i=0;i<p;i++) if(!good[i]) { ans = path[i]+1; break; }
 	
 	if(ans==-1) {
 		printf("Case #%d: Looks Good To Me\n", cs);
 		fprintf(stderr, "Case #%d: Looks Good To Me\n", cs);
 	} else {
 		printf("Case #%d: %d\n", cs, ans);
 		fprintf(stderr, "Case #%d: %d\n", cs, ans);
 	}
 
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	for(cs=1;cs<=T;cs++) solve();
 	return 0;
 }
