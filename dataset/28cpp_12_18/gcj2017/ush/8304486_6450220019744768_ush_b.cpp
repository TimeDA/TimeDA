
 #include <cassert>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <iostream>
 #include <string>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 typedef long long ll;
 
 
 int nNode;
 int nEdge;
 
 struct E {
   int a, b;
 };
 
 E es[2010];
 int vs[2010];
 
 vector<int> g1[1010]; // 無向グラフとして扱う
 int g2[1010][1010]; // 有向での割当値
 bool g3[1010][1010]; // 有向で枝があるか
 
 int counter;
 int visited[1010];
 int add;
 bool go(int s, int p, int u) {
   if(u == s) {
     g2[p][u] += add;
     return true;
   }
   if(visited[u] == counter) {
     return false;
   }
   visited[u] = counter;
   REP(i, g1[u].size()) {
     int v = g1[u][i];
     if(v != p) {
       bool res = go(s, u, v);
       if(res) {
         g2[p][u] += add;
         // cerr << ">>>" << p << " " << u << endl;
         return true;
       }
     }
   }
   return false;
 }
 
 bool solve() {
   cerr << "<<<" << endl;
   add = 1;
   while(true) {
     ++add;
     int idx = -1;
     REP(i, nEdge) {
       const E& e = es[i];
       if(g3[e.b][e.a]) { // 逆向きがある場合、具体的には振らないでも良い
         continue;
       }
       if(g2[e.a][e.b] - g2[e.b][e.a]) { // 割当終わってる
         continue;
       }
       idx = i;
       // cerr << ">" << idx << endl;
       break;
     }
     if(idx < 0) {
       break;
     }
     cerr << "idx = " << idx << endl;
 
     counter++;
     bool res = go(es[idx].a, es[idx].a, es[idx].b);
     if(!res) {
       return false;
     }
   }
   return true;
 }
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     scanf("%d%d", &nNode, &nEdge);
     memset(g2, 0, sizeof g2);
     memset(g3, 0, sizeof g3);
     REP(i, nNode) {
       g1[i].clear();
     }
          
     REP(i, nEdge) {
       scanf("%d%d", &es[i].a, &es[i].b);
       es[i].a--;
       es[i].b--;
       g1[es[i].a].push_back(es[i].b);
       g1[es[i].b].push_back(es[i].a);
       g3[es[i].a][es[i].b] = true;
     }
 
     bool possible = solve();
     if(!possible) {
       printf("Case #%d: IMPOSSIBLE\n", iCase+1);
     } else {
       printf("Case #%d:", iCase+1);
       REP(i, nEdge) {
         const E& e = es[i];
         int& v = vs[i];
         v = g2[e.a][e.b] - g2[e.b][e.a];
         if(g3[e.b][e.a]) { // 逆向きがある場合
           if(v == 0) {
             v = 1;
           } else if(v < 0) {
             v = e.a < e.b ? v-1 : 1;
           } else {
             v = e.a < e.b ? v+1 : -1;
           }
         } else {
           // これでOK
         }
         
         assert(abs(v) <= nNode*nNode);
         printf(" %d", v);
       }
       printf("\n");
       fflush(stdout);
     }
   }
   return 0;
 }
 
