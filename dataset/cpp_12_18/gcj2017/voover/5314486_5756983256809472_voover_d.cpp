#include <bits/stdc++.h>
 using namespace std;
 
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define FORD(i,b,a) for (int i = (int)(b)-1; i >= (a); --i)
 #define REP(i,N) FOR(i,0,N)
 #define st first
 #define nd second
 #define pb push_back
 
 typedef pair<int, int> PII;
 typedef long long LL;
 
 int C, R, M;
 char D[1000][1000];
 int id[1000][1000];
 void read_input() {
   scanf("%d%d%d", &C, &R, &M);
   REP(i,R)scanf("%s", D[i]);
 }
 
 PII pos_soldiers[100];
 PII pos_turrets[100];
 
 vector<int> turrets[100][100];
 bool visited[100][100];
 
 void dfs(int r, int c, int steps) {
   if (r < 0 || r >= R || c < 0 || c >= C || D[r][c] == '#' || steps < 0 || visited[r][c]) return;
   visited[r][c] = true;
   if (turrets[r][c].size()) return;
   dfs(r-1, c, steps-1);
   dfs(r+1, c, steps-1);
   dfs(r, c-1, steps-1);
   dfs(r, c+1, steps-1);
 }
 
 int S, T;
 int score[1050][1050];
 PII ne[1050][1050];
 
 void go(int mS, int mT) {
   if (score[mS][mT] >= 0) return;
 
   REP(i,R)REP(j,C) turrets[i][j].clear();
   REP(i,R)REP(j,C) {
     if (D[i][j] == 'T' && (mT&(1<<id[i][j]))) {
       FOR(j2,j+1,C) {
         if (D[i][j2] == '#') break;
         turrets[i][j2].pb(id[i][j]);
       }
       FORD(j2,j,0) {
         if (D[i][j2] == '#') break;
         turrets[i][j2].pb(id[i][j]);
       }
       FOR(i2,i+1,R) {
         if (D[i2][j] == '#') break;
         turrets[i2][j].pb(id[i][j]);
       }
       FORD(i2,i,0) {
         if (D[i2][j] == '#') break;
         turrets[i2][j].pb(id[i][j]);
       }
     }
   }
 
   set<PII> n;
   REP(i,S) if (mS&(1<<i)) {
     REP(r,R)REP(c,C) visited[r][c] = false;
     dfs(pos_soldiers[i].st, pos_soldiers[i].nd, M);
     REP(r,R)REP(c,C) if (visited[r][c]) {
       for (auto& t: turrets[r][c]) n.insert({i, t});
     }
   }
 
   score[mS][mT] = 0;
   for (auto& p: n) {
     int mS2 = mS-(1<<p.st), mT2 = mT-(1<<p.nd);
     go(mS2, mT2);
     if (score[mS2][mT2] + 1 > score[mS][mT]) {
       score[mS][mT] = score[mS2][mT2] + 1;
       ne[mS][mT] = p;
     }
   }
 }
 
 void scase() {
   S = 0, T = 0;
   REP(i,R)REP(j,C) {
     if (D[i][j] == 'S') {
       id[i][j] = S++;
       pos_soldiers[id[i][j]] = {i,j};
     }
     if (D[i][j] == 'T') {
       id[i][j] = T++;
       pos_turrets[id[i][j]] = {i,j};
     }
   }
 
   REP(i,(1<<S)) REP(j, (1<<T)) score[i][j] = -1;
 
   int mS = (1<<S) - 1, mT = (1<<T) - 1;
   go(mS, mT);
   int result = score[mS][mT];
   printf("%d\n", result);
   REP(i,result) {
     PII n = ne[mS][mT];
     printf("%d %d\n", n.st + 1, n.nd + 1);
     mS -= (1<<n.st);
     mT -= (1<<n.nd);
   }
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
