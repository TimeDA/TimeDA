#include <cstdio>
 #include <set>
 #include <string>
 #include <vector>
 using namespace std;
 
 char buf[1010][1010];
 int m, n;
 vector<int> dist[1010];
 int worst, fcnt;
 
 int calc(vector<int> &v) {
   set<string> st;
   for (int i = 0 ; i < v.size() ; ++i) {
     int len = strlen(buf[v[i]]);
     for (int j = 0 ; j < len ; ++j) {
       string tmps(buf[v[i]], j+1);
       st.insert(tmps);
     }
   }
   return st.size() + 1;
 }
 
 void solve(int p) {
   if (p == m) {
     int ans = 0;
     int flg = 1;
     for (int i = 0 ; i < n; ++i) {
       if (dist[i].empty()) {flg = 0; break;}
       ans += calc(dist[i]);
     }
     if (!flg) return;
     if (ans > worst) {worst = ans; fcnt = 1;}
     else if (ans == worst) ++fcnt;
     return;
   }
   for (int i = 0 ; i < n ; ++i) {
     dist[i].push_back(p);
     solve(p+1);
     dist[i].pop_back();
   }
 }
 
 int main() {
   int T;
   scanf("%d",&T);
   for (int ca = 1 ; ca <= T ; ++ca) {
     scanf("%d%d", &m, &n);
     for (int i = 0 ; i < m ; ++i)
       scanf("%s", buf[i]);
     for (int i = 0 ; i < n ; ++i) dist[i].clear();
     worst = 0; fcnt = 0;
     solve(0);
     printf("Case #%d: %d %d\n", ca, worst, fcnt);
   }
   return 0;
 }
 
