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
 
 const LL MOD = 1000002013;
 int N,M;
 int O[2000], E[2000], P[2000];
 
 LL C[3000];
 int D[3000];
 
 LL getV(LL d) {
     return d * N - d * (d - 1) / 2; 
 }
 
 LL get(int a, int b) {
     LL mini = C[a];
     FOR(i,a,b) mini = min(mini, C[i]);
     
     LL result = getV(D[b] - D[a]) * mini % MOD;
     
     int l = -1;
     FOR(i,a,b) {
         C[i] -= mini;
         if (C[i] && l == -1) l = i;
         else if (!C[i] && l != -1) {
             result += get(l,i);
             l = -1;
         }    
     }
     if (l != -1) result += get(l,b);
 
     return result % MOD;
 }
 
 void scase() {
     scanf("%d%d",&N,&M);
     LL A = 0, B = 0;
         
     REP(i,M) {
         scanf("%d%d%d",&O[i],&E[i],&P[i]);
         A += getV(E[i] - O[i]) * P[i] % MOD;
     }
     
     set<int> Se;
     REP(i,M) {
         Se.insert(O[i]);
         Se.insert(E[i]);
     }
     
     int K = 0;
     map<int,int> Ma;
     FOREACH(it, Se) {
         D[K] = *it;
         Ma[*it] = K++;
     }
     
     REP(i,K+3) C[i] = 0;
     REP(i,M) {
         FOR(j,Ma[O[i]], Ma[E[i]]) C[j] += P[i];
     }
     
     B = get(0,K);
     
     printf("%lld\n", ((A - B) % MOD + MOD) % MOD);
 }
 
 int main() {
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 }  
