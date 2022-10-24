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
 
 void run(){
     int N, i, j;
     cin>>N;
     int m1[1500], m2[1500], m3[1500];
     for(i=0;i<N;++i) cin>>m1[i];
     for(i=0;i<N;++i) cin>>m2[i];
     for(i=0;i<N;++i) m3[i]=i;
     for(i=0;i<N-1;++i)
         if(m2[i]<m2[i+1] || (m2[i]==m2[i+1] && m1[i]>m1[i+1])){
             j=m1[i]; m1[i]=m1[i+1]; m1[i+1]=j;
             j=m2[i]; m2[i]=m2[i+1]; m2[i+1]=j;
             j=m3[i]; m3[i]=m3[i+1]; m3[i+1]=j;
             if(i) i-=2;
         }
     for(i=0;i<N;++i) cout<<m3[i]<<" ";
     cout<<endl;
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
     int T;
     cin>>T;
     for(int ii=1;ii<=T;++ii){
         cout<<"Case #"<<ii<<": ";
 //        printf("Case #%d: ",ii);
         run();
     }
 	return 0;
 }
