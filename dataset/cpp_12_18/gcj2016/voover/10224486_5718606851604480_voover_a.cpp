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
 
 vector<string> data[13];
 
 int cnt[256];
 
 void scase() {
   int N, R, P, S;
   scanf("%d%d%d%d", &N, &R, &P, &S);
   
   REP(j,3) {
     cnt['R'] = cnt['P'] = cnt['S'] = 0;
     REP(i, (1<<N)) cnt[data[N][j][i]]++;
     if (cnt['R'] == R && cnt['P'] == P && cnt['S'] == S) {
       printf("%s\n", data[N][j].c_str());
       return;
     }
   }
   printf("IMPOSSIBLE\n");
 }
 
 int main() {
   data[0].push_back("P");
   data[0].push_back("R");
   data[0].push_back("S");
   FOR(i,1,13) {
     REP(j,3) {
       int j2 = (j + 1) % 3;
       if (data[i-1][j] < data[i-1][j2]) data[i].push_back(data[i-1][j] + data[i-1][j2]);
       else data[i].push_back(data[i-1][j2] + data[i-1][j]);
     }
     sort(data[i].begin(), data[i].end());
   }
 
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 } 
