#include <iostream>
 #include <cstdio>
 #include <cstring>
 using namespace std ;
 int N , MAXi , MAX ;
 int L[2000] , R[2000] , A[2000] ;
 int Solve() {
     cin >> N ; for ( int i = 1 ; i <= N ; i ++ ) cin >> A[i] ;
     for ( int i = 1 ; i <= N ; i ++ ) L[i] = R[i] = 0 ;
     for ( int i = 2 ; i <= N ; i ++ ) for ( int j = 1 ; j < i ; j ++ ) if ( A[i] < A[j] ) L[i] ++ ;
     for ( int i = N-1 ; i >= 1 ; i -- ) for ( int j = N ; j > i ; j -- ) if ( A[i] < A[j] ) R[i] ++ ;
     int ret = 0 ;
     for ( int i = 1 ; i <= N ; i ++ ) ret += min(L[i] , R[i]) ;
     return ret ;
 }
 int main() {
     freopen("B.in","r",stdin) ; freopen("B.out","w",stdout) ;
     int Test ; cin >> Test ;
     for ( int i = 1 ; i <= Test ; i ++ ) cout << "Case #" << i << ": " << Solve() << "\n" ;
 }
