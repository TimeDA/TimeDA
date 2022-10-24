#include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <cmath>
 #include <memory.h>
 using namespace std;
 typedef long long ll;
 
 const int N = 1e6+6;
 
 vector<int> f;
 void add(int i, int x){
     for(;i<f.size();i|=i+1) f[i]+=x;
 }
 
 int sum(int i){
     int s = 0;
     for(;i>=0; i=(i&(i+1))-1) s+=f[i];
     return s;
 }
 
 int calc(vector<int> a){
     int n = a.size();
     f.clear();
     f.assign(n, 0);
     vector<pair<int,int> > v(n);
     for(int i=0;i<n;++i) v[i] = make_pair(a[i], i);
     sort(v.begin(), v.end());
     int res = 0;
     for(int i=n-1;i>=0;--i){
         int k = v[i].second;
         res+=sum(k);
         add(k,1);
     }
     //for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<": "<<res<<endl;
     return res;
 }
 
 
 int solve2(vector<int> a){
     int n = a.size();
     int mx = *max_element(a.begin(), a.end());
     
     map<vector<int>, int> u;
     u[a] = 0;
     vector<vector<int> > q;
     q.push_back(a);
     for(int k=0;k<q.size();++k){
         vector<int> v = q[k];
         int dist = u[v];
         bool ok = true;
         for(int i=0;i<n;++i) if(v[i]==mx){
             for(int j=i-1;ok&&j>=0;--j) if(v[j]>v[j+1]) ok=false;
             for(int j=i+1;ok&&j<n;++j) if(v[j]>v[j-1]) ok=false;
             break;
         }
         if(ok) return dist;
         
         for(int i=1;i<n;++i){
             swap(v[i], v[i-1]);
             if(!u.count(v)){
                 u[v] = dist+1;
                 q.push_back(v);
             }
             swap(v[i], v[i-1]);
         }
     }
 }
 
 void solve(int test){
     
     int n;
     cin>>n;
     
     vector<int> a(n);
     for(int i=0;i<n;++i) cin>>a[i];
     
     int ans = n*n;
     for(int k=0;k<=n;++k){
         int res = 0;
         vector<int> b(a.begin(), a.begin()+k);
         res+=calc(b);
         b = vector<int>(a.begin()+k, a.end());
         reverse(b.begin(), b.end());
         res+=calc(b);
         ans = min(ans, res);
     }
     
     
     cout<<"Case #"<<test<<": ";
     
     int ans2 = solve2(a);
     
     /*if(1 ||ans!=ans2){
     for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<": ";
     cout<<ans<<' '<<ans2;
     }*/
     cout<<ans2;
     
     cout<<endl;
 }
 
 int main(){
     freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
     
     int tn;
     cin>>tn;
     for(int ti=1;ti<=tn;++ti){
         cerr<<"\t\t"<<ti<<"..."<<endl;
         solve(ti);
         cerr<<"\t\t"<<ti<<" ok."<<endl;
     }
     
     
     return 0;
 }
 
