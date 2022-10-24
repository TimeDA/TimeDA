#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}


void solve(){
  int c = in();
  vector<vector<int>>  g(2,vector<int>(c,1));
  
  vector<int> b(c);
  for(int i=0;i<c;i++) b[i] = in();
  
  vector<string> ans;
  
  if(b[c-1]==0){
      cout << "IMPOSSIBLE" << endl;
      return;
  }
  
  for(int i=0;i<c*c+2;i++){
    
    bool done = true;
    for(int j=0;j<c;j++) if(b[j]!=g[i%2][j]) done = false;
    
    if(done){
      
      string cur2;
      for(int j=0;j<c;j++) cur2+=".";
      ans.push_back(cur2);
      
      cout << ans.size() << endl;
      
      for(int j=0;j<(int)ans.size();j++){
        cout << ans[j] << endl;
      }
      
      return;
    }
    
    if(b[0]<g[i%2][0]){
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    
    string cur = ".";
    
    bool cansl = true;
    
    for(int j=0;j<c;j++) g[(i+1)%2][j] = g[i%2][j];
    
    int acum = b[0] - g[i%2][0];
    
    for(int j=1;j<c-1;j++){
      //~ cerr << acum << " " ;
      
      if(cansl && acum>0 && g[i%2][j]==1){
        g[(i+1)%2][j-1] = g[(i+1)%2][j-1] + 1;
        g[(i+1)%2][j] = g[(i+1)%2][j] - 1;
        cur+="/";
        cansl = true;
        acum = acum - 1 + b[j];
      }else{
        
        acum += b[j] - g[(i+1)%2][j];
        if(acum < 0 && g[i%2][j]==1){
          g[(i+1)%2][j] = g[(i+1)%2][j] - 1 ;
          g[(i+1)%2][j+1] = g[(i+1)%2][j+1] + 1;
          cur+="\\";
          cansl = false;
        }else{
          cur+=".";
          cansl = true;
        }
      }
      
    }
    
    //~ cerr << acum << endl;
    
    acum += b[c-1] - g[(i+1)%2][c-1];
    if(acum!=0){
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    cur+=".";
    
    ans.push_back(cur);
    
    
    
  } 
  
  cout << "IMPOSSIBLE" << endl;
  

}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1<<": ";
      solve();
    }
}
