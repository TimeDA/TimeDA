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
 
 const int MAXN=100;
 const double eps=1e-12;
 typedef struct S { double R,C; } S;
 bool operator<(const S &a,const S &b) { return a.C<b.C; }
 
 int n;
 double V,X;
 S s[MAXN];
 
 
 bool can(double t) {
 	{
 		double vhave=0,xhave=0;
 		REP(i,n) {
 			double vmax=s[i].R*t;
 			if(s[i].R>+eps&&xhave+vmax*s[i].C>0) vmax=-xhave/s[i].C;
 			vhave+=vmax; xhave+=vmax*s[i].C;
 		}
 		//printf("up %lf -> %lf, %lf\n",t,vhave,xhave);
 		if(xhave>=-eps&&vhave>=V) return true;
 	}
 	{
 		double vhave=0,xhave=0;
 		for(int i=n-1;i>=0;--i) {
 			double vmax=s[i].R*t;
 			if(s[i].R>+eps&&xhave+vmax*s[i].C<0) vmax=-xhave/s[i].C;
 			vhave+=vmax; xhave+=vmax*s[i].C;
 		}
 		//printf("dn %lf -> %lf, %lf\n",t,vhave,xhave);
 		if(xhave<=+eps&&vhave>=V) return true;
 	}
 	return false;
 }
 
 
 void run(int casenr) {
 	scanf("%d%lf%lf",&n,&V,&X);
 	REP(i,n) scanf("%lf%lf",&s[i].R,&s[i].C);
 	REP(i,n) s[i].C-=X;
 	sort(s,s+n);
 
 	bool leq=false,geq=false;
 	REP(i,n) { if(s[i].C>=-eps) geq=true; if(s[i].C<=+eps) leq=true; }
 	if(!leq||!geq) { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
 
 	double l=0,h=1; while(!can(h)) l=h,h+=h;
 	REP(i,100) {
 		double m=l+(h-l)/2;
 		if(!can(m)) l=m; else h=m;
 	}
 	double ret=l+(h-l)/2;
 	printf("Case #%d: %.9lf\n",casenr,ret);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
