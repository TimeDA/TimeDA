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
 #define MAX        120
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 /* EPS */
 const double eps = 1e-7 ;
 using namespace std ;
 /* Start Code Here */
 int n ;
 int N[ MAX ] ;
 
 int ans ;
 int f( int now )
 {
     int N[ 20 ] , cnt = 0 ;
     while( now )
     {
         N[ cnt++ ] = now % 10 ;
         now /= 10 ;
     }
     int t1 = 1 ;
     int ret = 0 ;
     for( int i = cnt-1 ; i >= 0 ; i-- )
     {
         ret += N[i] * t1 ;
         t1 *= 10 ;
     }
     return ret ;
 }
 void BK( int now , int cnt )
 {
     printf( "%d\n" , now ) ;
     if( now > n )
         return ;
     if( now == n )
     {
         ans = min( ans , cnt ) ;
         return ;
     }
     if( ans < cnt + n - now )
         return ;
     int rev = f( now+1 ) ;
     BK( now+1 , cnt+1 ) ;
     if( rev > now )
         BK( rev , cnt+2 ) ;
 }
 int A[ 1000001 ] = { 0 } ;
 int ch[ 1000001 ] = { 0 } ;
 void DP( )
 {
     int Lim = 1000001 ;
     //int Lim = 30 ;
     vector <int> v ;
     for( int i = 2 ; i < Lim ; i++ )
     {
         int rev = f( i ) ;
         if( rev > i )
         {
             ch[ i ] = rev ;
             v.PB( i ) ;
         }
     }
     printf( "%d\n" , v.SZ() ) ;
     int vsz = v.SZ() ;
     A[ 1 ] = 1 ;
     FILE *fout = fopen( "aaa.table" , "w" ) ;
     fprintf( fout, "%d %d\n" , 1 , A[1] ) ;
     for( int i = 2 ; i < Lim ; i++ )
     {
         A[ i ] = i ;
         for( int j = 0 ; j < vsz ; j++ )
         {
             if( v[j] > i )
                 break ;
             int rev = ch[ v[j] ] ;
             //printf( "cc %d %d\n" , j , rev ) ;
             if( rev <= i )
                 A[i] = min( A[i] , i - rev + A[ v[j] ] + 1 ) ;
         }
         if( i % 10000 == 0 )
             printf( "%d %d\n" , i , A[i] ) ;
         fprintf( fout, "%d %d\n" , i , A[i] ) ;
     }
     fclose( fout ) ;
 }
 void ReadT( )
 {
     FILE *fin = fopen( "aaa.table" , "r" ) ;
     int a , b ;
     while( ~fscanf( fin , "%d%d" , &a , &b ) )
         A[ a ] = b ;
     fclose( fin ) ;
 }
 int main( )
 {
     freopen( "A-small-attempt0.in" , "r" , stdin ) ;
     freopen( "A-small-attempt0.out" , "w" , stdout ) ;
     //freopen( "A-large.in" , "r" , stdin ) ;
     //freopen( "A-large.out" , "w" , stdout ) ;
     int t , T = 1 ;
     # if 0
     DP( ) ;
     # else
     ReadT( ) ;
     #endif // 0
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%d" , &n ) ;
         printf( "Case #%d: %d\n" , T++ , A[n] ) ;
     }
     return 0 ;
 }
 /*
 3
 1
 19
 23
 */
 /*
 output
 */
