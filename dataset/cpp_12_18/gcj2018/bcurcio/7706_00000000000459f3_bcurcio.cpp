#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}


void solve(){
  int R = in();
  int B = in();
  
  vector<vector<vector<int>>> mat(2,vector<vector<int>>(R+1,vector<int>(B+1,-1)));
  
  mat[1][0][0] = 0;
  
  int iter = 0;
  
  for(int c=1;c<=min(34,B+R);c++){
    for(int i=0;i<=c;i++){
      //~ cerr << i << endl;
      int cr = i;
      int cb = c-cr;
      //~ if(c<=3) cerr << i << ' ' <<  cr << ' ' << cb << endl;
      //~ else break;
      iter++;
      
      
      for(int j=0;j<R+1;j++){
        for(int k=0;k<B+1;k++){
          mat[(iter+1)%2][j][k] = mat[iter%2][j][k];
        }
      }
      for(int j=0;j<R+1;j++){
        for(int k=0;k<B+1;k++) if(j+cr<=R && k+cb<=B && mat[iter%2][j][k]!=-1){
          mat[(iter+1)%2][j+cr][k+cb] = max(mat[(iter+1)%2][j+cr][k+cb],mat[iter%2][j][k]+1);
        }
      }
      
      //~ for(int j=0;j<R+1;j++){
        //~ for(int k=0;k<B+1;k++){
          //~ cerr << mat[(iter+1)%2][j][k] << ' ';
        //~ }
        //~ cerr << endl;
      //~ }
    }
  }
  
  iter++;
  
  int ans = 0;
  for(int i=0;i<=R;i++){
    for(int j=0;j<=B;j++){
      int cant = mat[iter%2][i][j];
      //~ 
      //~ int db = B-j;
      //~ int dr = R-i;
      //~ if(db>dr) swap(db,dr);
      //~ 
      //~ int rst = 10;
      //~ while(dr>=rst){
        //~ dr-=rst;
        //~ rst+=1;
        //~ cant+=1;
      //~ }
      
      ans = max(ans,cant);
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
