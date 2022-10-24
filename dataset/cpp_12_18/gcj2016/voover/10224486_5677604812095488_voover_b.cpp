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
 
 int N, K;
 double P[300];
 
 double DP[300][300];
 
 double get() {
   DP[0][0] = 1.0;
   REP(i,K) {
     REP(j,K) {
       DP[i+1][j] = DP[i][j] * (1 - P[i]);
       if (j > 0) DP[i+1][j] += DP[i][j-1] * P[i];
     }
   }
   return DP[K][K / 2];
 }
 
 double _P[300];
 
 void scase() {
   scanf("%d%d", &N, &K);
   REP(i,N)scanf("%lf", &_P[i]);
   sort(_P, _P+N);
 
   double result = 0.0;
   REP(i,K+1) {
     REP(j,i) P[j] = _P[j];
     REP(j,K - i) P[K-1-j] = _P[N-1-j];
     result = max(result, get());
   }
   printf("%0.9lf\n", result);
 }
 
 int main() {
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 } 
