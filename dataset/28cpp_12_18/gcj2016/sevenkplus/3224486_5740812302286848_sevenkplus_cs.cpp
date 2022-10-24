#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define N 1010
 
 struct P3
 {
 	double x, y, z;
 	
 	P3 () {}
 	P3 (double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
 
 	void get() {cin >> x >> y >> z;}
 	void out() const {printf("%.9lf %.9lf %.9lf\n", x, y, z);}
 	
 	P3 operator + (const P3&a) const {return P3(x+a.x, y+a.y, z+a.z);}
 	P3 operator - (const P3&a) const {return P3(x-a.x, y-a.y, z-a.z);}
 	P3 operator * (double a) const {return P3(x*a, y*a, z*a);}
 	P3 operator / (double a) const {return P3(x/a, y/a, z/a);}
 	
 	double dot (const P3&a) const {return x*a.x + y*a.y + z*a.z;}
 	P3 crs (const P3&a) const {return P3(y*a.z-z*a.y, z*a.x-x*a.z, x*a.y-y*a.x);}
 	
 	double abs2 () const {return x*x+y*y+z*z;}
 	double abs () const {return sqrt(abs2());}
 	double dis2 (const P3&a) const {return (*this-a).abs2();}
 	double dis (const P3&a) const {return (*this-a).abs();}
 };
 
 int n, s; P3 p[N], v[N]; 
 double d[N][N]; 
 double a[N][N];
 
 int main () {
 	int _; cin >> _; 
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n >> s; 
 		for (int i = 0; i < n; i ++) {
 			p[i].get();  v[i].get(); 
 		}
 		for (int i = 0; i < n; i ++) 
 			for (int j = 0; j < n; j ++) d[i][j] = p[i].dis(p[j]); 
 		for (int i = 0; i < n; i ++) 
 			for (int j = 0; j < n; j ++) {
 				if (i == j) a[i][j] = 0;
 				else a[i][j] = d[i][j];
 			}
 		for (int k = 0; k < n; k ++)
 			for (int i = 0; i < n; i ++)
 				for (int j = 0; j < n; j ++) 
 					a[i][j] = min(a[i][j], max(a[i][k], a[k][j])); 
 		printf ("Case #%d: %.9lf\n", __, a[0][1]);
 	}
 	return 0;
 }