#include <bits/stdc++.h>
 using namespace std;
 
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define FORD(i,b,a) for (int i = (int)(b)-1; i >= (a); --i)
 #define REP(i,N) FOR(i,0,N)
 #define st first
 #define nd second
 #define pb push_back
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 
 typedef pair<int, int> PII;
 typedef long long LL;
 
 namespace two_sat {
   // SILNIE SPÓJNE SKŁADOWE (algrotym Tarjana) + 2SAT
   // Adam Polak
 
   const int N = 100*1000;
   const int NIL = (-1);
 
   int n;              // INPUT
   vector<int> g[N];   // INPUT
 
   int t, in[N], low[N];
   stack<int> s;
   bool stacked[N];
 
   int scc[N], scc_n;  // OUTPUT (SCC)
   bool value[N];      // OUTPUT (2SAT)
 
   void tarjan(int u) {
       low[u] = in[u] = t++;
       s.push(u);
       stacked[u] = true;
       FOREACH(v, g[u]) {
           if (in[*v]==NIL) {
               tarjan(*v);
               low[u] = min(low[u], low[*v]);
           } else if (stacked[*v]) low[u] = min(low[u], in[*v]);
       }
       if (low[u]==in[u]) {
           for(;;) {
               int v = s.top(); s.pop();
               stacked[v] = false;
               scc[v] = scc_n;
               if (v==u) break;
           }
           scc_n++;
       }
   }
 
   void tarjan_scc() {
   	REP(i,n) { in[i] = low[i] = NIL; stacked[i] = false; }
   	scc_n = t = 0;
   	REP(i,n) if(in[i]==NIL) tarjan(i);
   }
 
   // 2SAT usage:
   // 1) n = 2*variables
   // 2) REP(i,n) g[i].clear();
   // 3) add_constr(...)
   // 4) solve_2sat();
 
   void add_constr(int a, bool neg_a, int b, bool neg_b) {
       g[2*a+neg_a].push_back(2*b+1-neg_b);
       g[2*b+neg_b].push_back(2*a+1-neg_a);
   }
 
   bool solve_2sat() {
       tarjan_scc();
       int v[scc_n], c[scc_n];
       REP(i,(n/2)) if (scc[2*i]==scc[2*i+1]) return false;
       REP(i,n) v[scc[i]] = i;
       REP(i,scc_n) c[i] = NIL;
       REP(i,scc_n) if (c[i]==NIL) {
           c[i] = 1;
           c[scc[v[i]^1]] = 0;
       }
       REP(i,(n/2)) value[i] = c[scc[2*i+1]];
       return true;
   }
 }
 
 int R, C;
 char M[100][100];
 
 void read_input() {
   scanf("%d%d", &R, &C);
   REP(i,R) scanf("%s", M[i]);
   REP(i,R)REP(j,C) if (M[i][j] == '-') M[i][j] = '|';
 }
 
 bool visited[100][100];
 vector<pair<int, bool>> poss[100][100];
 
 bool shoot(int i, int j, int di, int dj, bool start = true) {
   if (i < 0 || i >= R || j < 0 || j >= C || M[i][j] == '#') return true;
   if (!start && M[i][j] == '|') return false;
   if (M[i][j] == '/') {
     swap(di, dj);
     di = -di;
     dj = -dj;
   } else if (M[i][j] == '\\') {
     swap(di, dj);
   }
   visited[i][j] = true;
   i += di;
   j += dj;
   return shoot(i, j, di, dj, false);
 }
 
 PII positions[10000];
 
 void scase() {
   int num = 0;
   REP(i,R)REP(j,C) poss[i][j].clear();
 
   REP(i, two_sat::N) two_sat::g[i].clear();
 
   REP(i,R)REP(j,C) {
     if (M[i][j] != '|') continue;
 
     REP(a,R)REP(b,C) visited[a][b] = false;
     bool can_horizontal = shoot(i,j,0,1) && shoot(i,j,0,-1);
     if (can_horizontal) {
       REP(a,R)REP(b,C) if (visited[a][b]) poss[a][b].pb({num, false});
     }
     REP(a,R)REP(b,C) visited[a][b] = false;
     bool can_vertical = shoot(i,j,1,0) && shoot(i,j,-1, 0);
     if (can_vertical) {
       REP(a,R)REP(b,C) if (visited[a][b]) poss[a][b].pb({num, true});
     }
 
     if (!can_horizontal && !can_vertical) {
       printf("IMPOSSIBLE\n");
       return;
     }
     if (!can_horizontal) {
       two_sat::add_constr(num, true, num, true);
     }
     if (!can_vertical) {
       two_sat::add_constr(num, false, num, false);
     }
     positions[num] = {i,j};
     ++num;
   }
 
   two_sat::n = 2 * num;
 
   REP(i,R)REP(j,C) if (M[i][j] == '.') {
     if (poss[i][j].empty()) {
       printf("IMPOSSIBLE\n");
       return;
     }
 
     assert(poss[i][j].size() <= 2);
     if (poss[i][j].size() == 1) {
       poss[i][j].pb(poss[i][j][0]);
     }
     two_sat::add_constr(poss[i][j][0].st, poss[i][j][0].nd, poss[i][j][1].st, poss[i][j][1].nd);
   }
 
   if (!two_sat::solve_2sat()) {
     printf("IMPOSSIBLE\n");
     return;
   }
   printf("POSSIBLE\n");
   REP(i,num) M[positions[i].st][positions[i].nd] = (two_sat::value[i] ? '-' : '|');
   REP(i,R) printf("%s\n", M[i]);
 
   bool ok = true;
   REP(i,R)REP(j,C) visited[i][j] = true;
   REP(a,num) if (two_sat::value[a]) {
     int i = positions[a].st;
     int j = positions[a].nd;
     ok = ok && shoot(i, j, 0, -1);
     ok = ok && shoot(i, j, 0, 1);
   } else {
     int i = positions[a].st;
     int j = positions[a].nd;
     ok = ok && shoot(i, j, -1, 0);
     ok = ok && shoot(i, j, 1, 0);
   }
   REP(i,R)REP(j,C) if (M[i][j] == '.') ok = ok && visited[i][j];
   assert(ok);
 }
 
 struct TestCaseConfig {
   int offset = 0;
   bool readAndPass = false;
 };
 
 TestCaseConfig read_config(int argc, const char* argv[]) {
   TestCaseConfig cfg;
 
   int argi = 0;
   while (argi < argc) {
     const char* arg = argv[argi++];
     if (strcmp(arg, "--read-and-pass") == 0) {
       cfg.readAndPass = true;
     } else if (strcmp(arg, "--case-offset") == 0 && argi < argc) {
       cfg.offset = atoi(argv[argi++]);
     }
   }
 
   return cfg;
 }
 
 int main(int argc, const char* argv[]) {
   TestCaseConfig cfg = read_config(argc, argv);
 
   int C;
   scanf("%d",&C);
   FOR(i,1,C+1) {
     read_input();
     if (cfg.readAndPass) {
       continue;
     }
     printf("Case #%d: ", i + cfg.offset);
     scase();
   }
 
   if (cfg.readAndPass) {
     int MAX_LINE = 20000000;
     char* buffer = new char[MAX_LINE];
     while (fgets(buffer, MAX_LINE, stdin)) {
       fputs(buffer, stderr);
     }
   }
 }
