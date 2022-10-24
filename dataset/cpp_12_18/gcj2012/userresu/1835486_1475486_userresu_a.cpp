#include <cstdio>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 int T;
 vector<pair<int,int> > v;
 int sz[1001];
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
         v.clear();
         int N;
         scanf("%d",&N);
         for (int i=1;i<=N;++i) scanf("%d",&sz[i]);
         for (int i=1;i<=N;++i) scanf("%d",&sz[i]),v.push_back(make_pair(-sz[i],i));
         sort(v.begin(),v.end());
         printf("Case #%d: ",z);
         for (int i=0;i<v.size();++i) {
             if (i<v.size()-1) printf("%d ",v[i].second-1);
             else printf("%d\n",v[i].second-1);
         }
     }
     return 0;
 }
