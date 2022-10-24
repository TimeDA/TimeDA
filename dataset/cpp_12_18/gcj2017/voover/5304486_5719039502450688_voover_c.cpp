#include <bits/stdc++.h>
 using namespace std;
 
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define REP(i,N) FOR(i,0,N)
 #define st first
 #define nd second
 #define pb push_back
 
 typedef pair<int, int> PII;
 typedef long long LL;
 
 const LL INF = 1e15;
 
 LL simulate(int H, int HD, int AK, int attacks_needed) {
   if (attacks_needed == 1) return 1;
   if (H > AK) return 1 + simulate(H - AK, HD, AK, attacks_needed - 1);
   if (H == HD - AK) return INF;
   return 1 + simulate(HD - AK, HD, AK, attacks_needed);
 }
 
 int HD, AD, HK, AK, B, D;
 void read_input() {
   scanf("%d%d%d%d%d%d", &HD, &AD, &HK, &AK, &B, &D);
 }
 
 void scase() {
   int attacks_needed = (HK + AD-1) / AD;
   if (B > 0) {
     for (int i = 1; i < attacks_needed; ++i) {
       LL buffed = AD + B * (LL)i;
       attacks_needed = min((LL)attacks_needed, i + (HK + buffed - 1) / buffed);
     }
   }
 
   LL result = INF;
 
   LL H = HD, A = AK, moves = 0;
   while (true) {
     result = min(result, moves + simulate(H, HD, A, attacks_needed));
     if (D == 0 || A == 0) break;
 
     if (H > max(0LL, A - D)) {
       A = max(0LL, A - D);
       H -= A;
     } else if (H < HD - A) {
       H = HD - A;
     } else {
       break;
     }
 
     ++moves;
   }
 
   if (result == INF) {
     printf("IMPOSSIBLE\n");
   } else {
     printf("%lld\n", result);
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
