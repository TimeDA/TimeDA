#include <iostream>
 #include <sstream>
 #include <string>
 #include <algorithm>
 #include <vector>
 #include <stack>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <cassert>
 
 using namespace std;
 
 #define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
 #define REP(i,n) FOR(i,0,n)
 #define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
 
 template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
 inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }
 
 typedef long long ll;
 const int INF = 100000000;
 const double EPS = 1e-8;
 const int MOD = 1000000007;
 int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
 int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
 int N;
 bool used[30];
 int A[30], B[30];
 int X[30];
 bool dfs(int k){
   if(k == N){
     int CA[20] = {};
     int CB[20] = {};
     REP(i, N){
       CA[i] = 1;
       REP(j, i){
         if(X[j] < X[i]) CA[i] = max(CA[i], CA[j] + 1);
       }
     }
     for(int i = N - 1; i >= 0; i--){
       CB[i] = 1;
       for(int j = N - 1; j > i; j--){
         if(X[j] < X[i]) CB[i] = max(CB[i], CB[j] + 1);
       }
     }
     REP(i, N) if(CA[i] != A[i]) return false;
     REP(i, N) if(CB[i] != B[i]) return false;
     REP(i, N) {
       printf("%d", X[i]);
       if(i != N - 1) putchar(' ');
       else putchar('\n');
     }
     return true;
   }
   int BEGIN = 1;
   int END = N; // [B, E]
   for(int i = k - 1; i >= 0; i--){
     if(A[i] < A[k]){
       while(i >= 0 && A[i] + 1 != A[k]){
         i--;
       }
       assert(i >= 0);
       BEGIN = max(BEGIN, X[i] + 1);
       break;
     }else{
       END = min(END, X[i] - 1);
     }
   }
   bool ne = false;
   for(int i = k - 1; i >= 0; i--){
     if(!ne && B[i] == B[k] + 1){
       END = min(END, X[i] - 1);
     }else if(B[i] <= B[k]){
       BEGIN = max(BEGIN, X[i] + 1);
       if(B[i] == B[k]) ne = true;
     }
   }
   /*
   printf("k = %d [%d, %d]: ", k, BEGIN, END);
   if(k > 0)debug(X, X + k);
   else putchar('\n');
   */
   for(int i = BEGIN; i <= END; i++)if(!used[i]){
     //printf("k = %d [%d, %d] put %d\n", k, BEGIN, END, i);
     X[k] = i;
     used[i] = true;
     if(dfs(k + 1)) return true;
     used[i] = false;
   }
   return false;
 }
 
 int main(){
   int T;
   cin >> T;
   REP(CASE, T){
     printf("Case #%d: ", CASE + 1);
     cin >> N;
     REP(i, N) cin >> A[i];
     REP(i, N) cin >> B[i];
     memset(used, 0, sizeof(used));
     dfs(0);
   }
   return 0;
 }
