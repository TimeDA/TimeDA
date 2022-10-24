#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef pair<int,int> pii;


void solve(){
  int n = in();
  
  vector<int> hist(n);
  vector<int> used(n);
  
  for(int i=0;i<n;i++){
    int d = in();
    vector<pii> aux;
    for(int j=0;j<d;j++){
      int x = in();
      hist[x]++;
      aux.push_back(pii(hist[x],x));
    }
    sort(aux.begin(),aux.end());
    int chosen = -1;
    for(int j=0;chosen == -1 && j<aux.size();j++) if(used[aux[j].second] == 0) chosen = aux[j].second;
    if(chosen>=0) used[chosen] = 1;
    cout << chosen << endl;
  }
}

int main(){
  for(int i=0,T=in();i<T;i++){
      //~ cout << "Case #" << i+1<<": ";
      solve();
    }
}
