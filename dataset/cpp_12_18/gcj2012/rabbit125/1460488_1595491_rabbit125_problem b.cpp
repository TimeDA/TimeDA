#include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 #define MAXSIZE 120
 using namespace std ;
 int N , S , P ;
 int n[ MAXSIZE ] ;
 int main( )
 {
     int i , j , t , T = 1 , ans ;
     int NormalMin , SuperMin , t1 ;
     freopen( "B-small-attempt0.in" , "r" , stdin ) ;
     freopen( "out.txt" , "w" , stdout ) ;
     cin >> t ;
     while( t-- )
     {
         cin >> N >> S >> P ;        //P =  0 , 1  , 2 , 3 , ...
         NormalMin = 3 * P - 2 ;     //    -2 , 1  , 4 , 7 , ...
         SuperMin = 3 * P - 4 ;      //    -4 , -1 , 2 , 5 , ...
         if( NormalMin < 0 )
             NormalMin = P ;
         if( SuperMin < 0 )
             SuperMin = P ;
         t1 = S ;
         ans = 0 ;
         vector <int> tmp ;
         for( i = 0 ; i < N ; i++ )
         {
             cin >> n[ i ] ;
             if( n[ i ] >= NormalMin )
                 ans++ ;
             else
             {
                 if( n[ i ] >= SuperMin && t1 > 0 )
                     ans++ , t1-- ;
             }
         }
         printf( "Case #%d: %d\n" , T++ , ans ) ;
     }
     return 0 ;
 }
