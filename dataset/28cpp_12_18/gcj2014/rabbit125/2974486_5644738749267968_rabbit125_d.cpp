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
 #define MAX       1200
 int n ;
 double a[ MAX ] , b[ MAX ] ;
 int main( )
 {
     freopen( "D-small-attempt0.in" , "r" , stdin ) ;
     freopen( "D-small-out" , "w" , stdout ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%d" , &n ) ;
         for( int i = 0 ; i < n ; i++ )
             scanf( "%lf" , &a[i] ) ;
         for( int i = 0 ; i < n ; i++ )
             scanf( "%lf" , &b[i] ) ;
         int p1 = 0 , p2 = 0 ;
         sort( a , a+n ) ;
         sort( b , b+n ) ;
         #if 0
         printf( "\n" ) ;
         for( int i = 0 ; i < n ; i++ )
             printf( "%.3lf%c" , a[i] , " \n"[i==n-1] ) ;
         for( int i = 0 ; i < n ; i++ )
             printf( "%.3lf%c" , b[i] , " \n"[i==n-1] ) ;
         #endif
         bool A[ MAX ] = { 0 } , B[ MAX ] = { 0 } ;
         double Tell ;
         int Tellid ;
         for( int i = 0 ; i < n ; i++ )
         {
             // check a[i] can't win, break the biggest in B
             int NowBMaxID = -1 , NowBMinID = -1 ;
             for( int j = n-1 ; j >= 0 ; j-- )
                 if( B[j] == 0 )
                 {
                     NowBMaxID = j ;
                     break ;
                 }
             for( int j = 0 ; j < n ; j++ )
                 if( B[j] == 0 )
                 {
                     NowBMinID = j ;
                     break ;
                 }
             if( a[i] < b[ NowBMinID ] )
             {
                 A[ i ] = 1 ;
                 B[ NowBMaxID ] = 1 ;
             }
             else
             {
                 A[ i ] = 1 ;
                 B[ NowBMinID ] = 1 ;
                 p1++ ;
             }
         }
         memset( A , 0 , sizeof( A ) ) ;
         memset( B , 0 , sizeof( B ) ) ;
         for( int i = 0 ; i < n ; i++ )
         {
             double Chv = 2 ;
             int   Chid = -1 ;
             for( int j = 0 ; j < n ; j++ )
                 if( B[ j ] == 0 && b[ j ] > a[ i ] )
                     if( Chv > b[ j ] )
                         Chv = b[ j ] , Chid = j ;
             if( Chid == -1 )
             {
                 for( int j = 0 ; j < n ; j++ )
                     if( B[ j ] == 0 && Chv > b[ j ] )
                         Chv = b[ j ] , Chid = j ;
             }
             A[ i ] = 1 ;
             B[ Chid ] = 1 ;
             if( a[i] > Chv )
                 p2++ ;
         }
         printf( "Case #%d: %d %d\n" , T++ , p1 , p2 ) ;
     }
     return 0 ;
 }
 /*
 4
 1
 0.5
 0.6
 2
 0.7 0.2
 0.8 0.3
 3
 0.5 0.1 0.9
 0.6 0.4 0.3
 9
 0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
 0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458
 */
 /*
 Case #1: 0 0
 Case #2: 1 0
 Case #3: 2 1
 Case #4: 8 4
 */
