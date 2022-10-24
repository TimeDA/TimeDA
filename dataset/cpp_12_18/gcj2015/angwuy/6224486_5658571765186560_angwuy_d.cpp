#include <cstdio>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <sstream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <bitset>
 #include <numeric>
 #include <ctime>
 #include <cmath>
 #include <cassert>
 #include <algorithm>
 using namespace std;
 int X,R,C;
 bool gao(){
     if((R*C)%X!=0) return 1;
     if(X==1||X==2) return 0;
     if(X==3) return R==1;
     if(X==4) return R==1||R==2;
 }
 int main() {
     freopen("D-small-attempt0.in" , "r" , stdin) ; freopen("D-small-attempt0.out", "w" ,stdout) ;
     int Test; cin>>Test;
     for(int i=1;i<=Test;i++){
         cin>>X>>R>>C;
         if(R>C) swap(R,C);
         if(gao())
             cout<<"Case #"<<i<<": RICHARD\n";
         else
             cout<<"Case #"<<i<<": GABRIEL\n";
     }
 }
