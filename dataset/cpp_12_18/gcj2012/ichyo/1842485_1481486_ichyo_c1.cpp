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
 bool used[10000][10000];
 int M;
 int rec(int f, int p, vector<int>& x, vector<int>& l){
   if(used[f][p]) return false;
   used[f][p] = true;
   int posdist = x[p] + min(x[p]-x[f], l[p]);
   if(posdist >= M) return true;
   for(int i = p + 1; i < x.size() && x[i] <= posdist; i++){
     if(rec(p, i, x, l)) return true;
   }
   return false;
 }
 
 int main(){
   int T; cin>>T;
   REP(testcase, T){
     memset(used, 0, sizeof(used));
     int N;
     cin>>N;
     vector<int> x;
     vector<int> l;
     x.push_back(0);
     l.push_back(INF);
     REP(i, N){
       int X, L;
       cin>>X>>L;
       x.push_back(X);
       l.push_back(L);
     }
     cin>>M;
     bool ans = rec(0, 1, x, l);
     printf("Case #%d: ", testcase + 1);
     if(ans) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
   }
   return 0;
 }
 
