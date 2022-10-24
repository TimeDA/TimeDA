#include <bits/stdc++.h>
 using namespace std;
 
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define REP(i,N) FOR(i,0,N)
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 #define st first
 #define nd second
 #define pb push_back
 
 typedef pair<int, int> PII;
 typedef long long LL;
 
 namespace matching {
   // MAKSYMALNE SKOJARZENIE w grafie dwudzielnym ("Turbomatching")
   // Adam Polak
 
   const int N = 10000;
   int n1,n2;          // INPUT
   vector<int> g[N];   // INPUT
   int m1[N], m2[N];   // OUTPUT
   bool c[N];
 
   bool dfs(int u) {
       if (u<0) return true;
       if (c[u]) return false; else c[u]=true;
       FOREACH(v, g[u])
           if (dfs(m2[*v])) { m1[u] = *v; m2[*v] = u; return true; }
       return false;
   }
 
   int matching() {
       REP(i,n1) m1[i]=-1;
       REP(i,n2) m2[i]=-1;
       bool changed;
       do {
           changed = 0;
           REP(i,n1) c[i]=false;
           REP(i,n1) if (m1[i]<0) changed |= dfs(i);
       } while(changed);
       int siz = 0;
       REP(i,n1) siz += (m1[i]!=-1);
       return siz;
   }
 };
 
 int N, M;
 char B[105][105];
 
 void read_input() {
   scanf("%d%d", &N, &M);
   REP(i,N)REP(j,N) B[i][j] = 0;
   REP(i,M) {
     int a, b;
     char buf[3];
     scanf("%1s%d%d", buf, &a, &b);
     --a, --b;
     if (buf[0] == 'x') {
       B[a][b] = 1;
     } else if (buf[0] == '+') {
       B[a][b] = 2;
     } else if (buf[0] == 'o') {
       B[a][b] = 3;
     }
   }
 }
 
 char B2[105][105];
 bool used_row[205], used_col[205], used_diag[205], used_diag2[205];
 void scase() {
   REP(i,2*N) used_row[i] = used_col[i] = used_diag[i] = used_diag2[i] = false;
 
   REP(i,N)REP(j,N) {
     B2[i][j] = B[i][j];
     if (B[i][j]&1) used_row[i] = used_col[j] = true;
     if (B[i][j]&2) used_diag[i+j] = used_diag2[i-j+N] = true;
   }
 
   matching::n1 = matching::n2 = N;
   REP(i,N) matching::g[i].clear();
   REP(i,N)REP(j,N) {
     if (!used_row[i] && !used_col[j]) matching::g[i].pb(j);
   }
   matching::matching();
   REP(i,N)REP(j,N) if (matching::m1[i] == j) B2[i][j] |= 1;
 
   matching::n1 = matching::n2 = 2*N;
   REP(i,2*N) matching::g[i].clear();
   REP(i,N)REP(j,N) {
     if (!used_diag[i+j] && !used_diag2[i-j+N]) matching::g[i+j].pb(i-j+N);
   }
   matching::matching();
   REP(i,N)REP(j,N) if (matching::m1[i+j] == i-j+N) B2[i][j] |= 2;
 
   int pts = 0, changes = 0;
   REP(i,N)REP(j,N) {
     if (B2[i][j]&1) ++pts;
     if (B2[i][j]&2) ++pts;
     if (B2[i][j] != B[i][j]) ++changes;
   }
   printf("%d %d\n", pts, changes);
   REP(i,N)REP(j,N) if (B[i][j] != B2[i][j]) {
     char c;
     if (B2[i][j] == 1) c = 'x';
     else if (B2[i][j] == 2) c = '+';
     else c = 'o';
     printf("%c %d %d\n", c, i+1, j+1);
   }
   // REP(i,N) {
   //   REP(j,N) {
   //     char c;
   //     if (B2[i][j] == 1) c = 'x';
   //     else if (B2[i][j] == 2) c = '+';
   //     else if (B2[i][j] == 3) c = 'o';
   //     else c = '.';
   //     printf("%c", c);
   //   }
   //   printf("\n");
   // }
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
