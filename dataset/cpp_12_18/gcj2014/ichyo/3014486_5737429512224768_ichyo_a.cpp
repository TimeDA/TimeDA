#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 int main(){
     int T;
     cin >> T;
     for(int casenum = 1; casenum <= T; casenum++) {
         printf("Case #%d: ", casenum);
         int N, L;
         cin >> N >> L;
         vector<int> v(N);
         REP(i, N) cin >> v[i];
         sort(v.begin(), v.end());
         int b = 0;
         int ans = 0;
         for(int i = N - 1; i >= 0; i--) {
             if(b > i) {
                 break;
             }
             ans++;
             if(v[b] + v[i] <= L) {
                 b++;
             }
         }
         cout << ans << endl;
     }
     return 0;
 }
 
