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
 int r , c , n , ans ;
 int main( )
 {
     freopen( "B-small-attempt0.in" , "r" , stdin ) ;
     freopen( "B-small-attempt0.out" , "w" , stdout ) ;
     //freopen( "A-large.in" , "r" , stdin ) ;
     //freopen( "A-large.out" , "w" , stdout ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%d%d%d" , &r , &c , &n ) ;
         int full = (r * c + 1 ) / 2 ;
         if( n <= full )
             printf( "Case #%d: 0\n" , T++ ) ;
         else
         {
             if( r == 1 || c == 1 )
                 ans = 2 * ( n - full ) ;
             else if( r * c == 2 && n == 2 )
                 ans = 1;
             else if( r > 2 && c > 2 )
             {
                 ans = (r-1) * c + (c-1) * r ;
                 int small_rec = ( (r-2) * (c-2) + 1 ) / 2 ;
                 if( n >= r*c - small_rec )
                     ans = ans - ( r*c - n ) * 4 ;
             }
             else if( (r*c) % 2 == 1 )
             {
                 if( n > (r*c + 1) / 2 + 2 )
                     ans = (n - ( r*c + 1 ) / 2 ) * 3 - 1 ;
                 else
                     ans = (n - ( r*c + 1) / 2 ) * 3 ;
             }
             else if( r % 2 == 0 && c % 2 == 0 )
             {
                 if( n - (r*c + 1) / 2 <= 2 )
                     ans = (n - (r*c + 1) / 2 ) * 2 ;
                 else
                     ans = (n - (r*c + 1) / 2 - 2) * 3 + 4 ;
             }
             else
             {
                 if( n - (r*c + 1) / 2 <= 2)
                     ans = (n - (r*c + 1) / 2) * 2 ;
                 else
                     ans = (n - (r*c + 1) / 2 - 2) * 3 + 4 ;
             }
             printf( "Case #%d: %d\n" , T++ , ans ) ;
         }
     }
     return 0 ;
 }
 /*
 4
 2 3 6
 4 1 2
 3 3 8
 5 2 0
 */
 /*
 output
 */
