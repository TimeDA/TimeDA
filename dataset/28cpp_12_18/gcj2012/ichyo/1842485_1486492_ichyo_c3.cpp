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
 
 #define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
 #define REP(i,n) FOR(i,0,n)
 #define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
 
 template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }
 
 typedef long long ll;
 const int INF = 100000000;
 const double EPS = 1e-8;
 const int MOD = 1000000007;
 bool judge(vector<int>& ans, vector<int>& x){
   int N = ans.size();
   REP(i, N - 1){
     double maxh = -INF;
     int maxx = -1;
     FOR(j, i + 1, N){
       int k = j - i;
       double height = (double)(ans[j]-ans[i])/k;
       if(height > maxh){
         maxh = height;
         maxx = j + 1;
       }
     }
     if(x[i] != maxx) return false;
   }
   return true;
 }
 
 int main(){
   int T; cin>>T;
   REP(testcase, T){
     int N;
     cin>>N;
     vector<int> x(N-1);
     REP(i, N-1) cin>>x[i];
     vector<int> ans(N);
     bool ng = false;
     //debug(x.begin(), x.end());
     REP(i, 1000000){
       //debug(ans.begin(), ans.end());
       REP(j, N)ans[j] = rand() % 1000;
       if(judge(ans, x))break;
       if(i == 1000000-1) ng = true;
     }
     printf("Case #%d: ", testcase + 1);
     if(ng) cout<<"Impossible"<<endl;
     else{
       REP(i, N){
         cout<<ans[i];
         cout<<((i == N-1)?"\n":" ");
       }
     }
   }
   return 0;
 }
 
