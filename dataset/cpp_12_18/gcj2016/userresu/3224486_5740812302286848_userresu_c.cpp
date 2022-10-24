#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 #include <string>
 #include <cmath>
 #include <queue>
 using namespace std;
 typedef long long ll;
 #define MAXN 1001
 
 struct point {
 	double x, y, z;
 	bool operator==(const point &b) const {
 		return x == b.x && y == b.y && z == b.z;
 	}
 } p[MAXN], v[MAXN];
 
 double dist (point aa, point bb, point va, point vb, double t) {
 	point a, b;
 	a.x = aa.x + va.x * t;
 	a.y = aa.y + va.y * t;
 	a.z = aa.z + va.z * t;
 	b.x = bb.x + vb.x * t;
 	b.y = bb.y + vb.y * t;
 	b.z = bb.z + vb.z * t;
 	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
 }
 
 int N, S;
 double ta[MAXN][MAXN], tb[MAXN][MAXN];
 bool vis[MAXN][101];
 
 struct state {
 	int i, w;
 	double t;
 	bool operator<(const state &b) const {
 		return t + w> b.t + b.w;
 	}
 };
 
 priority_queue<state> Q;
 
 double ft (double a, double t1, double t2) {
 	if (a > t2) return -1;
 	return max(a,t1);
 }
 
 bool dijkstra () {
 	Q = priority_queue<state>();
 	for (int i=1;i<=N;++i) for (int j=0;j<=S;++j) vis[i][j] = 0;
 	Q.push((state){1,0,0});
 	while (!Q.empty()) {
 		state t = Q.top(); Q.pop();
 		if (t.i == 2) return true;
 		if (vis[t.i][t.w]) continue;
 		//fprintf(stderr," %d %d %lf\n",t.i,t.w,t.t);
 		vis[t.i][t.w] = 1;
 		for (int j=1;j<=N;++j) if (j != t.i) {
 			double tm = ft(t.t+t.w,ta[t.i][j],tb[t.i][j]);
 			//printf("_%d %d %lf\n",t.i,j,tm);
 			if (tm == -1 || tm > t.t+t.w+1) continue;
 			Q.push((state){j,0,tm});
 		}
 	}
 	return false;
 }
 
 void main2 () {
 	scanf("%d %d",&N,&S);
 	for (int i=1;i<=N;++i) {
 		scanf("%lf %lf %lf",&p[i].x,&p[i].y,&p[i].z);
 		scanf("%lf %lf %lf",&v[i].x,&v[i].y,&v[i].z);
 	}
 	double l = 0, r = dist(p[1],p[2],v[1],v[2],0);
 	//r = 2;
 	while (r - l > 1e-7) {
 		double m = (l+r)/2;
 		//fprintf(stderr,"%lf %lf\n",l,r);
 		for (int i=1;i<=N;++i) for (int j=i+1;j<=N;++j) {
 			double d = dist(p[i],p[j],v[i],v[j],0);
 			if (d <= m) ta[i][j] = ta[j][i] = 0, tb[i][j] = tb[j][i] = 1000000;
 			else ta[i][j] = ta[j][i] = 1000000, tb[i][j] = tb[j][i] = 0;
 		}
 		if (dijkstra()) r = m;//, printf("good\n");
 		else l = m;
 	}
 	printf("%.7lf\n",l);
 }
 
 int main () {
 	int T = 1;
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 		fprintf(stderr,"%d\n",z);
 		printf("Case #%d: ",z);
 		main2();
 	}
 	return 0;
 }
