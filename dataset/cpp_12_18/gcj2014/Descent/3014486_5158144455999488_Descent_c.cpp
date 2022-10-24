#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <queue>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 struct blk{
 	int x1, y1, x2, y2;
 };
 
 struct node{
 	int x, s;
 	bool operator < (node const &T) const{return s > T.s;}
 };
 
 priority_queue<node> q;
 
 
 int dist(blk A, blk B){
 	if (A.x1 > B.x1) return dist(B, A);
 	if (B.x1 >= A.x2){
 		if (B.y2 <= A.y1) return max(B.x1 - A.x2, A.y1 - B.y2) - 1;
 		if (B.y1 >= A.y2) return max(B.x1 - A.x2, B.y1 - A.y2) - 1;
 		return B.x1 - A.x2 - 1;
 	}
 	if (B.y1 >= A.y2) return B.y1 - A.y2 - 1;
 	return A.y1 - B.y2 - 1;
 }
 
 int n, m, nb;
 int d[1005][1005], v[1005];
 blk a[1005];
 
 int Dijkstra(int S, int T, int n){
 	node t;
 	for (int i=0; i<n; i++) v[i] = (1<<30);
 	while (!q.empty()) q.pop();
 	q.push((node){S, 0});
 	while (!q.empty()){
 		t = q.top();
 		q.pop();
 		if (v[t.x] < (1<<30)) continue;
 		v[t.x] = t.s;
 		FOR(i,0,n) q.push((node){i, t.s + d[t.x][i]});
 	}
 	return v[T];
 }
 
 void solve(int tc){
 	scanf("%d%d%d", &n, &m, &nb);
 	FOR(i,0,nb) scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
 	a[nb++] = (blk){-1, 0, -1, m - 1};
 	a[nb++] = (blk){n, 0, n, m - 1};
 	
 	FOR(i,0,nb){
 		d[i][i] = 0;
 		FOR(j,0,i) d[i][j] = d[j][i] = dist(a[i], a[j]);
 	}
 
 	printf("Case #%d: %d\n", tc, Dijkstra(nb-2, nb-1, nb));
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
