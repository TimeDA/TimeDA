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
 
 LL X[200];
 LL me[200];
 
 void scase() {
     LL B;
     int N;
     scanf("%lld%d",&B,&N);
     REP(i,N) scanf("%lld",&X[i]);
     FOR(i,N,37) X[i] = 0;    
     
     N = 37;
     REP(i,N) me[i] = 0;
     
     double result = 0.0;
     REP(b,B) {
         int mi = 0;
         REP(i,N) if (X[i] < X[mi]) mi = i;
         X[mi]++;
         me[mi]++; 
     
         REP(i,N) if (X[i] < X[mi]) mi = i;
         
         LL stake = 0, cnt = 0;
         REP(i,N) {
             if (X[i] != X[mi]) continue;
             
             stake += me[i];
             cnt ++;
         }
         
         result = max(result, stake * (36.0 / cnt) - b - 1);
     }
     
     printf("%0.10lf\n", result);
 }
 
 int main() {
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 }  
