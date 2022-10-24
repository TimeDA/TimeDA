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
 
 char M[105][105];
 int first_in_row[105];
 int last_in_row[105];
 int first_in_col[105];
 int last_in_col[105];
 
 void scase() {
   int R,C;
   scanf("%d%d",&R,&C);
   REP(i,R)scanf("%s", M[i]);
   
   REP(i,R) {
     first_in_row[i] = last_in_row[i] = -1;
     REP(j,C) {
       if (M[i][j] == '.') continue;
       if (first_in_row[i] == -1) first_in_row[i] = j;
       last_in_row[i] = j;
     }
   }
   
   REP(j,C) {
     first_in_col[j] = last_in_col[j] = -1;
     REP(i,R) {
       if (M[i][j] == '.') continue;
       if (first_in_col[j] == -1) first_in_col[j] = i;
       last_in_col[j] = i;
     }
   }
   
   int result = 0;
   REP(i,R)REP(j,C) {
     if (first_in_row[i] == j && last_in_row[i] == j && first_in_col[j] == i && last_in_col[j] == i) {
       printf("IMPOSSIBLE\n");
       return;
     }
     if (first_in_row[i] == j && M[i][j] == '<') ++result;
     if (last_in_row[i] == j && M[i][j] == '>') ++result;
     if (first_in_col[j] == i && M[i][j] == '^') ++result;
     if (last_in_col[j] == i && M[i][j] == 'v') ++result;
   }
   
   printf("%d\n", result);
 }
 
 int main() {
   int Z;
   scanf("%d", &Z);
   REP(z,Z) {
     printf("Case #%d: ", z+1);
     scase();
   }
 }    
