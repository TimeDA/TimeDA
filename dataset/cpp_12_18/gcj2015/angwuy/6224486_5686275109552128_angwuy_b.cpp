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
 int N , C[1001][1001] , A[1001] ;
 int zaigao(int x) { if ( x % 2 == 0 ) return x / 2 ; else return (x/2) + 1 ; }
 int zhunbei() {
     for ( int i = 0 ; i <= 1000 ; i ++ ) for ( int j = 0 ; j <= 1000 ; j ++ )
         if ( j <= i ) C[j][i] = 0 ;
         else          C[j][i] = 1+C[j-i][i] ;
 }
 int gao() {
     int ret = 1000 , tmp ;
     for ( int i = 1 ; i <= 1000 ; i ++ ) {
         tmp = 0 ;
         for ( int j = 0 ; j < N ; j ++ ) tmp += C[A[j]][i] ;
         if ( i + tmp < ret ) ret = i + tmp ;
     }
     return ret ;
 }
 int main() {
     freopen("B-small-attempt0.in","r",stdin) ; freopen("B-small-attempt0.out","w",stdout) ;
     zhunbei() ;
     int Test ; cin >> Test ;
     for ( int i = 1 ; i <= Test ; i ++ ) {
         cin >> N ;
         for ( int j = 0 ; j < N ; j ++ ) cin >> A[j] ;
         cout << "Case #" << i << ": " << gao() << "\n" ;
     }
 }
