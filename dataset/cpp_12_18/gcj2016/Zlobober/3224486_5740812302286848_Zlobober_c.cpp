#include <cstdio>
 #include <cmath>
 using namespace std;
 
 const int N = 1050;
 double D[N][N];
 
 struct vt {
     double x, y, z;
     vt(double _x, double _y, double _z) {
         x = _x, y = _y, z = _z;
     }
     friend vt operator *(vt v, double k) {
         return vt(v.x * k, v.y * k, v.z * k);
     }
     friend vt operator *(double k, vt v) {
         return v * k;
     }
     friend vt operator -(vt a, vt b) {
         return vt(a.x - b.x, a.y - b.y, a.z - b.z);
     }
     double abs() {
         return sqrt(x * x + y * y + z * z);
     }
     vt() {}
 };
 
 vt P[N];
 
 bool used[N];
 
 int n;
 
 void DFS(int x, double mx) {
     used[x] = true;
     for (int y = 0; y < n; y++) {
         if (!used[y] && D[x][y] <= mx) {
             DFS(y, mx);
         }
     }
 }
 
 void solve(int cs) {
     double s;
     scanf("%d %lf", &n, &s);
     for (int i = 0; i < n; i++) {
         scanf("%lf %lf %lf", &P[i].x, &P[i].y, &P[i].z);
         double tmp1, tmp2, tmp3;
         scanf("%lf %lf %lf", &tmp1, &tmp2, &tmp3);
     }
     for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
             D[i][j] = (P[i] - P[j]).abs();
     double l = 0, r = 1e4;
     for (int it = 0; it < 50; it++) {
         double x = (l + r) / 2;
         for (int i = 0; i < n; i++)
             used[i] = false;
         DFS(0, x);
         if (used[1])
             r = x;
         else
             l = x;
     }
     printf("Case #%d: %.10lf\n", cs, (l + r) / 2.0);
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
