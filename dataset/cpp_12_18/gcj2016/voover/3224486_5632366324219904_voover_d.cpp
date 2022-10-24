#include <algorithm>
 #include <cstdio>
 #include <cstdlib>
 #include <list>
 #include <map>
 #include <queue>
 #include <set>
 #include <stack>
 #include <vector>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <complex>
 #include <sstream>
 using namespace std;
  
 typedef long long LL;
 typedef unsigned long long ULL;
 typedef long double LD;
 typedef vector<int> VI;
 typedef pair<int,int> PII;
  
 #define REP(i,n) for(int i=0;i<(n);++i)
 #define SIZE(c) ((int)((c).size()))
 #define FOR(i,a,b) for (int i=(a); i<(b); ++i)
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 #define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
 #define ALL(v) (v).begin(), (v).end()
  
 #define pb push_back
 #define mp make_pair
 #define st first
 #define nd second
 
 void scase() {
   int N, L;
   cin >> N >> L;
   vector<string> good;
   string bad;
   REP(i, N) {
     string tmp;
     cin >> tmp;
     good.pb(tmp);
   }
   cin >> bad;
   REP(i, N) {
     if (good[i] == bad) {
       printf("IMPOSSIBLE\n");
       return;
     }
   }
   
   int K = bad.size();
   if (K == 1) {
     printf("0 ?\n");
     return;
   }
   printf("??");
   REP(i, K - 1) {
     printf("1??");
   }
   printf(" ");
   REP(i, K) printf("0");
   printf("\n");
 }
 
 int main() {
 //  REP(i, R) randomized[i] = rand();
 
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 } 
 
