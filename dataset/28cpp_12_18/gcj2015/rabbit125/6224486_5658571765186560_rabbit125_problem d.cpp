// Google Code Jam Template by rabbit125 @2014/10/01
 /* Libs. */
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
 #include <cstdarg>
 #include <bits/stdc++.h>
 /* ShortCut Vars. */
 // __cplusplus is a int: 201103
 //#if ( ( _WIN32 || __WIN32__ ) &&  < 201103L)
 #if ( _WIN32 || __WIN32__ )
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif // WIN32
 #define MP   make_pair
 #define F    first
 #define S    second
 #define PB   push_back
 #define PF   push_front
 #define PPB  pop_back
 #define PPF  pop_front
 /* Define Value Vars. */
 #define BIT         17
 #define INF 2000000000
 #define MOD 1000000007
 #define STRMAX    1000
 #define MAX    1200000
 /* Type Short Cut Vars. */
 typedef unsigned int UI;
 typedef long long LLI;
 typedef unsigned long long ULL;
 typedef long double LD;
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 using namespace std ;
 /* Start Code Here */
 int x , r , c ;
 int main( )
 {
     freopen( "D-small-attempt0.in" , "r" , stdin ) ;
     freopen( "D-small-attempt0.out" , "w" , stdout ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%d%d%d" , &x , &r , &c ) ;
         if( r > c )
             swap( r , c ) ;
         int ans = 1 ;
         if( x == 1 )
             ans = 2 ;
         else if( x == 2 )
         {
             if( r * c % 2 == 0 )
                 ans = 2 ;
         }
         else if( x == 3 )
         {
             if( r == 2 && c == 3 )
                 ans = 2 ;
             if( r == 3 && c == 3 )
                 ans = 2 ;
             if( r == 3 && c == 4 )
                 ans = 2 ;
         }
         else if( x == 4 )
         {
             if( r == 3 && c == 4 )
                 ans = 2 ;
             if( r == 4 && c == 4 )
                 ans = 2 ;
         }
         if( ans == 1 )
             printf( "Case #%d: RICHARD\n" , T++ ) ;
         else
             printf( "Case #%d: GABRIEL\n" , T++ ) ;
     }
     return 0 ;
 }
 /*
 4
 2 2 2
 2 1 3
 4 4 1
 3 2 3
 */
 /*
 Case #1: GABRIEL
 Case #2: RICHARD
 Case #3: RICHARD
 Case #4: GABRIEL
 */
