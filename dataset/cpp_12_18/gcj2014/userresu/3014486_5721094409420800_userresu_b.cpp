#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 int A[100001];
 pair<int,int> B[10001];
 bool used[100001];
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     int N; scanf("%d",&N);
     for (int i=1;i<=N;++i) scanf("%d",&A[i]),B[i]=make_pair(A[i],i),used[i]=0;
     sort(B+1,B+N+1);
     int cost=0;
     int x=1,y=N;
     int ans=0;
     for (int i=1;i<=N;++i) {
         int cnt=0;
         for (int j=B[i].second-1;j>=1;--j) if (!used[j]) ++cnt;
         ans += min(cnt,N-i-cnt);
         used[B[i].second]=1;
     }
     printf("Case #%d: %d\n",z,ans);
 }
     return 0;
 }
