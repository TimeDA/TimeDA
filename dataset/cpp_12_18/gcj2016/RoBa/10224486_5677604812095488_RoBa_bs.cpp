#include <cstdio>
 #include <cmath>
 #include <cstring>
 #include <vector>
 #include <cassert>
 using namespace std;
 
 const int MAXN = 210;
 double dp[MAXN][MAXN];
 int pre[MAXN][MAXN];
 
 int get_best(int c, double a, double b) {
     if (fabs(a-0.5*c) < fabs(b-0.5*c)) return 0;
     return 1;
 }
 
 double pos[MAXN][MAXN];
 double get_ans(vector<double> v) {
     int N = v.size();
     assert(N % 2 == 0);
     memset(pos, 0, sizeof(pos));
     pos[0][0] = 1.0;
     for (int i = 0 ; i < v.size() ; ++i)
         for (int j = 0 ; j <= i ; ++j) {
             pos[i+1][j] += pos[i][j] * (1-v[i]);
             pos[i+1][j+1] += pos[i][j] * v[i];
         }
     return pos[N][N/2];
 }
 int n, k;
 double p[MAXN];
 
 int cnt_bit(int s) {
     int res = 0;
     while (s) {
         if (s&1) ++res;
         s >>= 1;
     }
     return res;
 }
 
 int main() {
     int T;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         scanf("%d%d",&n,&k);
         for (int i = 0 ; i < n ; ++i)
             scanf("%lf",&p[i]);
 
         double best = .0;
         for (int mask = 1 ; mask < (1<<n) ; ++mask) {
             if (cnt_bit(mask) != k) continue;
             vector<double> lt;
             for (int i = 0 ; i < n ; ++i) {
                 if (mask&(1<<i)) lt.push_back(p[i]);
             }
             double ans = get_ans(lt);
             if (ans > best) best = ans;
         }
         printf("Case #%d: %.10lf\n", ca, best);
     }
     return 0;
 }