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
 
 void solve(int test){
     int n,X;
     cin>>n>>X;
     
     vector<int> a(n);
     vector<int> u(n);
     set<pair<int,int> > q;
     for(int i=0;i<n;++i){
         cin>>a[i];
     }
     
     sort(a.begin(), a.end());
     for(int i=0;i<n;++i)
         q.insert(make_pair(a[i], i));
     
     
     int ans = 0;
     for(int i=0;i<n;++i) if(!u[i]){
         q.erase(make_pair(a[i], i));
         ++ans;
         pair<int,int> pp = make_pair(X - a[i], n);
         set<pair<int,int> > :: iterator it = q.lower_bound(pp);
         if(it!=q.begin()){
             --it;
             pp = *it;
             //cout<<"!"<<a[i]<<' '<<pp.first<<endl;
             u[pp.second] = 1;
             q.erase(pp);
         }
     }
     
     cout<<"Case #"<<test<<": ";
     
     cout<<ans;
     
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
 
