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
 string itos(int n){
   stringstream ss;
   ss<<n;
   return ss.str();
 }
 
 int main(){
   int A,B;
   int cas = 1;
   int N; cin>>N;
   while(N--){
     printf("Case #%d: ",cas++);
     cin>>A>>B;
     int ans = 0;
     for(int a = A; a < B; a++){
       for(int b = a + 1; b <= B; b++){
         bool ok = false;
         string s1 = itos(a);
         string s2 = itos(b);
         for(int i = 1; i < s1.size(); i++){
           string s3 = s1.substr(i) + s1.substr(0, i);
           if(s3 == s2) ok = true;
         }
         if(ok) ans ++;
       }
     }
     cout<<ans<<endl;
   }
   return 0;
 }
 
