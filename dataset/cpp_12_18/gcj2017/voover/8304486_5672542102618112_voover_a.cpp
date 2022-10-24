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
 
 char S[100];
 int frac[20];
 
 void read_input() {
   scanf("%s", S);
 }
 
 int tmp[20];
 void scase() {
   frac[0] = 1;
   FOR(i,1,10) frac[i] = i * frac[i-1];
 
   int L = strlen(S);
   int init = atoi(S);
 
   set<int> achievable, achievable2;
   queue<int> Q;
   achievable.insert(init);
   Q.push(init);
   int additional = 0;
 
   while (!Q.empty()) {
     int k = Q.front();
     int l = k;
     Q.pop();
 
     int s = 0;
     REP(i,L) {
       tmp[L-i] = k % 10;
       s += tmp[L-i];
       k /= 10;
     }
 
     if (s > L) continue;
 
     int p = 0;
     REP(i,L-s) S[p++] = '0';
     int s2 = 0;
     FOR(i,1,L+1)REP(j, tmp[i]) {
       S[p++] = '0' + i;
       s2 += i;
     }
     if (s2 > L) {
       int v2 = atoi(S);
       if (achievable2.find(v2) != achievable2.end()) {
         continue;
       }
       achievable2.insert(v2);
 
       int tmpa = frac[L];
       tmpa /= frac[L-s];
       FOR(i,1,L+1) tmpa /= frac[tmp[i]];
       additional += tmpa;
 
       continue;
     }
 
     do {
       int v = atoi(S);
       if (achievable.find(v) == achievable.end()) {
         achievable.insert(v);
         Q.push(v);
         if (achievable.size() > 100000 || Q.size() > 100000) exit(0);
       }
     } while (next_permutation(S, S+L));
   }
 
   printf("%d\n", additional + (int)achievable.size());
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
