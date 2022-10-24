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
 int R , C;
 char in[110][110];
 bool is_in(int x , int y){
   return x >= 0 && x < R &&
          y >= 0 && y < C;
 }
 pii dir(char w){
   if(w == '>') return mp(0 , 1);
   if(w == '<') return mp(0 , -1);
   if(w == 'v') return mp(1 , 0);
   if(w == '^') return mp(-1 , 0);
 }
 bool go(int i , int j , pii d){
   for(;;){
    i += d.fi , j += d.se;
    if(!is_in(i , j)) return false;
    if(in[i][j] != '.') return true;
          }
 }
 char on[] = "><^v";
 void doit(int CASE = 1){
   scanf("%d%d" , &R , &C);
   for(int i=0;i<R;++i)
    scanf("%s" , &in[i][0]);
   int ANS = 0;
   for(int i=0;i<R;++i)
    for(int j=0;j<C;++j){
     if(in[i][j] == '.') continue;
     if(go(i , j , dir(in[i][j]))) continue;
     bool fine = false;
     for(int p=0;p<4;++p)
      if(go(i , j , dir(on[p]))){
       fine = true; break;
                                }
     if(!fine){ANS = -1; goto END;}
     ++ANS;
                        }
   END:;
   printf("Case #%d: " , CASE);
   if(ANS < 0) printf("IMPOSSIBLE\n");
   else printf("%d\n" , ANS);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
