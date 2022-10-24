
 #include <cstdio>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <cstring>
 #include <cctype>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <list>
 #include <cmath>
 #include <complex>
 #include <numeric>
 #include <cassert>
 using namespace std;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 #define ALLOF(s) ((s).begin()), ((s).end())
 
 
 typedef long long ll;
 
 int n;
 double memo[1 << 20];
 bool visited[1 << 20];
 
 double solve(int pat) {
   double& res = memo[pat];
   if(visited[pat])
     return res;
   visited[pat] = true;
   if(pat == (1 << n)-1){
     res = 0;
   }else{
     res = 0;
     REP(i, n){
       int pos = i;
       int fee = n;
       while(pat & (1 << pos)){
 	pos = (pos + 1) % n;
 	fee--;
       }
       res += (fee + solve(pat | 1 << pos)) / n;
     }
   }
   return res;
 }
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     string s;
     cin >> s;
     int pat = 0;
     n = s.size();
     REP(i, n){
       if(s[i] == 'X')
 	pat |= 1 << i;
     }
     memset(visited, false, sizeof visited);
     printf("Case #%d: %.12f\n", iCase+1, solve(pat));
   }
   
   return 0;
 }
