// Google Code Jam Template by rabbit125 @2014/02/13
 #include <cstdio>
 #include <cstdlib>
 #include <queue>
 #include <cstring>
 #include <cmath>
 #include <map>
 #include <stack>
 #include <set>
 #include <vector>
 #include <iostream>
 #include <algorithm>
 #include <utility>
 #include <climits>
 #include <bits/stdc++.h>
 using namespace std ;
 /* Define Useful Vars. */
 #define ULL  unsigned long long
 #define LLI  long long
 #define BIT         17
 #define INF 1000000000
 #define MOD 1000000007
 #define MAX     200010
 /* Debug */
 #define DEBUG
 double C , F , X ;
 double Ans ;
 double AssTime[ MAX ] ;
 int main( )
 {
     freopen( "B-small-attempt0.in" , "r" , stdin ) ;
     freopen( "B-small-out" , "w" , stdout ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%lf%lf%lf" , &C , &F , &X ) ;
         Ans = X / 2.0 ;
         AssTime[ 0 ] = 0.0 ;
         for( int i = 1 ; i < MAX ; i++ )
             AssTime[ i ] = AssTime[ i-1 ] + ( C/(F*(i-1)+2.0) ) ;
         for( int i = 1 ; i < MAX ; i++ )
             Ans = min( Ans , AssTime[ i ] + X / ( 2.0 + i*F ) ) ;
         printf( "Case #%d: %.7lf\n" , T++ , Ans ) ;
     }
     return 0 ;
 }
 /*
 4
 30.0 1.0 2.0
 30.0 2.0 100.0
 30.50000 3.14159 1999.19990
 500.0 4.0 2000.0
 */
 /*
 Case #1: 1.0000000
 Case #2: 39.1666667
 Case #3: 63.9680013
 Case #4: 526.1904762
 */
