// Google Code Jam Template by rabbit125 @2015/04/18
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
 LLI n ;
 int dig[ 10 ] ;
 LLI ans = 0 ;
 void Parse( LLI x )
 {
     ans = x ;
     while( x > 0 )
     {
         int digit = x % 10 ;
         dig[ digit ] = 1 ;
         x /= 10 ;
     }
 }
 bool Check( int step )
 {
     bool allOK = 1 ;
     for( int i = 0 ; i < 10 ; i++ )
         if( dig[ i ] == 0 )
         {
             allOK = 0 ;
             break ;
         }
 
     if( step > 100000 )
         allOK = 1 , ans = -1 ;
     return allOK ;
 }
 int main( )
 {
     freopen( "A-small-attempt0.in" , "r" , stdin ) ;
     freopen( "A-small-attempt0.out" , "w" , stdout ) ;
     //freopen( "A-large.in" , "r" , stdin ) ;
     //freopen( "A-large.out" , "w" , stdout ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         memset( dig , 0 , sizeof( dig ) ) ;
         scanf( "%lld" , &n ) ;
         for( int i = 1 ; ; i++ )
         {
             Parse( i * n ) ;
             if( Check( i ) )
                 break ;
         }
         if( ans > 0 )
             printf( "Case #%d: %lld\n" , T++ , ans ) ;
         else
             printf( "Case #%d: INSOMNIA\n" , T++ ) ;
     }
     return 0 ;
 }
 /*
 5
 0
 1
 2
 11
 1692
 */
 /*
 Case #1: INSOMNIA
 Case #2: 10
 Case #3: 90
 Case #4: 110
 Case #5: 5076
 */
