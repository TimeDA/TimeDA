#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef pair<int,int> pii;

typedef long long ll;

bool dfs(ll cant, int pos, vector<int> &s, vector<ll> &c,vector<pii> &t){
  if(s[pos]==1) return false;
  
  if(c[pos]>=cant){
    c[pos]-=cant;
    return true;
  }
  
  cant-=c[pos];
  c[pos] = 0;
  
  s[pos] = 1;
  
  bool a1 = dfs(cant,t[pos].first, s,c,t);
  bool a2 = dfs(cant,t[pos].second,s,c,t);
  
  s[pos] = 0;
  
  if(a1 && a2) return true;
  return false;
} 

bool can(ll res, vector<pii> &t, vector<ll> c){
  
  vector<int> seen(c.size(),0);
  return dfs(res,0,seen,c,t);
}

void solve(){
  int M = in();
  vector<pii> trans;
  for(int i=0;i<M;i++){
    int x = in()-1;
    int y = in()-1;
    trans.push_back(pii(x,y));
  }
  
  vector<ll> cant(M);
  ll acum = 0;
  for(int i=0;i<M;i++){
    ll x = in();
    cant[i] = x;
    acum += x;
  }
  
  ll inf = cant[0];
  ll sup = acum+10;
  
  while(inf+1<sup){
    ll mid = (inf+sup)/2;
    if(can(mid,trans,cant)){
      inf = mid;
    }else{
      sup = mid;
    }
  }
  
  //~ assert(inf>=cant[0]);
  //~ assert(inf>=orig);
  cout << inf << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<<i+1<<": ";
      solve();
    }
}
