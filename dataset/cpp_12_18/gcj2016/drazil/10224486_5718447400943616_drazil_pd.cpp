#include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <cstdlib>
 #include <vector>
 #include <map>
 #include <tuple>
 #include <set>
 
 using namespace std;
 
 char pos[100][110];
 int n;
 char ans[100][110];
 int used[100];
 int ord[100];
 set<int> dp[100];
 
 bool go(int layer) {
     if (layer == n) return true;
     else {
         for (int i = 0; i < n; i++) {
             if (used[i] == 0) {
                 used[i] = 1;
                 ord[layer] = i;
                 dp[layer + 1].clear();
                 bool ok = true;
                 for (int taken : dp[layer]) {
                     bool work = false;
                     for (int j = 0; j < n; j++) {
                         if (ans[i][j] == 1 && (taken & (1 << j)) == 0) {
                             work = true;
                             dp[layer + 1].insert(taken | (1 << j));
                         }
                     }
                     if (!work) {
                        ok = false;
                        break;
                    }
                 }
                 if (!ok) return false;
                 if (!go(layer + 1)) return false;
                 used[i] = 0;
             }
         }
     }
     return true;
 }
 
 bool OK() {
     memset(used, 0, sizeof(used));
     dp[0].clear();
     dp[0].insert(0);
     return go(0);
 }
 
 int main() {
     int tc;
     cin >> tc;
     for (int t = 1; t <= tc; t++) {
         cin >> n;
         for (int i = 0; i < n; i++) {
             scanf("%s", pos[i]);
         }
         int cans = n * n;
         for (int i = 0; i < (1 << (n*n)); i++) {
             int id = i;
             bool valid = true;
             int cost = 0;
             for (int y = 0; y < n; y++) {
                 for (int x = 0; x < n; x++) {
                     ans[y][x] = (id & 1);
                     id >>= 1;
                     if (ans[y][x] == 0 && pos[y][x] == '1') valid = false;
                     else if(ans[y][x] == 1 && pos[y][x] == '0') cost++;
                 }
             }
             if (!valid || cost >= cans) {
                 continue;
             }
             if (OK()) {
                 cans = cost;
             }
         }
         printf("Case #%d: %d\n", t, cans);
     }
 
     return 0;
 }
 
