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
 
 vector<vector<int>> options[5];
 
 void init() {
   options[2] = {{0}, {1,1}};
   options[3] = {{0}, {1,2}, {1,1,1}, {2,2,2}};
   options[4] = {{0}, {1,3}, {2,3,3}, {1,1,2}, {2,2}, {1,1,1,1}, {3,3,3,3}};
 }
 
 int N, P;
 int G[5];
 void read_input() {
   scanf("%d%d", &N, &P);
   REP(i,P) G[i] = 0;
   REP(i,N) {
     int a;
     scanf("%d", &a);
     G[a%P]++;
   }
 }
 
 void scase() {
   init();
 
   int result = 0;
   for (auto& v: options[P]) {
     bool success = true;
     while (success) {
       REP(i, v.size()) {
         if (!G[v[i]]) {
           success = false;
           REP(j,i) G[v[j]]++;
           break;
         }
         G[v[i]]--;
       }
       if (success) ++result;
     }
   }
 
   REP(i, P) if (G[i]) {
     ++result;
     break;
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
