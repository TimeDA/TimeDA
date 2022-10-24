#include <cstdio>
 #include <cassert>
 #include <tuple>
 #include <set>
 using namespace std;
 
 void solve(int cs) {
     int n, k;
     scanf("%d %d", &n, &k);
     set<int> occ = {0, n + 1};
     tuple<int, int, int> ans;
     for (int i = 0; i < k; i++) {
         tuple<int, int, int> best(-42, -42, -42);
         for (int j = 1; j <= n; j++) {
             if (occ.count(j))
                 continue;
             int r = *occ.upper_bound(j) - j - 1;
             int l = j - *(--occ.lower_bound(j)) - 1;
             best = max(best, make_tuple(min(l, r), max(l, r), -j));
         }
         assert(get<0>(best) != -42);
         int x = -get<2>(best);
         ans = best;
         occ.insert(x);
     }
     printf("Case #%d: %d %d\n", cs, get<1>(ans), get<0>(ans));
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
         fflush(stdout);
         fprintf(stderr, "%d\n", i);
     }
 }
