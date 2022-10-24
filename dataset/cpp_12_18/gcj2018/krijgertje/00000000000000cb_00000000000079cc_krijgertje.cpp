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
#include <cstring>
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

const double MPI=acos(-1.0);
const double ALIM=MPI/4;
const double BLIM=0.615479718583211;
struct P { double x,y,z; P () {} P(double x,double y,double z):x(x),y(y),z(z) {} };
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y,a.z+b.z); }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y,a.z-b.z); }

bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.z<b.z; }
double operator^(const P &a,const P &b) { return a.x*b.z-a.z*b.x; }
double side(const P &a,const P &b,const P &c) { return (b-a)^(c-a); }

double want;
double A[3][3];

P mult(const P &p) { return P(A[0][0]*p.x+A[0][1]*p.y+A[0][2]*p.z,A[1][0]*p.x+A[1][1]*p.y+A[1][2]*p.z,A[2][0]*p.x+A[2][1]*p.y+A[2][2]*p.z); }

P p[8]; int np;
P hull[8]; int nhull;

P u,v,w;

double calc(double a,double b) {
	u=P(0.5,0,0),v=P(0,0.5,0),w=P(0,0,0.5);

	double acos=cos(a),asin=sin(a),bcos=cos(b),bsin=sin(b);
	REP(i,3) REP(j,3) A[i][j]=0; A[0][0]=acos,A[0][1]=-asin,A[1][0]=+asin,A[1][1]=acos,A[2][2]=1; u=mult(u),v=mult(v),w=mult(w);
	REP(i,3) REP(j,3) A[i][j]=0; A[1][1]=bcos,A[1][2]=-bsin,A[2][1]=+bsin,A[2][2]=bcos,A[0][0]=1; u=mult(u),v=mult(v),w=mult(w);

	np=0; REP(i,2) REP(j,2) REP(k,2) { P cur(0,0,0); cur=i==0?cur+u:cur-u; cur=j==0?cur+v:cur-v; cur=k==0?cur+w:cur-w; p[np++]=cur; }
	//REP(i,np) printf("p%d: %lf %lf %lf\n",i,p[i].x,p[i].y,p[i].z);

	sort(p,p+np);
	nhull=0; hull[nhull++]=p[0]; int tmp;
	tmp=nhull; REP(i,np) { while(nhull-tmp>0&&side(hull[nhull-2],hull[nhull-1],p[i])<=0) --nhull; hull[nhull++]=p[i]; }
	tmp=nhull; for(int i=np-1;i>=0;--i) { while(nhull-tmp>0&&side(hull[nhull-2],hull[nhull-1],p[i])<=0) --nhull; hull[nhull++]=p[i]; }
	//REP(i,nhull) printf("h%d: %lf %lf\n",i,hull[i].x,hull[i].z);

	double ret=0;
	REP(i,nhull-1) ret+=hull[i]^hull[i+1];
	return ret/2;
}

void run(int casenr) {
	scanf("%lf",&want);

	//double lim=MPI/4;
	//printf("%lf %lf %lf\n",calc(0,0),calc(MPI/4,0),calc(MPI/4,MPI/4));
	//int nsteps=100; REP(i,nsteps) { REP(j,nsteps) printf("%.6lf ",calc(i*lim/(nsteps-1),j*lim/(nsteps-1))); puts(""); }
	/*double l=0,h=lim;
	REP(rep,1000) {
		double m1=l+1*(h-l)/3,m2=l+2*(h-l)/3;
		if(calc(lim,m1)>calc(lim,m2)) h=m2; else l=m1;
	}
	printf("(%.15lf,%.15lf) = %.15lf [%.15lf]\n",lim,l,calc(lim,l),l/MPI);*/

	double midval=calc(0,BLIM);
	double a,b;
	if(want<=midval) {
		double l=0,h=BLIM;
		REP(rep,1000) {
			double m=l+(h-l)/2;
			if(calc(0,m)>want) h=m; else l=m;
		}
		a=0,b=l+(h-l)/2;
	} else {
		double l=0,h=ALIM;
		REP(rep,1000) {
			double m=l+(h-l)/2;
			if(calc(m,BLIM)>want) h=m; else l=m;
		}
		a=l+(h-l)/2,b=BLIM;
	}
	//printf("(%.15lf,%.15lf) = %.15lf [%.15lf]\n",a,b,calc(a,b),fabs(calc(a,b)-want));

	calc(a,b);
	printf("Case #%d:\n",casenr);
	printf("%.15lf %.15lf %.15lf\n",u.x,u.y,u.z);
	printf("%.15lf %.15lf %.15lf\n",v.x,v.y,v.z);
	printf("%.15lf %.15lf %.15lf\n",w.x,w.y,w.z);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
