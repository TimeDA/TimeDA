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
 void doit(int CASE = 1){
   double C , F , X;
   scanf("%lf%lf%lf" , &C , &F , &X);
   double BST = X / 2.0;
   double ctim = 0 , cprod = 2.0;
   int iters = 0;
   for(;;){
    //++iters;
    double ALL = ctim + X / cprod;
    //printf("%.3lf\n" , ALL);
    relaxMin(BST , ALL);
    ctim += C / cprod;
    cprod += F;
    if(ctim >= BST) break;
          }
   printf("Case #%d: " , CASE);
   printf("%.9lf\n" , BST);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
