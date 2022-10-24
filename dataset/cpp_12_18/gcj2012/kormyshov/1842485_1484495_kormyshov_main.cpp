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
 
 int main(){
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 
 	int T;
 	cin>>T;
 	for(int ii=1;ii<=T;++ii){
 
         int N, W, L;
         cin>>N>>L>>W;
         int i, r[1500], m[1500], t, x[1500], y[1500], mas[1500];
         for(i=0;i<N;++i){
             cin>>r[i];
             m[i]=i;
         }
         for(i=0;i<N-1;++i)
             if(r[i]<r[i+1]){
                 t=r[i];
                 r[i]=r[i+1];
                 r[i+1]=t;
 
                 t=m[i];
                 m[i]=m[i+1];
                 m[i+1]=t;
                 if(i) i-=2;
             }
 
         int l=0;
 
         memset(mas, 0, sizeof(mas));
 
         for(i=1;i<N;++i){
             l+=r[i]+r[i-1];
             if(l>L) break;
         }
         l=i-1;
 
         x[0]=y[0]=0;
         mas[0]=0;
         for(i=1;i<=l;++i){
             x[i]=x[i-1]+r[i]+r[i-1];
             y[i]=0;
             mas[i]=i;
         }
 
         int k=1, j=l+1;
         for(i=l+1;i<N;++i){
             if(k==0){
                 ++j;
                 if(j>l){
                     j=l;
                     k=1;
                 }
             }
             else{
                 --j;
                 if(j<0){
                     j=0;
                     k=0;
                 }
             }
 
             x[i]=x[mas[j]];
             y[i]=y[mas[j]]+r[i]+r[mas[j]];
 
             mas[j]=i;
         }
 
         for(i=0;i<N-1;++i)
             if(m[i]>m[i+1]){
                 t=m[i]; m[i]=m[i+1]; m[i+1]=t;
                 t=x[i]; x[i]=x[i+1]; x[i+1]=t;
                 t=y[i]; y[i]=y[i+1]; y[i+1]=t;
                 if(i) i-=2;
             }
 
         cout<<"Case #"<<ii<<": ";
         for(i=0;i<N;++i) cout<<x[i]<<" "<<y[i]<<" ";
         cout<<endl;
 
 	}
 
 	return 0;
 }
