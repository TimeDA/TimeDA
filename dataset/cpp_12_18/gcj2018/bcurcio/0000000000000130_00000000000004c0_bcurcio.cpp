#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

void solve(){
  int N = in();
  vector<pair<int,int>> pi;
  
  for(int i=0;i<N;i++){
    int x = in();
    pi.push_back(make_pair(-x,i));
  }
  
  sort(pi.begin(),pi.end());
  
  while(pi[0].first<pi[1].first){
    cout << char('A'+pi[0].second);
    pi[0].first++;
    if(pi[0].first<pi[1].first){
      cout << char('A'+pi[0].second);
      pi[0].first++;
    }
    cout <<" ";
  }
  
  int iter = 2;
  while(iter<N){
    while(pi[iter].first<0){      
      cout << char('A'+pi[iter].second);
      pi[iter].first++;
      if(pi[iter].first<0){
        cout << char('A'+pi[iter].second);
        pi[iter].first++;
      }
      cout <<" ";
    }
    iter++;
  }
  
  while(pi[0].first<0){
    cout << char('A'+pi[0].second);
    cout << char('A'+pi[1].second);
    pi[0].first++;
    cout << " ";
  }
  
  cout << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
    cout << "Case #"<< i+1 << ": ";
      solve();
    
    }
}
