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
 
 const int N = 1111;
 
 int tn, to[N][26];
 
 int cnt(vector<string>&s){
     tn = 0;
     memset(to[0], 0, sizeof(to[0]));
     ++tn;
     for(int k=0;k<s.size();++k){
         string z = s[k];
         int v = 0;
         for(int i=0;i<z.length();++i){
             int c = z[i]-'A';
             if(!to[v][c]){
                 memset(to[tn], 0, sizeof(to[tn]));
                 to[v][c] = tn++;
             }
             v = to[v][c];
         }
     }
     return tn;
 }
 
 int u[N];
 int ans, num;
 void go(vector<string> s, int i, int m){
     if(i==s.size()){
         int res = 0;
         for(int k=0;k<m;++k){
             vector<string> v;
             for(int i=0;i<s.size();++i) if(u[i]==k) v.push_back(s[i]);
             if(v.empty()) return ;
             res+=cnt(v);
         }
         if(ans<res) ans = res, num = 0;
         if(ans==res) ++num;
         return ;
     }
     for( u[i]=0; u[i]<m; ++u[i]){
         go(s, i+1, m);
     }
 }
 
 void solve(int test){
     
     int n,m;
     cin>>n>>m;
     vector<string> s(n);
     for(int i=0;i<n;++i) cin>>s[i];
     
     
     ans = 0;
     num = 0;
     go(s, 0, m);
     
     cout<<"Case #"<<test<<": ";
     
     cout<<ans<<' '<<num;
     
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
 
