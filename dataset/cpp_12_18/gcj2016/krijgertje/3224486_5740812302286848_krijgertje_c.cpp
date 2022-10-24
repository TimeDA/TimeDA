#include <algorithm>  
 #include <iostream>  
 #include <sstream>  
 #include <string>  
 #include <vector>  
 #include <queue>  
 #include <set>  
 #include <map>  
 #include <cstdio>  
 #include <cstdlib>  
 #include <cctype>  
 #include <cmath>  
 #include <list>  
 #include <climits>
 #include <cassert>
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
 
 const int MAXN=1000;
 const double eps=1e-9;
 const double INF=1e100;
 typedef struct P { int x,y,z; P() {} P(int x,int y,int z):x(x),y(y),z(z) {} } P;
 P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y,a.z-b.z); }
 double dst(const P &a,const P &b) { P d=b-a; return sqrt(0.0+d.x*d.x+d.y*d.y+d.z*d.z); }
 typedef struct R { int to; double l,r; R() {} R(int to,double l,double r):to(to),l(l),r(r) {} } R;
 bool operator<(const R &a,const R &b) { return a.l<b.l; }
 
 int n,tmx;
 P p[MAXN];
 P v[MAXN];
 
 vector<R> e[MAXN];
 int at[MAXN];
 
 void calcrange(int i,int j,double res) {
 	P dp=p[j]-p[i],dv=v[j]-v[i];
 	double a=dv.x*dv.x+dv.y*dv.y+dv.z*dv.z;
 	double b=2*(dp.x*dv.x+dp.y*dv.y+dp.z*dv.z);
 	double c=dp.x*dp.x+dp.y*dp.y+dp.z*dp.z-res*res;
 	if(a==0) {
 		if(c>0) return;
 		e[i].PB(R(j,0,INF));
 		e[j].PB(R(i,0,INF));
 		//printf("%d-%d: 0..oo\n",i,j);
 	} else {
 		double d=b*b-4*a*c; if(d<0) return;
 		//printf("%d-%d: %lf*t^2+%lf*t+%lf<=0 [%lf]\n",i,j,a,b,c,d);
 		double t0=(-b-sqrt(d))/(2*a),t1=(-b+sqrt(d))/(2*a);
 		if(t1<0) return;
 		if(t0<0) t0=0;
 		//printf("%d-%d: %lf..%lf\n",i,j,t0,t1);
 		e[i].PB(R(j,t0,t1));
 		e[j].PB(R(i,t0,t1));
 	}
 }
 
 bool ok(double m) {
 	REP(i,n) e[i].clear(),at[i]=0;
 	REP(i,n) FOR(j,i+1,n) calcrange(i,j,m);
 	REP(i,n) sort(e[i].begin(),e[i].end());
 	priority_queue<pair<double,pair<double,int> > > q;
 	q.push(MP(-0,MP(tmx,0)));
 	while(!q.empty()) {
 		double l=-q.top().first,r=q.top().second.first; int i=q.top().second.second; q.pop();
 		//printf("%lf..%lf at %d\n",l,r,i);
 		if(i==1) return true;
 		while(at[i]<SZ(e[i])&&e[i][at[i]].l<=r) {
 			R cur=e[i][at[i]++];
 			if(cur.r<l) continue;
 			double nl=max(l,cur.l),nr=min(cur.r+tmx,INF);
 			if(nr>r) r=nr;
 			q.push(MP(-nl,MP(nr,cur.to)));
 		}
 		//printf("extended to %lf\n",r);
 	}
 	return false;
 }
 
 void run(int casenr) {
 	scanf("%d%d",&n,&tmx);
 	REP(i,n) scanf("%d%d%d%d%d%d",&p[i].x,&p[i].y,&p[i].z,&v[i].x,&v[i].y,&v[i].z);
 
 	double l=0,h=dst(p[0],p[1])+eps;
 	REP(q,100) {
 		//printf("%lf .. %lf\n",l,h);
 		double m=l+(h-l)/2;
 		//m=casenr==1?1.75:casenr==2?2.0+eps:casenr==3?4.0+eps:m;
 		if(ok(m)) h=m; else l=m;
 	}
 	printf("Case #%d: %.9lf\n",casenr,l+(h-l)/2);
 	fprintf(stderr,"Case #%d: %.9lf\n",casenr,l+(h-l)/2);
 }
 
 int main() {
 
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
