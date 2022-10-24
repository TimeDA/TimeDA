#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <set>
 #include <map>
 #include <queue>
 ///#include <priority_queue>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 typedef long long ll;
 typedef pair<int,ll> pii;
 #define FE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 ll MOD = 1000002013LL;
 
 ll func(ll N , ll i){
   if(i==0) return 0;
   return  ((N * i) % MOD - (i*(i-1)/2)%MOD  + 5*MOD)% MOD;
 }
 
 void solve(){
   ///cerr << endl;
   int N = in();
   int M = in();
   int i;
   set<int> stat;
   map<int,ll> entry;
   map<int,ll> exits;
   ll should = 0; 
   for(i=0;i<M;i++){
     int o = in();
     int e = in();
     int p = in();
     stat.insert(o);
     stat.insert(e);
     should = ((should +(p * func(N,e-o))%MOD)) % MOD;
     entry[o] +=p;
     exits[e] +=p;
   }
   
   ll ans = 0;
   priority_queue<pii> pq;
   FE(stat,it){
     int s = *it;
     
     ll u = entry[s];
     ll d = exits[s];
     
     pq.push(pii(s,u));
     
     ///cerr << s <<  ' ' <<  u << ' ' << d << endl;
     
     while(d){
       pii top = pq.top(); pq.pop();
       ll mn = min(d,top.second);
       ans = (ans+(mn*func(N,s-top.first))%MOD)%MOD;
       d -= mn;
       top.second -= mn;
       if(top.second>0) pq.push(top);
     }
     
   }
   ///cerr << should << ' ' << ans << endl;
   cout << (should - ans + 10 * MOD ) % MOD << endl;
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
     printf("Case #%d: ",i+1);
       solve();
   }
 }
