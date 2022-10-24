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
 
 char S[15000];
 int multiply(char a, char b) {
   bool flip = (a < 0) ^ (b < 0);
   a = abs(a);
   b = abs(b);
   int result;
   if (a == 1 || b == 1) {
     result = a * b;
   } else if (a == b) {
     result = -1;
   } else {
     if ((a == 'i' && b == 'k') || (a == 'j' && b == 'i') || (a == 'k' && b == 'j')) {
       flip = !flip;
     }
     result = 3 * 'j' - a - b;
   }
   if (flip) {
     result = -result;
   }
   return result;
 }
 
 void scase() {
   int L, X;
   scanf("%d%d",&L,&X);
   scanf("%s", S);
   FOR(i,1,X) REP(j,L) {
     S[i * L + j] = S[j];
   }
   L *= X;
   
   bool had_i = false;
   bool had_j = false;
   REP(i,L) {
     if (i > 0) {
       S[i] = multiply(S[i-1], S[i]);
     }
     if (S[i] == 'i') {
       had_i = true;
     } else if (had_i && S[i] == multiply('i', 'j')) {
       had_j = true;
     }
   }
   
   bool ok = had_i && had_j && S[L-1] == multiply(multiply('i', 'j'), 'k');
   printf(ok ? "YES\n" : "NO\n");
 }
 
 int main() {
   int Z;
   scanf("%d", &Z);
   REP(z,Z) {
     printf("Case #%d: ", z+1);
     scase();
   }
 }    
