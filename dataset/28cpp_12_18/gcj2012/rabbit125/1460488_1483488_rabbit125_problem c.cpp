#include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #define MAXSIZE 2000010
 using namespace std ;
 int n , m ;
 int L[ MAXSIZE ] ;
 int main( )
 {
     int i , j , t1 , t2 , t3 , t4 , k ;
     int A , B , tN ;
     int t , T = 1 , ans ;
     freopen( "C-small-attempt0.in" , "r" , stdin ) ;
     freopen( "out.txt" , "w" , stdout ) ;
     cin >> t ;
     while( t-- )
     {
         cin >> A >> B ;
         memset( L , 0 , sizeof( L ) ) ;
         ans = 0 ;
         t1 = ( int ) log10( (double)A ) ;
         t2 = 1 ;
         for( i = 0 ; i < t1 ; i++ )
             t2 *= 10 ;
         //printf( "%d\n" , t2 ) ;
         for( i = A ; i <= B ; i++ )
             for( j = A ; j <= B ; j++ )
             {
                 if( i < j )
                 {
                     bool b = 0 ;
                     tN = j ;
                     for( k = 0 ; k < t1 ; k++ )
                     {
                         t4 = tN % 10 ;
                         tN = ( int ) ( tN / 10 ) + t4 * t2 ;
                         if( tN >= A && tN <= B && tN == i )
                         {
                             ans++ ;
                             break ;
                         }
                     }
                 }
             }
 
         /*
         for( i = A ; i <= B ; i++ )
         {
             j = i ;
             bool b = 0 ;
             for( k = 0 ; k < t1 ; k++ )
             {
                 t4 = j % 10 ;
                 j = ( int ) ( j / 10 ) + t4 * t2 ;
                 if( j >= A && j <= B && j > i )
                 {
                     ans++ ;
                     b = 1 ;
                     printf( "%d " , j ) ;
                 }
             }
             if( b )
                 printf( "%d\n" , i ) ;
         }
         */
         printf( "Case #%d: %d\n" , T++ , ans ) ;
     }
     return 0 ;
 }
