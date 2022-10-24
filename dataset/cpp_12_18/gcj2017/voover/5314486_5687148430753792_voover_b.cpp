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
 
 int N, C, M;
 int by_position[1005];
 int by_customer[1005];
 
 void read_input() {
   scanf("%d%d%d", &N, &C, &M);
   REP(i,1005) by_position[i] = by_customer[i] = 0;
   REP(i,M) {
     int p, c;
     scanf("%d%d", &p, &c);
     --c;
     --p;
     ++by_position[p];
     ++by_customer[c];
   }
 }
 
 void scase() {
   int needed = 0;
   REP(i,C) needed = max(needed, by_customer[i]);
 
   int su = 0;
   REP(i,N) {
     su += by_position[i];
     needed = max(needed, (su + i)/(i+1));
   }
 
   int promotions = 0;
   REP(i,N) promotions += max(0, by_position[i] - needed);
   printf("%d %d\n", needed, promotions);
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
