#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

typedef long long ll;

void solve(){
  ll N, K;
  cin >> N >> K;
  K--;

  unordered_map<ll,ll> cant;
  set<ll> have;
  
  cant[N] = 1;
  have.insert(-N);
  
  
  while(K>0){
    ll s = -*have.begin();
    have.erase(have.begin());
    ll t = cant[s];
    //~ cerr << s << ' ' << t << ' ' << K << endl;
    if(t>K){
      have.insert(-s);
      break;
    }else{
      ll s2 = (s-1)/2;
      s = (s-1) - s2;
      //~ cerr <<"   "<< s2 << ' ' << s << endl;
      have.insert(-s2);
      have.insert(-s);
      cant[s]+=t;
      cant[s2]+=t;
      
      K-=t;
      
    }
    
  }
  
  ll ans = (-*have.begin())-1;
  
  ll a2 = ans/2;
  ans = ans-a2;
  
  cout << ans << ' ' << a2 << endl;
  
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
    cout << "Case #"<< i+1 << ": ";
      solve();
    
    }
}
