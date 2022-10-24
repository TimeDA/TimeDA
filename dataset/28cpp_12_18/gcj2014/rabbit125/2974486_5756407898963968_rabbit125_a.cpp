// Google Code Jam Template by rabbit125 @2014/02/13
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
 #include <bits/stdc++.h>
 using namespace std ;
 /* Define Useful Vars. */
 #define ULL  unsigned long long
 #define LLI  long long
 #define BIT         17
 #define INF 1000000000
 #define MOD 1000000007
 #define MAX      12000
 /* Debug */
 #define DEBUG
 int CT[ 4 ][ 4 ] ;
 int AnsN[ 17 ] , RowID ;
 int main( )
 {
     freopen( "A-small-attempt0.in" , "r" , stdin ) ;
     freopen( "A-small-out" , "w" , stdout ) ;
     int t , T = 1 ;
     scanf( "%d" , &t ) ;
     while( t-- )
     {
         memset( AnsN , 0 , sizeof( AnsN ) ) ;
         for( int k = 0 ; k < 2 ; k++ )
         {
             scanf( "%d" , &RowID ) ;
             for( int i = 0 ; i < 16 ; i++ )
                 scanf( "%d" , &CT[i/4][i%4] ) ;
             for( int i = 0 ; i < 4 ; i++ )
                 AnsN[ CT[ RowID-1 ][ i ] ]++ ;
         }
         // only #'s comes is 2: #
         // some #'s comes two times: Bad magician!
         // No #'s comes two times: Volunteer cheated!
         vector <int> TwoTimes ;
         for( int i = 1 ; i <= 16 ; i++ )
             if( AnsN[ i ] == 2 )
                 TwoTimes.push_back( i ) ;
         if( (int)TwoTimes.size() == 1 )
             printf( "Case #%d: %d\n" , T++ , TwoTimes[0] ) ;
         else if( (int)TwoTimes.size() > 1 )
             printf( "Case #%d: Bad magician!\n" , T++ ) ;
         else
             printf( "Case #%d: Volunteer cheated!\n" , T++ ) ;
     }
     return 0 ;
 }
 /*
 3
 2
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 3
 1 2 5 4
 3 11 6 15
 9 10 7 12
 13 14 8 16
 2
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 2
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 2
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 3
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 */
 /*
 Case #1: 7
 Case #2: Bad magician!
 Case #3: Volunteer cheated!
 */
