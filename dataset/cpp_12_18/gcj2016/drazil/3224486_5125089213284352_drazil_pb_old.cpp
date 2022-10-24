#include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <cstdlib>
 #include <vector>
 #include <string>
 #include <unordered_map>
 
 using namespace std;
 
 int n, m;
 int pre[110];
 string ch;
 string match[10];
 
 int used[110];
 
 struct cnt {
     int val[10];
     cnt() {
         fill(val, val + 10, 0);
     }
 };
 
 int main() {
     int tc;
     cin >> tc;
     srand(514);
     for (int t = 1; t <= tc; t++) {
         unordered_map<string, cnt> dict;
         cin >> n;
         for (int i = 0; i < n; i++) {
             cin >> pre[i];
             pre[i]--;
         }
         cin >> ch;
         cin >> m;
         for (int i = 0; i < m; i++) {
             cin >> match[i];
         }
         dict.clear();
         
         int unhit = 0;
         for (int sim = 0; sim < 10000 && unhit < 20; sim++) {
             string cur, cls;
             memset(used, 0, sizeof(used));
             double curp = 1.0;
             for (int s = 0; s < n; s++) {
                 int zcnt = 0;
                 for (int i = 0; i < n; i++) if ((pre[i] == -1 || used[pre[i]] == 1) && used[i] == 0) zcnt++;
                 curp /= zcnt;
                 int ccnt = rand() % zcnt;
                 int id;
                 for (id = 0; id < n; id++)
                     if ((pre[id] == -1 || used[pre[id]] == 1) && used[id] == 0) {
                         if (ccnt == 0) break;
                         ccnt--;
                     }
                 used[id] = 1;
                 cur += ch[id];
                 char tmp[5];
                 sprintf(tmp, "%d,", id);
                 cls += tmp;
             }
             unhit++;
             if (dict.find(cls) == dict.end()) {
                 unhit = 0;
                 cnt c;
                 for (int i = 0; i < m; i++) {
                     if (cur.find(match[i]) != std::string::npos) c.val[i] = 1;
                 }
                 dict[cls] = c;
             }
         }
         
         printf("Case #%d:", t);
         int total[10] = {0};
         for (const auto &p : dict) {
             for (int i = 0; i < m; i++) total[i] += p.second.val[i];
         }
         for (int i = 0; i < m; i++) {
             printf(" %.9f", total[i]/(double)dict.size());
         }
         putchar('\n');
     }
     
     return 0;
 }
 
