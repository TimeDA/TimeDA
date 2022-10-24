#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 int N,W,L;
 pair<int,int> a[1001];
 pair<int,int> res[1001];
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     scanf("%d %d %d",&N,&W,&L);
     for (int i=1;i<=N;++i) scanf("%d",&a[i].first),a[i].first=-a[i].first,a[i].second=i;
     sort(a+1,a+N+1);
     for (int i=1;i<=N;++i) a[i].first=-a[i].first;
     int x=0,y=0,save=a[1].first;
     printf("Case #%d: ",z);
     for (int i=1;i<=N;++i) {
         res[a[i].second]=make_pair(x,y);
         if (i<N) {
            y+=a[i].first+a[i+1].first;
            if (y>L) y=0,x=x+save+a[i+1].first,save=a[i+1].first;
         }
     }
     for (int i=1;i<N;++i) printf("%d %d ",res[i].first,res[i].second);
     printf("%d %d\n",res[N].first,res[N].second);
     }
     return 0;
 }
