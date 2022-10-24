#include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #define MAX 100010
 using namespace std ;
 int n ;
 int A , B ;
 double p[ MAX ] ;
 int a[ 8 ] = { 0 , 3 , 2 , 1 , 2 , 1 , 1 , 1 } ;
 int b[ 8 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ;
 int d[ 12 ][ MAX ] ;
 int ct[ MAX ] ;
 double pt[ MAX ] , total , ans ;
 int main( )
 {
     int i , j , k ;
     int t1 , t2 , t3 ;
     int T = 1 , t ;
     freopen( "A-small-attempt0.in" , "r" , stdin ) ;
     freopen( "out.out" , "w" , stdout ) ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         scanf( "%d%d" , &A , &B ) ;
         for( i = 0 ; i < A ; i++ )
             scanf( "%lf" , &p[ i ] ) ;
         t1 = 1 ;
         for( i = 0 ; i < A ; i++ )
             t1 *= 2 ;
         for( i = 0 ; i < t1 ; i++ )
         {
             pt[ i ] = 1 ;
             k = 0 ;
             t2 = -1 ;
             bool b = 0 ;
             for( j = i ; k < A ; j /= 2 )
             {
                 //printf( "jjj%d\n" , j%2 ) ;
                 if( j%2 == 0 )
                     pt[ i ] *= (double) p[ A-1-k ] ;
                 else
                 {
                     //if( b == 0 )
                         t2 = k , b = 1 ;
                     pt[ i ] *= (double)( 1.0 - p[ A-1-k ] ) ;
                 }
                 k++ ;
             }
             //printf( "xx%.6lf\n" , pt[ i ] ) ;
             ct[ i ] = t2 ;
         }
         t3 = B - A + 1 ;
         ans = B + 1 + 1 ;
         /*
         for( i = 0 ; i < t1 ; i++ )
             printf( "%d " , ct[ i ] ) ;
         printf( "\n" ) ;
         for( i = 0 ; i < t1 ; i++ )
             printf( "%.2lf " , pt[ i ] ) ;
         printf( "\n" ) ;
         */
         for( i = 0 ; i <= A ; i++ )
         {
             double Tp = 0 ;
             for( j = 0 ; j < t1 ; j++ )
             {
                 //printf( "%.6lf %d\n" , pt[ j ] , ct[ j ] ) ;
                 if( i > ct[ j ] )
                     Tp += pt[ j ] * (double) ( t3 + (i)*2 ) ;//printf("x%.3lf %d %.3lf\n" , pt[ j ] , t3 + (i)*2 , Tp ) ;
                 else
                     Tp += pt[ j ] * (double) ( t3 + (i)*2 + B + 1 ) ;//,printf("y%.3lf %d %.3lf\n" , pt[ j ] , t3 + (i)*2 + B + 1  , Tp ) ;
 
             }
             //printf( "%.6lf %.6lf\n" , ans , Tp ) ;
             ans = min( ans , Tp ) ;
         }
         printf( "Case #%d: %.6lf\n" , T++ , ans ) ;
     }
     return 0 ;
 }
