#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 const int N = 205;
 
 double P[N];
 double D[N][N];
 
 double calc(vector<double> A) {
     D[0][0] = 1;
     for (int i = 0; i < A.size(); i++) {
         for (int j = 0; j <= i + 1; j++)
             D[i + 1][j] = 0;
         for (int j = 0; j <= i; j++) {
             D[i + 1][j] += D[i][j] * (1 - A[i]);
             D[i + 1][j + 1] += D[i][j] * A[i];
         }
     }
     return D[A.size()][A.size() / 2];
 }
 
 void solve(int cs) {
     int n, k;
     scanf("%d %d", &n, &k);
     for (int i = 0; i < n; i++) {
         scanf("%lf", &P[i]);
     }
     sort(P, P + n);
     double ans = 0;
     for (int i = 0; i <= k; i++) {
         vector<double> A(P, P + i);
         vector<double> B(P + n - (k - i), P + n);
         vector<double> C;
         C.insert(C.end(), A.begin(), A.end());
         C.insert(C.end(), B.begin(), B.end());
         ans = max(ans, calc(C));
     }
     printf("Case #%d: %.10lf\n", cs, ans);
 }
 
 
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {   
         solve(i + 1);
     }
 }
