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
 int R , C , M , F;
 char brd[55][55];
 bool rev;
 void doit(int CASE = 1){
   printf("Case #%d:\n" , CASE);
   scanf("%d%d" , &R , &C);
   scanf("%d" , &M) , F = R*C - M;
   int FC = F;
   rev = false;
   if(C > R) rev = true , swap(R , C);
   for(int i=0;i<R;++i)
    for(int j=0;j<C;++j)
     brd[i][j] = '*';
   bool HAS_SOL = true;
   bool SOLVED = false;
   if(F == 1){
    brd[0][0] = 'c';
    SOLVED = true;
             }
   if(!SOLVED && C == 1){
    for(int i=0;i<F;++i)
     brd[i][0] = '.';
    brd[0][0] = 'c';
    SOLVED = true;
                        }
   if(!SOLVED && C == 2){
    if(F == 2 || F%2 == 1)
     HAS_SOL = false;
    else
     for(int i=0;i<F/2;++i)
      brd[i][0] = brd[i][1] = '.';
    brd[0][0] = 'c';
    SOLVED = true;
                        }
   if(!SOLVED){
    if(FC == 2) HAS_SOL = false;
    SOLVED = true;
    int step = 0;
    for(int i=R-1;i>=0;--i){
     if(F-2 < 0) break;
     F -= 2;
     brd[i][C-2] = brd[i][C-1] = '.';
     step = 1;
                           }
    for(int j=C-3;j>=0;--j)
     for(int i=R-1;i-1>=0;i -= 2){
      if(F-2 < 0) break;
      F -= 2;
      brd[i][j] = brd[i-1][j] = '.';
      step = 2;
                                 }
    for(int j=C-3;j-1>=0;j -= 2){
     if(F-2 < 0) break;
     F -= 2;
     brd[0][j] = brd[0][j-1] = '.';
     step = 3;
                                }
    brd[R-1][C-1] = 'c';
    if(F == 1){
     if(FC == 3 || FC == 5 || FC == 7) HAS_SOL = false;
     else{
      if(step == 3){
       for(int j=C-1;j>=0;--j)
        if(brd[0][j] == '*'){
         brd[0][j] = '.';
         break;
                            }
                   }
      if(step == 1){
       for(int i=0;i<R;++i)
        if(brd[i][C-1] != '*'){
         brd[i][C-1] = brd[i][C-2] = '*';
         brd[R-1][C-3] = brd[R-2][C-3] = '.';
         brd[R-3][C-3] = '.';
         break;
                              }
                   }
      if(step == 2){
       int lc , lr;
       for(lc = 0;lc<C;++lc)
        if(brd[R-1][lc] == '.') break;
       for(lr = 0;lr<R;++lr)
        if(brd[lr][lc] == '.') break;
       if(lr > 1) brd[lr-1][lc] = '.';
       else{
        if(lc == 0) brd[0][C-3] = '.';
        else{
         brd[lr][lc] = '*';
         brd[R-1][lc-1] = '.';
         brd[R-2][lc-1] = '.';
            }
           }
                   }
         }
              }
              }
   if(!HAS_SOL) puts("Impossible");
   else{
    if(!rev)
     for(int i=0;i<R;++i){
      for(int j=0;j<C;++j)printf("%c" , brd[i][j]);
      puts("");
                         }
    else
     for(int j=0;j<C;++j){
      for(int i=0;i<R;++i)printf("%c" , brd[i][j]);
      puts("");
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
