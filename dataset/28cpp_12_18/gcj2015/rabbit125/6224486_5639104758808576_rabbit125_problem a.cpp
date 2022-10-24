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
 #define MAX       1200
 /* Type Short Cut Vars. */
 typedef unsigned int UI;
 typedef long long LLI;
 typedef unsigned long long ULL;
 typedef long double LD;
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 using namespace std ;
 /* Start Code Here */
 int n ;
 char s[ MAX ] ;
 int main( )
 {
     freopen( "A-small-attempt0.in" , "r" , stdin ) ;
     freopen( "A-small-attempt0.out" , "w" , stdout ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%d %s" , &n , s ) ;
         int stand = 0 ;
         int cur_lev = 0 ;
         int add = 0 ;
         for( int i = 0 ; i < n+1 ; i++ )
             if( s[i] != 0 )
             {
                 if( stand < i )
                 {
                     cur_lev = i ;
                     add += i - stand ;
                     stand += i - stand ;
                 }
                 stand += s[i] - '0' ;
             }
         printf( "Case #%d: %d\n" , T++ , add ) ;
     }
     return 0 ;
 }
 /*
 4
 4 11111
 1 09
 5 110011
 0 1
 */
 /*
 Case #1: 0
 Case #2: 1
 Case #3: 2
 Case #4: 0
 */
