#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

void solve(){
  int S = in();
  vector<int> D;
  vector<int> A;
  vector<int> B;
  
  
  
  for(int i=0;i<S;i++){
    D.push_back(in());
    A.push_back(in());
    B.push_back(in());
  }
  
  
  if(S==1){
    cout << 1 <<' ' <<  1 << endl;
    return;
  }
  int maxs = 0;
  int cants = 0;
  
  
  for(int i=0;i<S;i++){
    for(int j=i+1;j<S;j++){
      int M = D[i]+A[i];
      int N = -1000000000;
      bool can = true;
      
      for(int k=i;k<=j;k++){
        if(D[k]+A[k]!=M){
          int act = D[k]-B[k];
          if(N==-1000000000) N = act;
          if(N!=act) can = false;
        }
      }
      
      if(can){
        int curs = j-i+1;
        if(curs==maxs){
          //~ cerr << i << ' ' << j << endl;
          cants++;
        }
        if(curs>maxs){
          maxs = curs;
          cants=1;
        }
      }else{
        N = D[i]-B[i];
        M = -1000000000;
        can = true;
        
        for(int k=i;k<=j;k++){
          if(D[k]-B[k]!=N){
            int act = D[k]+A[k];
            if(M==-1000000000) M = act;
            if(M!=act) can = false;
          }
        }
        
      if(can){
        int curs = j-i+1;
        if(curs==maxs){
          //~ cerr << i << ' ' << j << endl;
          cants++;
        }
        if(curs>maxs){
          maxs = curs;
          cants=1;
        }
      }
        
      }
      
      
    }
  }
  
  cout << maxs << ' ' << cants << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<<i+1<<": ";
      solve();
    }
}
