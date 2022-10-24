#include <cstdio>
 #include <algorithm>
 #include <vector>
 using namespace std;
 typedef long long ll;
 
 ll M,F;
 int N;
 vector<pair<ll,ll> > v;
 ll INF=1;
 int main () {
     for (int i=1;i<=18;++i) INF=INF*10;
     INF++;
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
         v.clear();
     scanf("%lld %lld %d",&M,&F,&N);
     ll a,b;
     ll mn=INF;
     for (int i=1;i<=N;++i) {
         scanf("%lld %lld",&a,&b);
         v.push_back(make_pair(b,a));
         if (mn>a) mn=a;
     }
     sort(v.begin(),v.end());
     ll cost=F,sz=0;
     for (int i=0;i<v.size();++i) {
         while (i && i<v.size() && v[i-1].first==v[i].first) ++i;
         if (i==v.size()) break;
         ll bst=INF;
         for (int j=i;j<v.size();++j) if (v[j].second<bst) {
             bst=v[j].second;
         }
         if (bst>F+mn) {
             break;
         }
         sz=v[i].first+1;
         if (i) cost+=bst*(v[i].first-v[i-1].first);
         else cost+=bst*(v[i].first+1);
     }
     ll cnt=M/cost*sz;
     cost=M/cost*cost+F;
     for (int i=0;i<v.size();++i) {
         while (i && i<v.size() && v[i-1].first==v[i].first) ++i;
         if (i==v.size()) break;
         ll bst=INF;
         for (int j=i;j<v.size();++j) if (v[j].second<bst) {
             bst=v[j].second;
         }
         ll c;
         if (i) c=(v[i].first-v[i-1].first);
         else c=(v[i].first+1);
         if (cost+bst*c<=M) {
             cost+=bst*c;
             cnt+=c;
         }
         else {
             ll k = (M-cost)/bst;
             if (k>0) cnt+=k;
             break;
         }
     }
     printf("Case #%d: %lld\n",z,cnt);
     }
     return 0;
 }
