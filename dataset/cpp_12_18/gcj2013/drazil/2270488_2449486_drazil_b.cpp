#include <cstdio>
 #include <set>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <stack>
 
 using namespace std ;
 
 int map[120][120] ;
 
 int main(void)
 {
     int tc, cas ;
     int y, x, my, mx ;
     int xr[120] ;
     int yr[120] ;
     bool pass ;
 
     scanf("%d",&tc) ;
     for(cas=1;cas<=tc;cas++)
     {
         memset(xr,0,sizeof(xr)) ;
         memset(yr,0,sizeof(yr)) ;
 
         scanf("%d%d",&my,&mx) ;
         for(y=0;y<my;y++)
         {
             for(x=0;x<mx;x++)
             {
                 scanf("%d",&map[y][x]) ;
                 if(map[y][x]>xr[x]) xr[x] = map[y][x] ;
                 if(map[y][x]>yr[y]) yr[y] = map[y][x] ;
             }
         }
         
         pass = true ;
         
         for(y=0;y<my&&pass;y++)
         {
             for(x=0;x<mx&&pass;x++)
             {
                 if(map[y][x]!=min(xr[x],yr[y]))
                 {
                     pass = false ;
                 }
             }
         }
         
         if(pass==true)
         {
             printf("Case #%d: YES\n",cas) ;
         }
         else
         {
             printf("Case #%d: NO\n",cas) ;
         }
     }
 
     return 0;
 }
