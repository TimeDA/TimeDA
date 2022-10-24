#include <cstdio>
 #include <vector>
 #include <functional>
 #include <algorithm>
 using namespace std;
 
 const int MAXN = 1010;
 const int INF = 1e9;
 int a[MAXN];
 int L[MAXN], R[MAXN];
 int dp[MAXN][MAXN];
 int rankk[MAXN];
 
 int main() {
   int T, n;
   scanf("%d", &T);
   for (int ca = 1 ; ca <= T ; ++ca) {
     scanf("%d",&n);
     vector<pair<int,int> > tmp;
     for (int i = 0 ; i < n ; ++i) {
       scanf("%d", &a[i]);
       tmp.push_back(make_pair(a[i], i));
     }
     sort(tmp.begin(), tmp.end(), greater<pair<int,int> >());
     for (int i = 0 ; i < n ; ++i)
       rankk[i] = tmp[i].second;
 
     memset(L, 0, sizeof(L));
     memset(R, 0, sizeof(R));
     for (int i = 0 ; i < n ; ++i) {
       for (int j = 0 ; j < i ; ++j)
         if (a[j] > a[i]) ++L[i];
       for (int j = i + 1 ; j < n ; ++j)
         if (a[j] > a[i]) ++R[i];
     }
     memset(dp, 0x3f, sizeof(dp));
     for (int i = 0 ; i < n ; ++i)
       dp[i][i] = 0;
     for (int len = 1 ; len <= n ; ++len) {
       for (int left = 0 ; left < n ; ++left) {
         int right = left + len - 1;
         if (dp[left][right] >= INF) continue;
         
         int nextIndex = rankk[len];
         if (right+1 < n)
           dp[left][right+1] = min(dp[left][right+1], dp[left][right] + R[nextIndex]);
         if (left-1 >= 0)
           dp[left-1][right] = min(dp[left-1][right], dp[left][right] + L[nextIndex]);
       }
     }
     printf("Case #%d: %d\n", ca, dp[0][n-1]);
   }
   return 0;
 }
 
