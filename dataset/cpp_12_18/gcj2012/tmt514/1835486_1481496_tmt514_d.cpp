#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #define SZ(x) ((int)(x).size())
 #define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
 using namespace std;
 
 char s[5005];
 
 int g[5005], deg[5005], all[5005];
 int FIND(int x) { return g[x]==x?g[x]:g[x]=FIND(g[x]); }
 void UNION(int x, int y) { g[FIND(x)] = FIND(y); }
 char w[36]="abcdefghijklmnopqrstuvwxyz";
 char imp[36]="oieastbg";
 int to[36]={}, edg[36][36], ans=0;
 
 void add(int p, int q) {
 	if(edg[p][q]) return;
 	edg[p][q] = 1;
 	++ans;
 	UNION(p, q);
 	deg[p]++; deg[q]--; all[p]++; all[q]++;
 }
 int odds[36]={}, node[36]={};
 
 void solve() {
 	int k;
 	ans = 0;
 	scanf("%d", &k);
 	scanf("%s", s);
 	int n = strlen(s);
 	memset(edg, 0, sizeof(edg));
 	for(int i=0;i<36;i++) g[i] = i;
 	for(int i=0;i<36;i++) deg[i] = all[i] = odds[i] = node[i] = 0;
 	for(int i=0;i<n-1;i++) {
 		int p = s[i]-'a', q = s[i+1]-'a';
 		add(p, q);
 		if(to[p]>=0) add(to[p], q);
 		if(to[q]>=0) add(p, to[q]);
 		if(to[p]>=0 && to[q]>=0) add(to[p], to[q]);
 	}
 	for(int i=0;i<36;i++) odds[i]=0;
 	for(int i=0;i<36;i++) {
 		if(all[i]>0) node[FIND(i)]++;
 		if(deg[i]>0) odds[FIND(i)]+=deg[i];
 	}
 	//for(int i=0;i<36;i++) printf("%d ", deg[i]);
 	for(int i=0;i<36;i++) if(FIND(i)==i) {
 		if(node[i]>0 && odds[i]==0) ans++;
 		else ans += odds[i];
 	}
 	static int cs=0;
 	printf("Case #%d: %d\n", ++cs, ans);
 }
 
 int main(void) {
 	int T;
 	memset(to, -1, sizeof(to));
 	for(int i=0;imp[i];i++) to[imp[i]-'a']=i+26;
 
 	scanf("%d", &T);
 	while(T--) solve();
 	return 0;
 }
 
