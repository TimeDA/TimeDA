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
 
 bool willWin(LL k, LL N, LL P) {
     if (P <= 0) return false;
     
     if (k == 0) return true;
     return willWin((k-1)/2, N - 1, P - (1LL<< N) / 2);
 }
 
 void scase() {
     LL N, P;
     scanf("%lld%lld",&N,&P);
 
     LL A0 = 0, B0 = (1LL<<N)-1;
     while (A0 < B0) {
         LL S = (A0 + B0 + 1) / 2;
         if (willWin(S,N,P)) A0 = S;
         else B0 = S - 1; 
     }
     
     LL A1 = 0, B1 = (1LL<<N)-1;
     while (A1 < B1) {
         LL S = (A1 + B1 + 1) / 2;
         if (willWin((1LL<<N) - 1 - S,N,(1LL<<N) - P)) B1 = S - 1;
         else A1 = S;
     }
         
     printf("%lld %lld\n", A0, A1);
 }
 
 int main() {
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 }  
