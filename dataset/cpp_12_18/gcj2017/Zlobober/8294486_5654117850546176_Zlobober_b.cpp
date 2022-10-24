#include <cstdio>
 #include <cassert>
 #include <algorithm>
 #include <string>
 #include <vector>
 using namespace std;
 
 int cnt[6];
 
 char CHR[] = "ROYGBV";
 
 string stup() {
     vector<int> V;
     for (int i = 0; i < 6; i++) {
         for (int j = 0; j < cnt[i]; j++) {
             V.emplace_back(i);
         }
     }
     do {
         bool gbad = false;
         for (int i = 0; i < (int)V.size(); i++) {
             int a = V[i];
             int b = V[(i + 1) % V.size()];
             bool bad = false;
             if (a % 2 == 0)
                 bad |= b == a || (b + 1) % 6 == a || (b + 5) % 6 == a;
             else
                 bad |= b != (a + 3) % 6;
             swap(a, b);
             if (a % 2 == 0)
                 bad |= b == a || (b + 1) % 6 == a || (b + 5) % 6 == a;
             else
                 bad |= b != (a + 3) % 6;
             if (bad) {
                 gbad = true;
                 break;
             }
         }
         if (!gbad) {
             string s;
             for (int i : V)
                 s.push_back(CHR[i]);
             return s;
         }
     } while (next_permutation(V.begin(), V.end()));
     return "IMPOSSIBLE";
 }
 
 int n;
 
 bool valid(string s) {
     for (int i = 0; i < (int)s.size(); i++) {
         char ca = s[i];
         char cb = s[(i + 1) % (int)s.size()];
         int a = find(CHR, CHR + 6, ca) - CHR;
         int b = find(CHR, CHR + 6, cb) - CHR;
         bool bad = false;
         if (a % 2 == 0)
             bad |= b == a || (b + 1) % 6 == a || (b + 5) % 6 == a;
         else
             bad |= b != (a + 3) % 6;
         swap(a, b);
         if (a % 2 == 0)
             bad |= b == a || (b + 1) % 6 == a || (b + 5) % 6 == a;
         else
             bad |= b != (a + 3) % 6;
         if (bad) {
             return false;
         }
     }
     return true;
 }
 
 
 string clev() {
     for (int i = 0; i < 3; i++) {
         if (cnt[i] == cnt[i + 3] && cnt[i] + cnt[i + 3] == n) {
             string ans;
             for (int j = 0; j < n / 2; j++) {
                 ans.push_back(CHR[i]);
                 ans.push_back(CHR[i + 3]);
             }
             return ans;
         }
     }
     for (int i = 0; i < 6; i += 2) {
         if (cnt[i] <= cnt[(i + 3) % 6] && cnt[(i + 3) % 6] != 0) {
             return "IMPOSSIBLE";
         }
         cnt[i] -= cnt[(i + 3) % 6];
     }
     string s;
     int p = 0;
     for (int i = 2; i < 6; i += 2) {
         if (cnt[i] > cnt[p])
             p = i;
     }
     int sum = cnt[0] + cnt[2] + cnt[4];
     if (2 * cnt[p] > sum)
         return "IMPOSSIBLE";
     while (true) {
         if (cnt[p] == 0)
             break;
         int q = -1;
         for (int i = 0; i < 6; i += 2) {
             if ((q == -1 || cnt[i] > cnt[q]) && i != p)
                 q = i;
         }
         cnt[p]--;
         if (cnt[q] == 0 && cnt[p] != 0)
             return "IMPOSSIBLE";
         s.push_back(CHR[p]);
         p = q;
     }
     assert(s.size() >= 2);
     if (!valid(s)) {
         int k = min((int)s.size(), 3);
         sort(s.begin() + (int)s.size() - k, s.end());
         do {
             if (valid(s)) {
                 break;
             }
         } while( next_permutation(s.begin() + (int)s.size() - k, s.end()));
     }
     assert(valid(s));
     for (int i = 0; i < 6; i += 2) {
         if (cnt[(i + 3) % 6] == 0)
             continue;
         int p = find(s.begin(), s.end(), CHR[i]) - s.begin();
         assert(p != s.size());
         ++p;
         string in;
         for (int j = 0; j < cnt[(i + 3) % 6]; j++) {
             in.push_back(CHR[(i + 3) % 6]);
             in.push_back(CHR[i % 6]);
         }
         s = s.substr(0, p) + in + s.substr(p);
     }
     assert(s.size() == n);
     return s;
 }
 
 void solve(int cs) {
     #ifdef INPUT
     scanf("%d", &n);
     for (int i = 0; i < 6; i++) {
         scanf("%d", &cnt[i]);
     }
     #else
     for (int i = 0; i < 6; i++) {
         cnt[i] = rand() % 6;
     }
     n = accumulate(cnt, cnt + 6, 0);
     if (n < 3 || n > 10)
         return;
     #endif
     //fprintf(stderr, "%d %d %d %d %d %d %d\n", n, cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5]);
     string st;
     if (n <= 10)
         st = stup();
     else
         st = "IGN";
     string cl = clev();
 
     //fprintf(stderr, "st = %s, cl = %s\n", st.data(), cl.data());
     assert((st == "IMPOSSIBLE") == (cl == "IMPOSSIBLE") || st == "IGN");
     if (cl != "IMPOSSIBLE") {
         //assert(valid(st));
         assert(valid(cl));
     }
     printf("Case #%d: %s\n", cs, cl.data());
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
