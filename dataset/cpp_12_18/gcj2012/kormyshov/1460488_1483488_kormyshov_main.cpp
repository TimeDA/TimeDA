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
 
 int f(int a,int b){
     int p=1,res=0,t,tmp;
     while(p<=a)p*=10;
     p/=10;
     for(int i=a;i<=b;++i){
         if(p*10==i)p*=10;
         t=i;
         do{
             tmp=t/p;
             t=(t%p)*10+tmp;
             if(t>i && t<=b) ++res;
         }while(t!=i);
     }
     return res;
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 	int T, A, B;
 	cin>>T;
 	for(int ii=1;ii<=T;++ii){
         cin>>A>>B;
         cout<<"Case #"<<ii<<": "<<f(A,B)<<endl;
 	}
 	return 0;
 }
