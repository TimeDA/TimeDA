#include <cstdio>
 #include <cstring>
 #include <set>
 using namespace std;
 
 typedef pair<int,int> PII;
 
 struct Comp {
     bool operator()(PII a, PII b) {
         if (a.first != b.first) return a.first > b.first;
         return a.second < b.second;
     }
 };
 
 set<pair<int,int>, Comp> ss;
 
 int main() {
     int T, ca;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         int n, k;
         scanf("%d%d",&n,&k);
         ss.clear();
         ss.insert(make_pair(n, 1));
         int ans1, ans2;
         while (k--) {
             PII cc = *ss.begin();
             ss.erase(ss.begin());
             if (cc.first == 1) {
                 ans1 = ans2 = 0;
             } else if (cc.first == 2) {
                 ans1 = 1; ans2 = 0;
                 cc.first = 1;
                 cc.second = cc.second + 1;
                 ss.insert(cc);
             } else if (cc.first % 2 == 0) {
                 ans1 = cc.first / 2;
                 ans2 = cc.first / 2 - 1;
                 PII leftc = make_pair(cc.first / 2 - 1, cc.second);
                 PII rightc = make_pair(cc.first / 2, cc.second + cc.first / 2);
                 ss.insert(leftc);
                 ss.insert(rightc);
             } else {
                 ans1 = ans2 = cc.first / 2;
                 PII leftc = make_pair(cc.first / 2, cc.second);
                 PII rightc = make_pair(cc.first / 2, cc.second + cc.first / 2 + 1);
                 ss.insert(leftc);
                 ss.insert(rightc);
             }
         }
         printf("Case #%d: ", ca);
         printf("%d %d\n", ans1, ans2);
     }
     return 0;
 }
