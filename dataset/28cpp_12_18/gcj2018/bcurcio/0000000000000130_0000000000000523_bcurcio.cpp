#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

void solve(){
  int A,B;
  A = in();
  B = in()+1;
  int N = in();
  string s;
  while(1){
    int C = (B-A)/2+A;
    cout << C << endl;
    cin >> s;
    if(s[0]=='C') return;
    if(s[4]=='B'){
      B = C;
    }else{
      A = C;
    }
  }
}

int main(){
  for(int i=0,T=in();i<T;i++)
      solve();
}
