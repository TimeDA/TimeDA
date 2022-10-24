// Google Code Jam Template by rabbit125 @2014/10/01
 /* Libs. */
 #include <algorithm>
 #include <bits/stdc++.h>
 #include <climits>
 #include <cstdarg>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <iostream>
 #include <map>
 #include <queue>
 #include <set>
 #include <stack>
 #include <utility>
 #include <vector>
 /* ShortCut Vars. */
 #if __WIN32__
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif // __WIN32__
 #define BG   begin
 #define CL   clear
 #define ED   end
 #define FR   first
 #define MP   make_pair
 #define SC   second
 #define SZ   size
 #define PB   push_back
 #define PF   push_front
 #define PPB  pop_back
 #define PPF  pop_front
 #define lg      std::__lg
 #define __count __builtin_popcount
 /* Type ShortCuts */
 typedef unsigned int        UI;
 typedef long long          LLI;
 typedef unsigned long long ULL;
 typedef long double         LD;
 /* Function ShortCuts */
 #define MS0(x) memset(x, 0, sizeof(x))
 #define MS1(x) memset(x, -1, sizeof(x))
 /* C++11 */
 // __cplusplus is a int: 201103
 #if __cplusplus > 201103L
     #include <tuple>
     #define MT make_tuple
     typedef tuple<int, int> TII;
 #endif
 /* Define Value Vars. */
 #define BIT         17
 #define INF 2000000000
 #define MOD 1000000007
 #define STRMAX    1000
 #define MAX    1200000
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 /* EPS */
 const double eps = 1e-7 ;
 using namespace std ;
 /* Start Code Here */
 int n ;
 int sec[ 2 ] ;
 vector <int> v ;
 void GetSec( )
 {
     sec[0] = sec[1] = 0 ;
     for( int i = n-1 ; i >= 0 ; i-- )
     {
         if( v[i] < v[n-1] )
         {
             sec[0] = v[i] ;
             break ;
         }
         sec[1]++ ;
     }
     //printf( "sec %d %d\n" , sec[0], sec[1] ) ;
 }
 int main( )
 {
     freopen( "B-small-attempt5.in" , "r" , stdin ) ;
     freopen( "B-small-attempt5.out" , "w" , stdout ) ;
     int t , T = 1 ;
     int t1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%d" , &n ) ;
         v.clear() ;
         for( int i = 0 ; i < n ; i++ )
         {
             scanf( "%d" , &t1 ) ;
             v.PB( t1 ) ;
         }
         sort( v.BG(), v.ED() ) ;
         GetSec( ) ;
         int step = 0 ;
         while( v[n-1] > 0 )
         {
             if( v[n-1] >= max( sec[0] , (v[n-1] / 2 + v[n-1] % 2) ) + sec[1] )
             {
                 t1 = v[n-1] ;
                 v[ n-1 ] -= t1 / 2 ;
                 v.PB( t1 / 2 ) ;
                 n++ ;
             }
             else
             {
                 for( int i = 0 ; i < n ; i++ )
                     if( v[i] > 0 )
                         v[i]-- ;
             }
             sort( v.BG(), v.ED() ) ;
             step++ ;
             GetSec( ) ;
             /*
             printf( "%d // " , step ) ;
             for( int i = 0 ; i < n ; i++ )
                 printf( "%d%c" , v[i] , " \n"[i+1 == n] ) ;
             */
         }
         printf( "Case #%d: %d\n" , T++ , step ) ;
     }
     return 0 ;
 }
 /*
 5
 1
 3
 4
 1 2 1 2
 1
 4
 4
 4 8 9 4
 4
 9 6 2 9
 */
 /*
 Case #1: 3
 Case #2: 2
 Case #3: 3
 Case #4: 7
 Case #5: 8
 
 */
