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
 
 int N;
 char A[30][30];
 char B[30][30];
 
 int masks[30];
 int bits[100];
 
 bool has_matching(int bad_i, int bad_j) {
   REP(m, (1<<N)) {
     if ((1<<bad_j)&m) continue;
     
     int M = 0;
     int cnt = 0;
     REP(j,N) {
       if ((1<<j)&m) {
         ++cnt;
         M |= masks[j];
       }
     }
     
     M &= ~(1<<bad_i);
 
     if (bits[M] < cnt) return false;
   }
 
   return true;
 }
 
 bool is_good() {
   REP(j,N) masks[j] = 0;
   REP(i,N)REP(j,N) if (B[i][j]) masks[j] |= (1<<i);
  
   if (!has_matching(N,N)) return false;
   REP(i,N)REP(j,N) if (!B[i][j] && has_matching(i,j)) return false;
   return true;
 }
 
 void scase() {
   scanf("%d", &N);
   REP(i,N) {
     scanf("%s", A[i]);
     REP(j,N) A[i][j] -= '0';
   }
   
   int result = N * N;
 
   REP(mask, (1<<(N*N))) {
     int mask2 = mask;
     REP(i,N)REP(j,N) {
       B[i][j] = mask2&1;
       mask2 >>= 1;
     }
     int added = 0;
     REP(i,N)REP(j,N) if(!B[i][j] && A[i][j]) goto fail;
     else if (B[i][j] && !A[i][j]) ++added;
 
     if (is_good()) {
       result = min(result, added);
     }
     
     fail:;
   }  
   
   printf("%d\n", result);
 }
 
 int main() {
     FOR(i,1,100) bits[i] = (i % 2) + bits[i / 2];
 
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 } 
