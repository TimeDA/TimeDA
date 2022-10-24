#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 typedef long long ll;
 
 int N,a[2001],ans[2001];
 vector<vector<int> > v(2001);
 
 bool better (pair<int,int> x,pair<int,int> y) {
     return (ll)x.first*y.second-(ll)x.second*y.first>10e-9;
 }
 
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     scanf("%d",&N);
     for (int i=1;i<=N;++i) v[i].clear();
     for (int i=1;i<N;++i) scanf("%d",&a[i]),v[a[i]].push_back(i);
     for (int i=1;i<=N;++i) ans[i]=0;
     bool ch=1;
     bool ok=1;
     while (ch) {
           ch=0;
     for (int i=2;i<=N;++i) {
         if (!ok) { ch=0; break; }
         for (int j=0;j<v[i].size();++j) {
             int x=v[i][j];
             pair<int,int> best=make_pair(0,-1);
             int bi=-1;
             for (int k=x+1;k<=N;++k) {
                 pair<int,int> cur=make_pair(k-x,ans[k]-ans[x]);
                 if (better(best,cur)) best=cur,bi=k;
             }
             if (bi!=i) ch=1,++ans[i];
             if (ans[i]>10000) { ok=0; ch=0; break;}
         }
     }}
     if (ok) for (int i=1;i<N;++i) for (int j=a[i]+1;j<=N;++j) {
         if (better(make_pair(a[i]-i,ans[a[i]]-ans[i]),make_pair(j-i,ans[j]-ans[i]))) { ok=0; break; }
         }
     printf("Case #%d: ",z);
     if (!ok) printf("Impossible\n");
     else {for (int i=1;i<N;++i) printf("%d ",ans[i]);
     printf("%d\n",ans[N]);}
     }
     return 0;
 }
