#include <bits/stdc++.h>
 using namespace std;
 
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define REP(i,N) FOR(i,0,N)
 #define st first
 #define nd second
 #define pb push_back
 
 typedef pair<int, int> PII;
 typedef long long LL;
 
 int N, P;
 int R[3000];
 int packages[3000][3000];
 
 void read_input() {
   scanf("%d%d", &N, &P);
   REP(i,N) scanf("%d", &R[i]);
   REP(i,N)REP(j,P) scanf("%d", &packages[i][j]);
 }
 
 multiset<PII> kits[3000];
 set<int> possibles;
 
 void scase() {
   REP(i,N) kits[i].clear();
   possibles.clear();
 
   REP(i,N)REP(j,P) {
     // 1.1 * X * R[i] >= packages[i][j] => X >= 10 * packages[i][j] / (R[i] * 11)
     int X = (10 * packages[i][j] + R[i] * 11 - 1) / (R[i] * 11);
     // 0.9 * X * R[i] <= packages[i][j] => X <= packages[i][j] * 10 / (9 * R[i]);
     int Y = (packages[i][j] * 10 / (9 * R[i]));
     if (X <= Y) {
       kits[i].insert(PII(X, Y));
       possibles.insert(X);
       possibles.insert(Y);
     }
   }
 
   int result = 0;
   for (int k: possibles) {
     while (true) {
       REP(i,N) {
         bool found = false;
         for (auto p: kits[i]) if (p.st <= k && k <= p.nd) found = true;
         if (!found) {
           goto not_possible;
         }
       }
 
       REP(i,N) {
         PII best_p = {1e8,1e8};
         for (auto p: kits[i]) if (p.st <= k && k <= p.nd && p.nd < best_p.nd) best_p = p;
         kits[i].erase(kits[i].find(best_p));
       }
       ++result;
     }
 
     not_possible:;
   }
 
   printf("%d\n", result);
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
