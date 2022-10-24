#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 
 
 int main(){
     int caseNumber;
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         string s; int K;
         cin>>s>>K;
         int res = 0, bad = 0;
         REP(i, s.size()) {
             if (s[i] == '-') {
                 res++;
                 REP(j, K) {
                     if (i + j < s.size()) {
                         if (s[i + j] == '-') s[i + j] = '+'; else s[i + j] = '-';
                     } else {
                         bad = 1;
                         goto next;
                     }
                 }
             }
         }
         next:;
         if (bad)
             printf("Case #%d: IMPOSSIBLE\n", caseN + 1);
         else
             printf("Case #%d: %d\n", caseN + 1, res);
     }
     return 0;
 }