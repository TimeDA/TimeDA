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
 int CASE = 1;
 char T[6][6];
 void doit(int CASE){
   for(int i=0;i<4;++i)
    scanf("%s" , &T[i]);
   bool XW = false , OW = false , DRAW = true;
   for(int i=0;i<4;++i)
    for(int j=0;j<4;++j)
     if(T[i][j] == '.')DRAW = false;
   for(int i=0;i<4;++i){
    bool X = true , O = true;
    for(int j=0;j<4;++j){
     if(T[i][j] != 'X' && T[i][j] != 'T')X = false;
     if(T[i][j] != 'O' && T[i][j] != 'T')O = false;
                        }
    if(X)XW = true;
    if(O)OW = true;
                       }
   for(int j=0;j<4;++j){
    bool X = true , O = true;
    for(int i=0;i<4;++i){
     if(T[i][j] != 'X' && T[i][j] != 'T')X = false;
     if(T[i][j] != 'O' && T[i][j] != 'T')O = false;
                        }
    if(X)XW = true;
    if(O)OW = true;
                       }
   {
    bool X = true , O = true;
    int px = 0 , py = 0;
    for(int i=0;i<4;++i){
     if(T[px][py] != 'X' && T[px][py] != 'T')X = false;
     if(T[px][py] != 'O' && T[px][py] != 'T')O = false;
     ++px , ++py;
                        }
    if(X)XW = true;
    if(O)OW = true;
   }
   {
    bool X = true , O = true;
    int px = 0 , py = 3;
    for(int i=0;i<4;++i){
     if(T[px][py] != 'X' && T[px][py] != 'T')X = false;
     if(T[px][py] != 'O' && T[px][py] != 'T')O = false;
     ++px , --py;
                        }
    if(X)XW = true;
    if(O)OW = true;
   }
   if(XW){
    printf("Case #%d: X won\n" , CASE);
    return;
         }
   if(OW){
    printf("Case #%d: O won\n" , CASE);
    return;
         }
   if(DRAW){
    printf("Case #%d: Draw\n" , CASE);
    return;
           }
   printf("Case #%d: Game has not completed\n" , CASE);
 }
 int main(){
   int Q; scanf("%d" , &Q);
   while(Q-- > 0)
    doit(CASE++);
   return 0;
 }
