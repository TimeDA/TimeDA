#include <iostream>
 #include <cstdio>
 #include <memory.h>
 #include <cstring>
 #include <cmath>
 
 #include <vector>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <algorithm>
 
 #define ABS(a) ((a)<0?-(a):(a))
 #define SIGN(a) ((a)<0?-1:((a)>0?1:0))
 #define SQR(a) ((a)*(a))
 #define MAX(a,b) (((a)>(b))?(a):(b))
 #define MIN(a,b) (((a)<(b))?(a):(b))
 
 #define REP(i, n) for(int i=0; i<(n); ++i)
 #define FOR(i, a, b) for(int i=(a); i<(b); ++i)
 
 #define in ({int x;scanf("%d", &x);x;})
 
 #define PI   (3.1415926)
 #define INF  (2147483647)
 #define INF2 (1073741823)
 #define EPS  (0.000001)
 #define y1 stupid_cmath
 
 typedef long long LL;
 
 using namespace std;
 
 int f(){
     int N, i, S, p, res=0, a;
     cin>>N>>S>>p;
     for(i=0;i<N;++i){
         cin>>a;
         if(a>=p*3-2){
             ++res;
             continue ;
         }
         if(a-p>=0 && p-2>=0 && a>=p*3-4 && S>0){
             --S;
             ++res;
             continue ;
         }
     }
 
     return res;
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 	int T;
 	cin>>T;
 	for(int ii=1;ii<=T;++ii){
         cout<<"Case #"<<ii<<": "<<f()<<endl;
     }
 	return 0;
 }
