#include <iostream>
 #include <cstring>
 #include <cstdio>
 #include <cstdlib>
 #include <algorithm>
 #define MAXSIZE 5200
 using namespace std ;
 char s1[ 3 ][ 200 ] = { "ejp mysljylc kd kxveddknmc re jsicpdrysizq"
                       , "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
                       , "de kr kd eoya kw aej tysr re ujdr lkgc jv" } ;
 char s2[ 3 ][ 200 ] = { "our language is impossible to understandqz"
                       , "there are twenty six factorial possibilities"
                       , "so it is okay if you want to just give up" } ;
 char map[ 502 ] ;
 char w[ MAXSIZE ] ;
 int main( )
 {
     int i , j , k , t , T = 1 ;
     freopen( "A-small-attempt1 (1).in" , "r" , stdin ) ;
     freopen( "out.txt" , "w" , stdout ) ;
     bool b = 0 ;
     for( j = 0 ; j < 3 ; j++ )
         for( k = 0 ; k < strlen( s1[ j ] ) ; k++ )
             map[ s1[ j ][ k ] ] = s2[ j ][ k ] ;
     scanf( "%d\n" , &t ) ;
     for( int kk = 0; kk < t; kk++)
     {
         gets( w ) ;
         printf( "Case #%d: " , T++ ) ;
         for( i = 0 ; i < strlen( w ) ; i++ )
         {
             printf( "%c" , map[ w[ i ] ] ) ;
         }
         printf( "\n" ) ;
     }
     return 0 ;
 }
