#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef long long ll;


void solve(){
  int d =in();
  string s;
  cin >> s;
  int n = s.size();
  int cs = 0;
  int cc = 0;
  
  ll charge = 1;
  ll dmg = 0;
  
  for(int i=0;i<n;i++){
    if(s[i]=='C') charge*=2;
    if(s[i]=='S') dmg+=charge;
    
    if(s[i]=='C') cc++;
    if(s[i]=='S') cs++;
  }
  if(cs>d){
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  
  int hacks = 0;
  
  while(dmg>d){
    
    hacks++;
    int ultimo = -1;
    ll cargaactual = 1;
    ll ultimacarga = -1;
    
    for(int i=0;i<n-1;i++){
      if(s[i]=='C') cargaactual*=2;
      
      if(s[i]=='C' && s[i+1]=='S'){
        ultimo = i;
        ultimacarga = cargaactual;
      }
    }
    
    swap(s[ultimo],s[ultimo+1]);
    dmg -=ultimacarga/2;
    
  }
  
  cout << hacks << endl;
  
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1 << ": ";
      solve();
    }
}
