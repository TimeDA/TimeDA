#include <cstdio>
 #include <string>
 #include <cstdlib>
 #include <set>
 #include <map>
 using namespace std;
 
 typedef long long LL;
 map<int,LL> up,down;
 int n;
 
 LL cost(LL pcnt, LL scnt) {
   LL t =  ((LL)n + n - scnt + 1) * scnt / 2 * pcnt;
   // printf("pcnt:%lld scnt:%lld t:%lld\n", pcnt, scnt, t);
   return t;
 }
 
 int main() {
   int T, ca, m;
   scanf("%d",&T);
   for (ca = 1 ; ca <= T ; ++ca) {
     scanf("%d%d",&n,&m);
     up.clear(); down.clear();
     set<int> pt;
     LL ori = 0;
     while (m--) {
       int t1, t2, cnt;
       scanf("%d%d%d",&t1,&t2,&cnt);
       ori += cost(cnt, t2-t1);
       up[t1] += cnt;
       down[t2] += cnt;
       pt.insert(t1);
       pt.insert(t2);
     }
     LL ans = 0;
     map<int,LL> cur;
     map<int,LL>::reverse_iterator itr2;
     for (set<int>::iterator itr = pt.begin() ; itr != pt.end() ; ++itr) {
       // printf("pos:%d\n", *itr);
       if (up.count(*itr)) {
         cur[*itr] += up[*itr];
       }
       if (down.count(*itr)) {
         LL tmp = down[*itr];
         for (itr2 = cur.rbegin() ; itr2 != cur.rend() ; ++itr2) {
           // printf("itr2:%d,%lld\n",itr2->first, itr2->second); 
           if (itr2->second == 0) continue;
           if (itr2->second >= tmp) {
             ans += cost(tmp, *itr - itr2->first);
             itr2->second -= tmp;
             tmp = 0; break;
           } 
           ans += cost(itr2->second, *itr - itr2->first);
           tmp -= itr2->second;
           itr2->second = 0;
         }
         // printf("_ans:%lld\n",ans);
       }
     }
     printf("Case #%d: %lld\n", ca, ori-ans);
   }
   return 0;
 }
 
