
 #include <cstdio>
 #include <string>
 #include <queue>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <set>
 using namespace std;
 
 typedef int LL;
 
 const int MAXW = 104;
 const int MAXH = 504;
 const int MAXN = MAXW * MAXH * 2;
 const int MAXE = MAXN * 8;
 const int INF = 100000000;
 const LL LLINF = INF;
 
 const int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
 
 #define PB push_back
 #define MP make_pair
 #define MIN(a,b) ((a)<(b)?(a):(b))
 
 struct Enode {
   int v;
   LL cap, f;
   int next, dup;
   Enode() {cap = f = 0; v = 0; next = dup = 0;}
   Enode(int _v, LL _cap, LL _f, int _next)
   {v = _v; cap = _cap; f = _f; next = _next;}
 } elist[MAXE*2];
 
 int head[MAXN];
 int V, S, T;
 int pe;
 int h[MAXN];
 LL e[MAXN];
 int inq[MAXN];
 int gap[MAXN*2];
 int hl;
 vector<int> nlist[MAXN*2];
 
 void add_edge(int u, int v, LL cap, LL f = 0) {
   elist[pe++] = Enode(v, cap, f, head[u]);
   head[u] = pe - 1;
   elist[pe++] = Enode(u, 0, -f, head[v]);
   head[v] = pe - 1;
   elist[pe-2].dup = pe - 1;
   elist[pe-1].dup = pe - 2;
 }
 
 void _relabel(int p) {
   int tp, oh, i, j, low = INF;
   oh = h[p];
   for (tp = head[p] ; tp != -1 ; tp = elist[tp].next)
     if (elist[tp].cap > elist[tp].f)
       low = min(low, h[elist[tp].v]);
   h[p] = low + 1;
   hl = max(hl, h[p]);
   nlist[h[p]].PB(p);
 
   ++gap[h[p]];
   if (--gap[oh] == 0) {
     for (i = 0 ; i < V ; i++) {
       if (i != S && h[i] > oh && h[i] <= V) {
         --gap[h[i]];
         h[i] = V + 1;
       }
     }
   }
 }
 
 int _push(int p) {
   int tp;
   LL d;
   for (tp = head[p] ; tp != -1 ; tp = elist[tp].next) {
     if (h[p] != h[elist[tp].v] + 1) continue;
     d = MIN(e[p], elist[tp].cap - elist[tp].f);
     if (d <= 0) continue;
     e[p] -= d; e[elist[tp].v] += d;
     elist[tp].f += d;
     elist[elist[tp].dup].f -= d;
     if (inq[elist[tp].v] == 0 && elist[tp].v != S && elist[tp].v != T) {
       inq[elist[tp].v] = 1;
       nlist[h[elist[tp].v]].PB(elist[tp].v);
     }
   }
   return (e[p] == 0);
 }
 
 int _findh() {
   int i, tmp, s;
   for (i = hl ; i >= 0 ; i--) {
     tmp = nlist[i].size();
     if (tmp == 0) continue;
     s = nlist[i][tmp-1];
     nlist[i].pop_back();
     hl = i;
     break;
   }
   if (i < 0) return -1;
   return s;
 }
 
 LL maxflow_hlpp() {
   int p, tq;
   LL ans;
   memset(e, 0, sizeof(e));
   memset(h, 0, sizeof(h));
   memset(inq, 0, sizeof(inq));
   memset(gap, 0, sizeof(gap));
   for (p = 0 ; p <= V * 2 ; p++) nlist[p].clear();
 
   h[S] = V;
   hl = V; nlist[V].PB(S);
 
   gap[V] = 1; gap[0] = V - 1;
   for (p = head[S] ; p != -1 ; p = elist[p].next) {
     if (elist[p].v == S) continue;
     e[elist[p].v] += elist[p].cap - elist[p].f;
     elist[p].f = elist[p].cap;
     elist[elist[p].dup].f = -elist[p].f;
     if (elist[p].v != T) {
       inq[elist[p].v] = 1;
       nlist[0].PB(elist[p].v);
     }
   }
   while ((tq = _findh()) != -1) {
     while (e[tq] > 0)
       if (!_push(tq)) _relabel(tq);
     inq[tq] = 0;
   }
   ans = 0;
   for (p = head[S] ; p != -1 ; p = elist[p].next)
     ans += elist[p].f;
   return ans;
 }
 
 void initg() {
   memset(head, -1, sizeof(head));
   pe = 1;
 }
 
 int tk[MAXW][MAXH];
 int W, H;
 
 inline int getInIndex(int x, int y) {
   return (x * H + y) * 2;
 }
 inline int getOutIndex(int x, int y) {
   return (x * H + y) * 2 + 1;
 }
 
 int main() {
   int TT;
   scanf("%d", &TT);
   for (int ca = 1 ; ca <= TT ; ++ca) {
     int B;
     scanf("%d%d%d", &W, &H, &B);
     memset(tk, 0, sizeof(tk));
     for (int i = 0 ; i < B ; ++i) {
       int x1, y1, x2, y2;
       scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
       for (int tx = x1 ; tx <= x2 ; ++tx)
         for (int ty = y1 ; ty <= y2 ; ++ty)
           tk[tx][ty] = 1;
     } 
     initg();
     S = W * H * 2; T = S+1; V = T+1;
     for (int i = 0 ; i < W ; ++i)
       for (int j = 0 ; j < H ; ++j) {
         if (tk[i][j]) continue;
         add_edge(getInIndex(i, j), getOutIndex(i, j), 1);
         for (int d = 0 ; d < 4 ; ++d) {
           int ti = i + dir[d][0];
           int tj = j + dir[d][1];
           if (ti < 0 || ti >= W || tj < 0 || tj >= H)
             continue;
           if (tk[ti][tj]) continue;
           add_edge(getOutIndex(i, j), getInIndex(ti, tj), 1);
           add_edge(getOutIndex(ti, tj), getInIndex(i, j), 1);
         }
       }
     for (int i = 0 ; i < W ; ++i) {
       if (!tk[i][0])
         add_edge(S, getInIndex(i, 0), 1);
       if (!tk[i][H-1])
         add_edge(getOutIndex(i, H-1), T, 1);
     }
     int ans = maxflow_hlpp();
     printf("Case #%d: %d\n", ca, ans);
     /*
     for (int i = 0 ; i < V ; ++i) {
       for (int p = head[i] ; p != -1 ; p = elist[p].next) {
         if (elist[p].f > 0) {
           printf("[%d->%d], (%d,%d)%d->(%d,%d)%d\n", i, elist[p].v, i/2/H, i/2%H, i%2, elist[p].v/2/H, elist[p].v/2%H, elist[p].v%2);
         }
       }
     }
     */
     /*
     for (int i = 0 ; i < W ; ++i)
       for (int j = 0 ; j < H ; ++j) {
         int tmp = getInIndex(i, j);
         for (int p = head[tmp] ; p != -1 ; p = elist[p].next) {
           if (elist[p].f > 0) {
             printf("take (%d,%d)\n", i, j);
           }
         }
       }
     */
   }
   return 0;
 }
 
