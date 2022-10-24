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
 #define MAX  120000000
 /* Time Evaluation */
 #define runtime() ((double)clock() / CLOCKS_PER_SEC)
 /* EPS */
 const double eps = 1e-7 ;
 using namespace std ;
 /* Start Code Here */
 int n, m, cnt ;
 bool intT[ MAX ] ;
 int bitmap[ 32 ] = {0} ;
 map<LLI,bool> primeT ;
 vector <LLI>  primeV ;
 int prime_size = 0 ;
 void PrimeTable()
 {
     primeT.clear() ;
     primeV.clear() ;
     memset( intT, 0 , sizeof( intT ) ) ;
     intT[ 1 ] = 1 ;
     for( int i = 2 ; i < (int)sqrt( (double)MAX ) ; i++ )
         if( intT[ i ] == 0 )
             for( int j = i+i ; j < MAX ; j += i )
                 intT[ j ] = 1 ;
     for( int i = 2 ; i < MAX ; i++ )
         if( intT[ i ] == 0 )
         {
             primeT[ (LLI) i ] = 1 ;
             primeV.push_back( (LLI) i ) ;
         }
     prime_size = (int) primeV.size() ;
     printf( "%d\n" , prime_size ) ;
     //for( int i = 0 ; i < prime_size ; i++ )
         //printf( " %d%c", primeV[i], i == prime_size-1 ? '\n' : ' ' ) ;
 }
 bool Isprime( LLI x )
 {
     if( x == 1 )
         return 1 ;
     if( primeT[ x ] == 1 )
         return 1 ;
     bool checking = 0 ;
     for( int i = 0 ; i < prime_size ; i++ )
         while( x % primeV[i] == 0 )
             x /= primeV[i], checking = 1 ;
     if( !checking && x != 1 )
         return 1 ;
     return 0 ;
 }
 void Checker()
 {
     bool isaAns = 1 ;
     LLI cur_num = 0, base = 0 ;
     vector <LLI> divs ;
     divs.clear() ;
     for( int i = 2 ; i <= 10 ; i++ )
     {
         base = 1, cur_num = 0 ;
         for( int j = 0 ; j <= n-1 ; j++ )
             cur_num += bitmap[j] * base, base *= i ;
         //printf( "%12lld %12d\n" , cur_num , i ) ;
         if( Isprime( cur_num ) )
         {
             isaAns = 0 ;
             break ;
         }
         else
         {
             for( int j = 0 ; j < prime_size ; j++ )
                 if( cur_num % primeV[j] == 0 )
                 {
                     divs.push_back( primeV[j] ) ;
                     break ;
                 }
         }
     }
     if( isaAns )
     {
         for( int i = n-1 ; i >= 0 ; i-- )
             printf( "%d" , bitmap[i] ) ;
         for( int i = 0 ; i < divs.size() ; i++ )
             printf( " %lld" , divs[i] ) ;
         printf( "\n" ) ;
         cnt++ ;
     }
 }
 
 void BK( int bit_p )
 {
     // overflow..
     // Finish..
     if( cnt == m )
         return ;
     if( bit_p == n-1 )
     {
         Checker() ;
         return ;
     }
     if( bit_p > n-1 )
         return ;
     // 2 ~ 14
     bitmap[ bit_p ] = 0 ;
     BK( bit_p+1 ) ;
     bitmap[ bit_p ] = 1 ;
     BK( bit_p+1 ) ;
 }
 void Solve1()
 {
     BK( 1 ) ;
 }
 int main( )
 {
     freopen( "C-small-attempt0.in" , "r" , stdin ) ;
     freopen( "C-small-attempt0.out" , "w" , stdout ) ;
     //freopen( "C-large.in" , "r" , stdin ) ;
     //freopen( "C-large.out" , "w" , stdout ) ;
     PrimeTable( ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%d%d", &n, &m ) ;
         cnt = 0 ;
         memset( bitmap, 0 , sizeof( bitmap ) ) ;
         bitmap[ 0 ] = bitmap[ n-1 ] = 1 ;
         printf( "Case #%d:\n" , T++ ) ;
         Solve1() ;
     }
     return 0 ;
 }
 /*
 1
 16 50
 */
 /*
 1
 6 3
 */
 /*
 output
 */
