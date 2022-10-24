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
 
 int R, C;
 char B[100][100];
 void read_input() {
   scanf("%d%d", &R, &C);
   REP(i,R) scanf("%s", B[i]);
 }
 
 void scase() {
   printf("\n");
 
   REP(i,R) {
     char first = 0;
     REP(j,C) if (B[i][j] != '?') {
       first = B[i][j];
       break;
     }
     if (!first) continue;
     REP(j,C) {
       if (B[i][j] != '?') first = B[i][j];
       else B[i][j] = first;
     }
   }
   FOR(i,1,R) REP(j,C) if (B[i][j] == '?' && B[i-1][j] != '?') B[i][j] = B[i-1][j];
   FORD(i,R-1,0) REP(j,C) if (B[i][j] == '?' && B[i+1][j] != '?') B[i][j] = B[i+1][j];
   REP(i,R) printf("%s\n", B[i]);
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
