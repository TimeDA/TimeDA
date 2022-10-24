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
 #define MAX        120
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 /* EPS */
 const double eps = 1e-7 ;
 using namespace std ;
 /* Start Code Here */
 int ans = 0 , len ;
 struct Pan
 {
     char p[ MAX ] ;
 };
 
 Pan Reverse( Pan cur, int x )
 {
     Pan ret = cur ;
     for( int i = 0 ; i <= x ; i++ )
     {
         if( cur.p[i] == '-' )
             ret.p[ x-i ] = '+' ;
         else
             ret.p[ x-i ] = '-' ;
     }
     return ret ;
 }
 
 void BK( int deep , Pan cur )
 {
     bool ok = 1 ;
     //printf( "%d %s %d\n", deep , cur.p ) ;
     for( int i = 0 ; i < len ; i++ )
         if( cur.p[i] == '-' )
         {
             ok = 0 ;
             break ;
         }
     if( ok )
     {
         ans = min( ans, deep ) ;
         return ;
     }
     if( deep > len || deep > ans )
         return ;
     for( int i = 0 ; i < len ; i++ )
         BK( deep+1, Reverse(cur, i ) ) ;
 }
 void Solve1( Pan ori_p )
 {
     BK( 0 , ori_p ) ;
 }
 void Solve2( Pan ori_p )
 {
     int cnt = 0 ;
     for( int i = 1 ; i < len ; i++ )
         if( ori_p.p[i] != ori_p.p[i-1] )
             cnt++ ;
     if( ori_p.p[len-1] == '-' )
         cnt++ ;
     ans = cnt ;
 }
 int main( )
 {
     freopen( "B-small-attempt1.in" , "r" , stdin ) ;
     freopen( "B-small-attempt1.out" , "w" , stdout ) ;
     //freopen( "B-large.in" , "r" , stdin ) ;
     //freopen( "B-large.out" , "w" , stdout ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         ans = MAX ;
         Pan ori_p ;
         scanf( "%s" , ori_p.p ) ;
         len = strlen( ori_p.p ) ;
         //Solve1( ori_p ) ;
         Solve2( ori_p ) ;
         printf( "Case #%d: %d\n" , T++ , ans ) ;
     }
     return 0 ;
 }
 /*
 5
 -
 -+
 +-
 +++
 --+-
 */
 /*
 Case #1: 1
 Case #2: 1
 Case #3: 2
 Case #4: 0
 Case #5: 3
 */
