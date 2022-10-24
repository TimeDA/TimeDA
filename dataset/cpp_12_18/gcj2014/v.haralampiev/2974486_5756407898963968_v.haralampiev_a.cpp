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
 #define BITS(a) __builtin_popcount(a)
 void doit(int CASE){
   int m1 = 0 , m2 = 0;
   int r1 , r2;
   scanf("%d" , &r1);
   for(int i=1;i<=4;++i)
    for(int j=1;j<=4;++j){
     int v; scanf("%d" , &v);
     if(r1 == i) m1 |= (1<<v);
                         }
   scanf("%d" , &r2);
   for(int i=1;i<=4;++i)
    for(int j=1;j<=4;++j){
     int v; scanf("%d" , &v);
     if(r2 == i) m2 |= (1<<v);
                         }
   printf("Case #%d: " , CASE);
   m1 &= m2;
   if(BITS(m1) == 0) puts("Volunteer cheated!");
   else if(BITS(m1) > 1) puts("Bad magician!");
        else{
         int p;
         for(p=1;!(m1&(1<<p));++p);
         printf("%d\n" , p);
            }
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
