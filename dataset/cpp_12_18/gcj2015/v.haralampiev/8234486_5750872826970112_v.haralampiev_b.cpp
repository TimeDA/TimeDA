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
 const double EPS = 1E-9;
 void say(int CASE , double t){
   printf("Case #%d: " , CASE);
   if(t < 0) printf("IMPOSSIBLE\n");
   else printf("%.12lf\n" , t);
 }
 void doit(int CASE = 1){
   int N;
   double V , X;
   vector<double> sr , st;
   scanf("%d%lf%lf" , &N , &V , &X);
   sr.resize(N) , st.resize(N);
   for(int i=0;i<N;++i)
    scanf("%lf%lf" , &sr[i] , &st[i]);
   if(N == 1){
    if(X == st[0])
     return say(CASE , V / sr[0]);
    else
     return say(CASE , -1.0);
             }
   else{
    if(st[0] == st[1]){
     if(X == st[0])
      return say(CASE , V / (sr[0] + sr[1]));
     else
      return say(CASE , -1.0);
                      }
    else{
     double L1 = (V * X - V * st[1]) / (st[0] - st[1]);
     if(L1 < -EPS || L1 > V + EPS)
      return say(CASE , -1.0);
     double L2 = V - L1;
     return say(CASE , max(L1 / sr[0] , L2 / sr[1]));
        }
       }
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
