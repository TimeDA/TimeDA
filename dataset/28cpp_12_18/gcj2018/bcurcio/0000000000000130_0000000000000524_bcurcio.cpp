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

  int D = in();
  int N = in();
  
  double reach_time = 0;
  
  for(int i=0;i<N;i++){
    int k = in();
    int s = in();
    
    reach_time = max(reach_time,(D-k)*1./(1*s));
  }
  
  printf("%.8lf\n",D/reach_time);
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
    cout << "Case #"<< i+1 << ": ";
      solve();
    
    }
}
