#include<cstdio>
 #include<iostream>
 #include<queue>
 #include<stack>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<map>
 #include<sstream>
 #include<cmath>
 #include<cctype>
 #include<cassert>
 #include<cstring>
 #include<cstdlib>
 
 using namespace std;
 
 #define pf printf
 #define sf scanf
 #define VI vector<int>
 #define pb push_back
 #define fo(a,b) for((a)=0;(a)<(b);a++)
 
 #define debug 0
 const int inf = 1000000000;
 
 
 long long ncr[305][305] = {0}; void gen_ncr(int n) { int i, j; fo(i, n+1) ncr[i][0] = 1; for(i=1;i<=n;i++) for(j=1;j<=n;j++) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];}
 double dis(double x1, double y1, double x2, double y2) { return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }
 
 int W, L, n;
 struct point {
 	double x, y;
 };
 
 struct circle {
 	int r;
 	int ind;
 };
 
 vector<point> P;
 int flag[105] = {0};
 
 bool cmp(const circle &a, const circle &b) {
 	if( a.r != b.r ) return a.r > b.r;
 	return a.ind < b.ind;
 }
 
 bool ok(double x, double y, double r) {
 	int i;
 	if( x < 0 || y < 0 || x > W || y > L ) return false;
 	for(i=0;i<n;i++) {
 		if( flag[i] ) {
 			double d = dis(P[i].x, P[i].y, x, y);
 			double rad_sum = r + flag[i];
 			if( d < rad_sum ) return false;
 		}
 	}
 
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for( cases=1; cases<=test; cases++ ) {
 		cin >> n >> W >> L;
 		vector<circle> R; R.clear();
 		int i, j;
 		for(i=0; i<n; i++) {
 			circle c; cin >> c.r;
 			c.ind = i;
 			R.pb(c);
 		}
 		sort(R.begin(), R.end(), cmp);
 		P.clear();
 		point p;
 		for(i=0; i<n; i++) P.pb(p);
 		for(i=0; i<n; i++) flag[i] = -1;
 
 		p.x = p.y = 0;
 		P[0] = p;
 		flag[0] = R[0].r;
 
 		if( n > 1 ) {
 			p.x = W; p.y = L;
 			P[1] = p;
 			flag[1] = R[1].r;
 		}
 
 		for(i=0;i<n;i++) {
 			if(flag[i] != -1 &&  ok(W, 0, R[i].r) ) {
 				p.x = W; p.y = 0;
 				P[i] = p;
 				flag[i] = R[i].r;
 				break;
 			}
 		}
 
 		for(i=0;i<n;i++) {
 			if(flag[i] == -1 &&  ok(0, L, R[i].r) ) {
 				p.x = 0; p.y = L;
 				P[i] = p;
 				flag[i] = R[i].r;
 				break;
 			}
 		}
 
 		// to right
 		while(1) {
 			bool yes = false;
 			for(i=0; i<n; i++) {
 				if( flag[i] != -1 ) {
 					for(j=0;j<n;j++) {
 						if( flag[j] == -1 ) {
 							if( ok( P[i].x + R[i].r + R[j].r, P[i].y, R[j].r) ) {
 								p.x = P[i].x + R[i].r + R[j].r;
 								p.y = P[i].y;
 								P[j] = p;
 								flag[j] = R[j].r;
 								yes = true;
 							}
 						}
 					}
 				}
 			}
 			if( yes == false ) break;
 		}
 
 		while(1) {
 			bool yes = false;
 			for(i=0; i<n; i++) {
 				if( flag[i] != -1 ) {
 					for(j=0;j<n;j++) {
 						if( flag[j] == -1 ) {
 							if( ok( P[i].x - R[i].r - R[j].r, P[i].y, R[j].r) ) {
 								p.x = P[i].x - R[i].r - R[j].r;
 								p.y = P[i].y;
 								P[j] = p;
 								flag[j] = R[j].r;
 								yes = true;
 							}
 						}
 					}
 				}
 			}
 			if( yes == false ) break;
 		}
 
 		while(1) {
 			bool yes = false;
 			for(i=0; i<n; i++) {
 				if( flag[i] != -1 ) {
 					for(j=0;j<n;j++) {
 						if( flag[j] == -1 ) {
 							if( ok( P[i].x , P[i].y + R[i].r + R[j].r, R[j].r) ) {
 								p.x = P[i].x ;
 								p.y = P[i].y + R[i].r + R[j].r;
 								P[j] = p;
 								flag[j] = R[j].r;
 								yes = true;
 							}
 						}
 					}
 				}
 			}
 			if( yes == false ) break;
 		}
 
 		while(1) {
 			bool yes = false;
 			for(i=0; i<n; i++) {
 				if( flag[i] != -1 ) {
 					for(j=0;j<n;j++) {
 						if( flag[j] == -1 ) {
 							if( ok( P[i].x , P[i].y - R[i].r - R[j].r, R[j].r) ) {
 								p.x = P[i].x ;
 								p.y = P[i].y - R[i].r - R[j].r;
 								P[j] = p;
 								flag[j] = R[j].r;
 								yes = true;
 							}
 						}
 					}
 				}
 			}
 			if( yes == false ) break;
 		}
 
 		pf("Case #%d:", cases);
 		for(i=0;i<n;i++) {
 			for(j=0;j<n;j++)
 				if( R[j].ind == i ) {
 					pf(" %.1lf %.1lf", P[j].x, P[j].y);
 				}
 		}
 		cout << endl;
 
 	}
 	return 0;
 }
 
