#include <cstdio>
 #include <queue>
 #include <climits>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <map>
 #include <set>
 #include <algorithm>
 #include <cmath>
 #include <cstdlib>
 #include <functional>
 #include <numeric>
 
 using namespace std;
 
 struct Solver
 {
   int fullhp, b, d;
 
   long long getenc(int hd, int ad, int hk, int ak) {
     return ((ad * 128 + hd) * 128 + hk) * 128 + ak;
   }
 
   void getdec(long long val, int &hd, int &ad, int &hk, int &ak) {
     ak = val % 128; val /= 128;
     hk = val % 128; val /= 128;
     hd = val % 128; val /= 128;
     ad = val;
   }
 
   set<long long> edges;
   bool fill_next(int hd, int ad, int hk, int ak) {
     if (hk - ad <= 0) return true;
     {
       int rhk = hk - ad;
       int rhd = hd - ak;
       if (rhd > 0)
         edges.insert(getenc(rhd, ad, rhk, ak));
     }
     {
       int rhd = hd - ak;
       if (rhd > 0)
         edges.insert(getenc(rhd, ad + b, hk, ak));
     }
     {
       int rhd = fullhp - ak;
       if (rhd > 0)
         edges.insert(getenc(rhd, ad, hk, ak));
     }
     {
       int rak = max(0, ak - d);
       int rhd = hd - rak;
       if (rhd > 0)
         edges.insert(getenc(rhd, ad, hk, rak));
     }
     return false;
   }
 
   map<long long, int> steps;
   int solve(int hd, int ad, int hk, int ak) {
     queue<long long> q;
     q.push(getenc(hd, ad, hk, ak));
     steps[getenc(hd, ad, hk, ak)] = 0;
     while (!q.empty()) {
       long long qf = q.front(); q.pop();
       edges.clear();
       getdec(qf, hd, ad, hk, ak);
       if (fill_next(hd, ad, hk, ak)) {
         return steps[qf] + 1;
       }
       int curstep = steps[qf];
       for (auto v : edges) {
         if (steps.count(v) == 0) {
           q.push(v);
           steps[v] = curstep + 1;
         }
       }
     }
     return -1;
   }
 
   int process() {
     int hd, ad, hk, ak;
     scanf("%d%d%d%d", &hd, &ad, &hk, &ak);
     fullhp = hd;
     scanf("%d%d", &b, &d);
     return solve(hd, ad, hk, ak);
   }
 };
 
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     Solver solver;
     printf("Case #%d: ", testcase);
     int res = solver.process();
     if (res < 0) printf("IMPOSSIBLE\n");
     else printf("%d\n", res);
   }
   return 0;
 }