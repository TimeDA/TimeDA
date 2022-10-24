#include<iostream>
 #include<cstdio>
 #include<fstream>
 
 using namespace std ;
 
 int f[107][107] ;
 int t , x, y ; 
 
 int main(){
    // freopen("D-small.in" , "r" ,stdin);
    // freopen("D-small.out" , "w" ,stdout);
     f[2][3] = 2 ; f[2][4] = 1 ; f[2][5] = 1 ; f[2][6] = 3 ; 
     f[3][3] = 2 ; f[3][4] = 2 ; f[3][5] = 2 ; f[3][6] = 2 ; 
     f[4][3] = 3 ; f[4][4] = 1 ; f[4][5] = 1 ; f[4][6] = 5 ;
     f[5][3] = 3 ; f[5][4] = 1 ; f[5][5] = 1 ; f[5][6] = 5 ; 
     f[6][3] = 6 ; f[6][4] = 2 ; f[6][5] = 2 ; f[6][6] = 19 ; 
     int T;
     scanf("%d" , &T);
     for (int i = 1 ; i <= T; i++){
         scanf("%d%d" , &x , &y);
         printf("Case #%d: %d\n" ,i ,  f[x][y]);
     }
 }
