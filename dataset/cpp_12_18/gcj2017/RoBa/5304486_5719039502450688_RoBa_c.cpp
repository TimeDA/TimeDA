#include <cstdio>
 #include <cstring>
 #include <queue>
 using namespace std;
 
 int hd, ad, hk, ak, b, d;
 
 bool vis[101][101][101][101];
 
 struct State {
     State() {}
     State(int hd_, int ad_, int hk_, int ak_) {
         hd = hd_;
         ad = ad_;
         hk = hk_;
         ak = ak_;
     }
     int hd, ad, hk, ak;
 };
 
 queue<State> q;
 queue<int> step;
 
 State attack(State s) {
     s.hk -= s.ad;
     s.hd -= s.ak;
     return s;
 }
 
 State buff(State s) {
     s.ad += b;
     if (s.ad > 100) s.ad = 100;
     s.hd -= s.ak;
     return s;
 }
 
 State cure(State s) {
     s.hd = hd;
     s.hd -= s.ak;
     return s;
 }
 
 State debuff(State s) {
     s.ak -= d;
     if (s.ak < 0) s.ak = 0;
     s.hd -= s.ak;
     return s;
 }
 
 int main() {
     int T;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         scanf("%d%d%d%d%d%d",&hd,&ad,&hk,&ak,&b,&d);
         
         while (!q.empty()) q.pop();
         while (!step.empty()) step.pop();
 
         q.push(State(hd,ad,hk,ak));
         memset(vis, 0, sizeof(vis));
         vis[hd][ad][hk][ak] = 1;
         step.push(0);
         int flg = false;
         int ans = -1;
         while (!q.empty() && !flg) {
             State state = q.front();
             State ns;
             int cur_step = step.front();
             q.pop();
             step.pop();
             for (int cmd = 0 ; cmd < 4 ; ++cmd) {
                 if (cmd == 0) {
                     ns = attack(state);
                 } else if (cmd == 1) {
                     ns = buff(state);
                 } else if (cmd == 2) {
                     ns = cure(state);
                 } else if (cmd == 3) {
                     ns = debuff(state);
                 }
                 if (ns.hk <= 0) {
                     ans = cur_step + 1;
                     flg = true;
                     break;
                 }
                 if (ns.hd <= 0) continue;
                 if (vis[ns.hd][ns.ad][ns.hk][ns.ak]) continue;
                 vis[ns.hd][ns.ad][ns.hk][ns.ak] = 1;
                 // printf("step %d: [%d %d %d %d]\n", cur_step+1, ns.hd, ns.ad, ns.hk, ns.ak);
                 q.push(ns);
                 step.push(cur_step+1);
             }
         }
         printf("Case #%d: ", ca);
         if (!flg) printf("IMPOSSIBLE\n");
         else printf("%d\n", ans);
     }
     return 0;
 }
 
