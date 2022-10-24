#ifdef _WIN32
 #  define LL "%I64d"
 #else
 #  define LL "%Ld"
 #endif
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <cstring>
 #include <ctime>
 #include <vector>
 #include <deque>
 #include <set>
 #include <map>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <string>
 #include <algorithm>
 #include <complex>
 #include <utility>
 #include <cassert>
 using namespace std;
 #define null NULL
 #define mp make_pair
 #define pb(a) push_back(a)
 #define sz(a) ((int)(a).size())
 #define all(a) a.begin() , a.end()
 #define fi first
 #define se second
 #define relaxMin(a , b) (a) = min((a),(b))
 #define relaxMax(a , b) (a) = max((a),(b))
 #define SQR(a) ((a)*(a))
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 #define MOD 1000000007
 int ANS = -1;
 int CNT = 0;
 int M , N;
 vector<string> in;
 char buf[110];
 vector<string> part[10];
 int lcp(string a , string b){
   int ret = 0;
   for(int i=0;i<min(sz(a) , sz(b));++i)
    if(a[i] != b[i]) break;
    else ++ret;
   return ret;
 }
 void eval(){
   for(int i=0;i<N;++i)
    if(part[i].empty()) return;
   int cc = N;
   for(int i=0;i<N;++i){
    for(int j=0;j<sz(part[i]);++j){
     cc += sz(part[i][j]);
     if(j > 0) cc -= lcp(part[i][j-1] , part[i][j]);
                                  }
                       }
   if(cc > ANS) ANS = cc , CNT = 0;
   if(cc == ANS) ++CNT;
 }
 void go(int pos){
   if(pos >= M){
    eval();
    return;
               }
   for(int i=0;i<N;++i){
    part[i].pb(in[pos]);
    go(pos + 1);
    part[i].pop_back();
                       }
 }
 void doit(int CASE = 0){
   ANS = 0;
   CNT = 0;
   scanf("%d%d" , &M , &N);
   for(int i=0;i<N;++i)
    part[i].clear();
   in.clear();
   for(int i=0;i<M;++i){
    scanf("%s" , &buf);
    in.pb(string(buf));
                       }
   sort(all(in));
   go(0);
   printf("Case #%d: %d %d\n" , CASE , ANS , CNT);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
