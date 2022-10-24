#include <cstdio>
 #include <vector>
 using namespace std;
 
 const int N = 1050;
 
 vector<int> S, M;
 vector<int> E[N];
 
 int DFS(int x, int l, int r) {
     if (S[x] < l || S[x] > r)
         return 0;
     int ans = 1;
     for (int y : E[x])
         ans += DFS(y, l, r);
     return ans;
 }
 
 void solve(int cs_num) {
     int n, d;
     scanf("%d %d", &n, &d);
     int s0, as, cs, rs;
     scanf("%d %d %d %d", &s0, &as, &cs, &rs);
     int m0, am, cm, rm;
     scanf("%d %d %d %d", &m0, &am, &cm, &rm);
     S.resize(n);
     M.resize(n);
     S[0] = s0;
     M[0] = m0;
     for (int i = 1; i < n; i++) {
         S[i] = (S[i - 1] * 1ll * as + cs) % rs;
         M[i] = (M[i - 1] * 1ll * am + cm) % rm;
     }
     for (int i = 0; i < n; i++)
         E[i].clear();    
     for (int i = 1; i < n; i++)
         E[M[i] % i].push_back(i);
     int ans = 0;
     for (int i = 0; i < n; i++) {
         int a = S[i];
         int b = S[i] + d;
         ans = max(ans, DFS(0, a, b));
     }
     printf("Case #%d: %d\n", cs_num, ans);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
