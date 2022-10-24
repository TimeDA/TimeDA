#include <cstdio>
 #include <algorithm>
 #include <cassert>
 #include <vector>
 #include <map>
 using namespace std;
 
 map<int, int> M;
 
 void solve(int cs) {
     int p;
     M.clear();
     scanf("%d", &p);
     vector<int> A(p);
     for (int i = 0; i < p; i++) {
         scanf("%d", &A[i]);
     }
     for (int i = 0; i < p; i++) {
         int x;
         scanf("%d", &x);
         M[A[i]] = x;
     }
     int n0 = 0;
     assert(!(M[0] & (M[0] - 1)));
     while ((1 << n0) < M[0])
         n0++;
     for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
         assert(it->second % (1 << n0) == 0);
         it->second >>= n0;
     }
     int sum = 0;
     for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
         sum += it->second;
     }
     assert(!(sum & (sum - 1)));
     vector<int> num;
     while (M.size() > 1) {
         map<int, int>::iterator it = ++M.begin();
         int x = it->first;
         num.push_back(x);
         map<int, int> Q;
         while (!M.empty()) {
             it = M.begin();
             if (it->second == 0) {
                 M.erase(it);
                 continue;
             }
             Q[it->first]++;
             M[it->first]--;
             assert(M[it->first + x] > 0);
             M[it->first + x]--;
         }
         M.swap(Q);
     }
     for (int i = 0; i < n0; i++)
         num.push_back(0);
     sort(num.begin(), num.end());
     printf("Case #%d:", cs);
     for (int x : num)
         printf(" %d", x);
     printf("\n");
 }
 
 int main() 
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
         fflush(stdout);
     }
 }
