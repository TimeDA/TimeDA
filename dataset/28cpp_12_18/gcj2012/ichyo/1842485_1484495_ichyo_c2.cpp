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
 double ds(double x, double y){
   return sqrt(x*x + y * y);
 }
 bool ok(vector<double>& x, vector<double>& y, vector<double>& r){
   REP(i, x.size())FOR(j, i+1, x.size()){
     if(ds(x[i]-x[j], y[i]-y[j]) < r[i]+r[j]) return false;
   }
   return true;
 }
 
 int main(){
   int T; cin>>T;
   REP(testcase, T){
     int N, W, L;
     cin>>N>>W>>L;
     vector<double> r(N);
     REP(i, N) cin>>r[i];
     vector<double> x(N);
     vector<double> y(N);
     while(true){
       REP(i, N){
         x[i] = rand() % W;
         y[i] = rand() % L;
       }
       if(ok(x, y, r)){
         break;
       }
     }
     printf("Case #%d: ", testcase + 1);
     REP(i, N){
       printf("%.1lf %.1lf", x[i], y[i]);
       cout<<((i == N-1)?"\n":" ");
     }
   }
   return 0;
 }
 
