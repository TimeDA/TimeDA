#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef long long ll;

int mat[5][100];

void solve(){
  memset(mat,0,sizeof mat);
  int a = in();
  
  int row = 2;
  int col = 2;
  
  cout << row << ' ' << col << endl;
  
  int x,y;
  
  x = in();
  y = in();
  
  while(x!=0){
    
    mat[x][y] = 1;
    
    while(mat[1][col-1] == 1 && mat[2][col-1] == 1 && mat[3][col-1] == 1) col++; 
    
    cout << row << ' ' << col << endl;
    
    x = in();
    y = in();
  }
  
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      solve();
    }
}
