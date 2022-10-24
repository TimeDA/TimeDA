#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

typedef long long ll;

void solve(){
  int n = in();
  vector<int> w(n);
  for(int i=0;i<n;i++) w[i] = in();
  
  int last = 0;
  ll ooo = 1000000000;
  ooo = ooo*ooo;
  
  vector<ll> best(n+5,ooo);
  best[0] = 0;
  
  for(int i=0;i<n;i++){
    int inf = 0;
    int sup = last+1;
    //~ cerr <<"is " <<  inf << " " << sup << endl;
    
    while(inf+1<sup){
      int mid = (inf+sup)/2;
      //~ cerr <<inf << ' ' << sup <<  " " << mid << endl;
      
      if(best[mid]<=w[i]*6){
        inf = mid;
      }else{
        sup = mid;
      }
    }
    
    //~ cerr <<inf << ' ' <<  best[inf+1] << endl;
    if(best[inf+1] > best[inf]+w[i]){
      best[inf+1] = best[inf]+w[i];
      if(inf+1>last) last = inf+1;
    } 
    
  }
  
  cout << last << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1<<": ";
      solve();
    }
}
