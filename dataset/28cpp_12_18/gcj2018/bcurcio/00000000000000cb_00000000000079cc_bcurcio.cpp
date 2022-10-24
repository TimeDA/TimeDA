#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef long long ll;

void show(vector<vector<double>> x){
  
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++) cerr << x[i][j] << ' ' ;
    cerr << endl;
  }
  cerr << "****" << endl;
}
void multiplicar(vector<vector<double>> &a, vector<vector<double>> &b,vector<vector<double>> c){
  // a = b*c
  //~ cerr << "**** " << endl;
  //~ show(a);
  //~ show(b);
  //~ show(c);
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      a[i][j] = 0;
      for(int k=0;k<3;k++){
        a[i][j] += b[i][k] * c[k][j];
      }
    }
  }
}

double calcsombra(vector<vector<double>> &a){
  double res = 0;
  
  res += fabs(a[0][0]*a[2][1]-a[2][0]*a[0][1]); // segunda cordenada del producto v de 1 y 2
  res += fabs(a[0][0]*a[2][2]-a[2][0]*a[0][2]); // segunda cordenada del producto v de 1 y 3
  res += fabs(a[0][2]*a[2][1]-a[2][2]*a[0][1]); // segunda cordenada del producto v de 2 y 3
  
  return res;
}

void solve(){
  double A;
  double pi = 4*atan(1);
  cin >> A;
  vector<vector<double>> cubo(3,vector<double>(3));
  cubo[0][0] = 1;
  cubo[1][1] = 1;
  cubo[2][2] = 1;
  
  vector<vector<double>> rot1(3,vector<double>(3));
  rot1[0][0] = 1;
  rot1[1][1] = 1;
  rot1[2][2] = 1;
  
  
  vector<vector<double>> rot2(3,vector<double>(3));
  rot2[0][0] = 1;
  rot2[1][1] = 1;
  rot2[2][2] = 1;
  

  bool dorot2 = false;
  
  if(A>sqrt(2)){
    dorot2 = true;
    rot2[1][1] =  cos(pi/4);
    rot2[1][2] = -sin(pi/4);
    rot2[2][1] = sin(pi/4);
    rot2[2][2] = cos(pi/4);
  }
  
  double inf = 0;
  double sup = pi/4;
  double mid = inf;
  
  for(int i=0;i<100;i++){
    mid = (inf+sup) / 2;
    //~ cerr << mid << endl;
    vector<vector<double>> aux = cubo;
    //~ show(rot1); 
    rot1[0][0] = cos(mid); 
    rot1[0][1] = -sin(mid);
    rot1[1][0] = sin(mid);
    rot1[1][1] = cos(mid);
    
    
    multiplicar(aux,rot1,aux);
    if(dorot2) multiplicar(aux,rot2,aux);
    
    double cura = calcsombra(aux);
    
    if(cura<A){
      inf = mid;
    }else{
      sup = mid;
    }
    
  }
  
  mid = (inf+sup)/2;
  vector<vector<double>> x = cubo;
    
  rot1[0][0] = cos(mid); 
  rot1[0][1] = -sin(mid);
  rot1[1][0] = sin(mid);
  rot1[1][1] = cos(mid);
  
  
  multiplicar(x,rot1,x);
  if(dorot2) multiplicar(x,rot2,x);
  
  
  double crx = x[0][0]/2 + x[0][1]/2 + x[0][2]/2;
  double cry = x[1][0]/2 + x[1][1]/2 + x[1][2]/2;
  double crz = x[2][0]/2 + x[2][1]/2 + x[2][2]/2;
  
  printf("%.9lf %.9lf %.9lf\n",x[0][0]/2+x[0][1]/2-crx,x[1][0]/2+x[1][1]/2-cry,x[2][0]/2+x[2][1]/2-crz);
  printf("%.9lf %.9lf %.9lf\n",x[0][0]/2+x[0][2]/2-crx,x[1][0]/2+x[1][2]/2-cry,x[2][0]/2+x[2][2]/2-crz);
  printf("%.9lf %.9lf %.9lf\n",x[0][2]/2+x[0][1]/2-crx,x[1][2]/2+x[1][1]/2-cry,x[2][2]/2+x[2][1]/2-crz);
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1 << ": "<< endl;
      solve();
    }
}
