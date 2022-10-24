#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}


void solve(){
  int N  = in();
  vector<vector<int>> mat(N,vector<int>(N));

  for(int i=0;i<N;i++) for(int j=0;j<N;j++){
    mat[i][j] = in();
  }
  
  int m = N*N;
  
  int ans = m;
  
  for(int z=0;z<(1<<m);z++){
    int cnt = __builtin_popcount(z);
    if(cnt>ans) continue;
    
    bool can = true;
    //~ cerr << z << endl;
    for(int i=0;can && i<N;i++){
      for(int j=0;can && j<N;j++){
        int n1 = i*N+j;
        //~ cerr << " m " << n1 << endl;
        if(z&(1<<n1)) continue;
        //~ cerr << i << ' ' << j << endl;
        for(int k=0;k<N;k++){
          int n2 = i*N+k;
          if(n1!=n2 && (z&(1<<n2))==0 && mat[i][j]==mat[i][k]) can = false;
          
          n2 = k*N+j;
          if(n1!=n2 && (z&(1<<n2))==0 && mat[i][j]==mat[k][j]) can = false;
        }
      }
    }
    //~ cerr << "*** " << endl;
    if(can){
      //~ cerr << z << endl;
      ans = min(cnt,ans);
    }
    
    
    
  }
  
  cout << ans << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1<<": ";
      solve();
    }
}
