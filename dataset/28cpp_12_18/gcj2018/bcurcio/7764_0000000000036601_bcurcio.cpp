#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef pair<int,int> pii;


void solve(){
  int N = in();
  int L = in();
  vector<int> C(L);
  vector<pii> D(L);
  int have = N;
  //~ cerr << have << endl;
  for(int i=0;i<L;i++){
    C[i] = in();
    have -= C[i];
  }
  //~ cerr << have << endl;
  
  if(L==1){
    cout << 100 << endl;
    return;
  }
  
  vector<int> need(N);
  for(int i=1;i<N;i++){
    double v1 = i*100./(N*1.);
    double v2 = (i-1)*100./(N*1.);
    v1 = v1 - int(v1);
    v2 = v2 - int(v2);
    //~ cerr << i << v1 << ' ' << v2 << endl;
    
    if(v1>=0.5 && v2<.5) need[i] = i;
  }
  
  int act = 0;
  for(int i=N-1;i>=0;i--){
    if(need[i]!=0) act = need[i];
    else need[i] = act;
  }
  
  //~ for(int i=0;i<N;i++) cerr << need[i] << ' ';
  //~ cerr << endl;
  
  for(int i=0;i<L;i++) D[i] = pii(need[C[i]]-C[i],i);
  
  sort(D.begin(),D.end());
  
  //~ cerr << " q " << have << endl;
  
  for(int i=0;i<L;i++) if(D[i].first!=0){
    if(have <= 0) continue;
    if(need[0]>0 && D[i].first>need[0]) continue;
    //~ cerr << "f " << D[i].first  << endl;
    
    int gadd = min(have,D[i].first);
    have -= gadd;
    C[D[i].second]+=gadd;
  }
  
  need[0] = max(1,need[0]);
  
  C.push_back(have%need[0]);
  
  
  //~ for(int i=0;i<L;i++) cerr << C[i] << ' ' ; cerr << endl;
  
  int ans = 0;
  //~ cerr << "AS " << endl;
  for(int i=0;i<L;i++){
    //~ cerr << int(double((C[i]*100.)/(N*1.))) << endl;
    ans += int(double((C[i]*100.)/(N*1.))+0.5);
  }
  //~ cerr <<  (have/need[0]) << ' ' << int(double((need[0]*100.)/(N*1.))+0.5) << endl;
  ans += (have/need[0]) * int(double((need[0]*100.)/(N*1.))+0.5);
  
  cout << ans << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<<i+1<<": ";
      solve();
    }
}
