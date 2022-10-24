#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 int main(){
     int T;
     cin >> T;
     for(int casenum = 1; casenum <= T; casenum++) {
         printf("Case #%d: ", casenum);
         int N;
         cin >> N;
         vector<int> A(N);
         REP(i, N) cin >> A[i];
         vector<pair<int, int>> P(N);
         REP(i, N) P[i] = make_pair(A[i], i);
         sort(P.begin(), P.end());
         vector<bool> used(N);
         int ans = 0;
         for(int i = 0; i < N; i++) {
             int k = P[i].second;
             int left = 0, right = 0;
             for(int j = 0; j < k; j++) {
                 if(!used[j]) {
                     left++;
                 }
             }
             for(int j = N - 1; j > k; j--) {
                 if(!used[j]) {
                     right++;
                 }
             }
             used[k] = true;
             // cout << left << " " << right << endl;
             ans += min(left, right);
         }
         cout << ans << endl;
     }
     return 0;
 }
 
