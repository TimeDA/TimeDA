#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef long long ll;

int arr0[112345];
int arr1[112345];

void solve(){
  int n = in();
  
  int last0 = 0;
  int last1 = 0;
  
  for(int i=0;i<n;i++){
    if(i%2==0){
      arr0[i/2] = in();
      last0 = i/2;
    }else{ 
      arr1[i/2] = in();
      last1 = i/2;
    }
  }
  
  sort(arr0,arr0+last0+1);
  sort(arr1,arr1+last1+1);
  
  int cur0 = 0;
  int cur1 = 0;
  int ant = -1;
  int i = 0;
  
  while(i<n){
    
    if(ant>arr0[cur0]){
      cout << i-1 << endl;
      return;
    }
    ant = arr0[cur0];
    cur0++;
    i++;
    
    if(i<n){
      if(ant>arr1[cur1]){
        cout << i-1 << endl;
        return;
      }
      ant = arr1[cur1];
      cur1++;
      i++;
    }
  }
  
  cout << "OK" << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1 << ": ";
      solve();
    }
}
