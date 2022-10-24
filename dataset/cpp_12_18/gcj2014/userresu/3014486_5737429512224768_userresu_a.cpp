#include <cstdio>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 bool used[100001];
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     int N,X;
     scanf("%d %d",&N,&X);
     int cnt=0;
     vector<int> v;
     used[0]=0;
     for (int i=1;i<=N;++i) {
         used[i]=0;
         int c;
         scanf("%d",&c);
         if (c>=X) ++cnt;
         else {
             v.push_back(c);
         }
     }
     sort(v.begin(),v.end());
     int i=v.size()-2,j=v.size()-1;
     for (;j>=0;--j) if (!used[j]) {
         used[j]=1;
         for (i=j-1;i>=0;--i) if (!used[i] && v[i]+v[j]<=X) {
             used[i]=1;
             break;
         }
         ++cnt;
     }
     printf("Case #%d: %d\n",z,cnt);
     }
     return 0;
 }
