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
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 
 	int T;
 	cin>>T;
 	for(int ii=1;ii<=T;++ii){
 
         int N;
         cin>>N;
         int d[11000], l[11000], i, j;
         for(i=0;i<N;++i) cin>>d[i]>>l[i];
         int D;
         cin>>D;
         d[N]=D;
         l[N]=0;
 
         int m[11000], mm;
         memset(m,-1,sizeof(m));
         m[0]=d[0];
         for(i=0;i<N;++i){
             if(m[i]<0) break;
             for(j=i+1;j<=N && d[j]-d[i]<=m[i];++j){
                 mm=MIN(d[j]-d[i],l[j]);
                 if(mm>m[j]) m[j]=mm;
             }
 
         }
         if(m[N]<0) cout<<"Case #"<<ii<<": NO\n";
         else cout<<"Case #"<<ii<<": YES\n";
 	}
 
 	return 0;
 }
