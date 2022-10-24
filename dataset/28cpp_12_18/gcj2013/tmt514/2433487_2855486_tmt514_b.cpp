#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 
 class Point {
 	public:
 		int x, y, id;
 		Point(int _x=0, int _y=0, int _id=0) { x=_x; y=_y; id=_id; }
 		Point operator-(const Point &p) { return Point(x-p.x, y-p.y, id); }
 		Point operator+(const Point &p) { return Point(x+p.x, y+p.y, id); }
 		int operator^(const Point &p) { return x*p.y-y*p.x; }
 		int operator*(const Point &p) { return x*p.x+y*p.y; }
 		bool operator<(const Point &p) const { return x*p.y<y*p.x || (x*p.y==y*p.x && x*x+y*y<p.x*p.x+p.y*p.y); }
 		bool operator==(const Point &p) { return x==p.x && y==p.y && id==p.id; }
 } p[500];
 int n, cs;
 int u[500], ucs;
 
 void output(int *r) {
 	printf("Case #%d:", cs);
 	for(int i=0;i<n;i++) printf(" %d", p[r[i]].id);
 	puts("");
 }
 
 bool intersect(Point A, Point B, Point C, Point D) {
 
 	int g1= (C-A)^(C-B);
 	if(g1==0 && !(B==C) && (A-C)*(C-B)>0) return true;
 	int g2= (D-A)^(D-B);
 	if(g2==0 && !(D==A) && (A-D)*(D-B)>0) return true;
 	int g3= (A-C)^(A-D);
 	if(g3==0 && !(D==A) && (C-A)*(A-D)>0) return true;
 	int g4= (B-C)^(B-D);
 	if(g4==0 && !(B==D) && (C-B)*(B-D)>0) return true;
 
 
 
 	int f1=(C-A)^(D-A);
 	int f2=(D-B)^(C-B);
 	int f3=(A-C)^(B-C);
 	int f4=(B-D)^(A-D);
 	if(f1*1LL*f2<=0 || f3*1LL*f4<=0) return false;
 	return true;
 }
 
 void solve() {
 	scanf("%d", &n);
 	for(int i=0;i<n;i++) { scanf("%d%d", &p[i].x, &p[i].y); p[i].id = i; }
 	for(int i=1;i<n;i++)
 		if(p[i].x<p[0].x || (p[i].x==p[0].x && p[i].y<p[0].y)) swap(p[i], p[0]);
 	for(int i=1;i<n;i++) { p[i].x-=p[0].x; p[i].y -= p[0].y; }
 	p[0].x=p[0].y=0;
 	sort(p+1,p+n);
 
 	++ucs;
 	u[0] = ucs;
 	int s[500]={}, ns=0;
 	s[ns++] = 0;
 	s[ns++]=1;
 	for(int i=2;i<n;i++) {
 		while(ns>=2 && ((p[s[ns-1]]-p[s[ns-2]])^(p[i]-p[s[ns-1]])) >= 0)
 			--ns;
 		s[ns++] = i;
 	}
 
 
 	int area1=0;
 	s[ns] = s[0];
 
 	for(int i=0;i<ns;i++) area1 += (p[s[i]]^p[s[i+1]]);
 	if(area1<0) area1=-area1;
 
 	//for(int i=0;i<ns;i++) printf("%d;", p[s[i]].id);
 	//printf("area=%d\n", area1);
 
 
 	int r[20];
 	for(int i=0;i<n;i++) r[i]=i;
 	do {
 		r[n] = r[0];
 		int flag=0, area2=0;
 		for(int i=0;i<n;i++) area2 += (p[r[i]]^p[r[i+1]]);
 		area2=abs(area2);
 
 		//output(r);
 		//printf("area is %d\n", area2);
 		if(abs(area2) * 2 <= area1) continue;
 
 		for(int i=0;i<n && !flag;i++)
 			for(int j=i+1;j<n && !flag;j++)
 				if(intersect(p[r[i]], p[r[i+1]], p[r[j]], p[r[j+1]])) {
 		//			printf("I on %d %d-%d %d\n", p[r[i]].id, p[r[i+1]].id, p[r[j]].id, p[r[j+1]].id);
 					flag = 1;
 				}
 		if(!flag) {
 			output(r);
 			break;
 		}
 	} while(next_permutation(r+1, r+n));
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	for(cs=1;cs<=T;cs++) solve();
 	return 0;
 }
