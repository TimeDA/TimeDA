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
 int X , R , C;
 bool DO3(){
   if(C == 1) return false;
   return true;
 }
 bool DO4(){
   if(C < 3) return false;
   return true;
 }
 bool DO5(){
   if(R == 5) return C >= 4 ? true : false;
   if(R%5 != 0) return true;
   return C >= 3 ? true : false;
 }
 int gcd(int a , int b){
   while(b) a %= b , swap(a , b);
   return a;
 }
 bool DO6(){
   if(gcd(R , 6) == 1) return true;
   if(gcd(R , 6) == 3) return C >= 4 ? true : false;
   if(R%6 == 0) return C >= 4 ? true : false;
   return C >= 6 ? true : false;
 }
 bool doit(){
   scanf("%d%d%d" , &X , &R , &C);
   if(R < C) swap(R , C);
   if((R*C) % X != 0) return false;
   if(X >= 7) return false;
   if(R < X) return false;
   if(X == 1) return true;
   if(X == 2) return true;
   if(X == 3) return DO3();
   if(X == 4) return DO4();
   if(X == 5) return DO5();
   if(X == 6) return DO6();
   return true;
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i){
    bool ans = doit();
    printf("Case #%d: " , i);
    if(ans) puts("GABRIEL");
    else puts("RICHARD");
                        }
   return 0;
 }
