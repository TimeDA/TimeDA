#include <bits/stdc++.h>
 using namespace std;
 
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define REP(i,N) FOR(i,0,N)
 #define st first
 #define nd second
 #define pb push_back
 
 typedef pair<int, int> PII;
 typedef long long LL;
 
 map<pair<LL, LL>, LL> _memo;
 LL get(LL N, LL D) {
   auto entry = make_pair(N, D);
   if (_memo.find(entry) != _memo.end()) {
     return _memo[entry];
   }
   if (N < D) return 0;
   LL res = 1 + get((N-1)/2, D) + get(N/2, D);
   return _memo[entry] = res;
 }
 
 LL N, K;
 void read_input() {
   scanf("%lld%lld", &N, &K);
 }
 
 void scase() {
   LL L = 1, R = N;
   while (L < R) {
     LL S = (L + R + 1) / 2;
     if (get(N, S) >= K) {
       L = S;
     } else {
       R = S - 1;
     }
   }
 
   printf("%lld %lld\n", L/2, (L-1)/2);
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
