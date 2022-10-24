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
 
 using namespace std ;
 
 char map[10][10] ;
 
 int main(void)
 {
     int tc, cas ;
     int y, x ;
     bool isempty;
     
     scanf("%d",&tc) ;
     for(cas=1;cas<=tc;cas++)
     {
         for(y=0;y<4;y++) scanf("%s",map[y]) ;
         
         isempty = false ;
 
         for(y=0;y<4;y++)
         {
             int cnt[2] = {0,0} ;
 
             for(x=0;x<4;x++)
             {
                 if(map[y][x]=='X') cnt[0]++ ;
                 else if(map[y][x]=='O') cnt[1]++ ;
                 else if(map[y][x]=='T')
                 {
                     cnt[0]++ ;
                     cnt[1]++ ;
                 }
                 else isempty = true ;
             }
 
             if(cnt[0]==4)
             {
                 printf("Case #%d: X won\n",cas) ;
             }
             else if(cnt[1]==4)
             {
                 printf("Case #%d: O won\n",cas) ;
             }
 
             if(cnt[0]==4||cnt[1]==4)
             {
                 y = -1 ;
                 break ;
             }
         }
 
         if(y==-1) continue ;
         
         for(x=0;x<4;x++)
         {
             int cnt[2] = {0,0} ;
 
             for(y=0;y<4;y++)
             {
                 if(map[y][x]=='X') cnt[0]++ ;
                 else if(map[y][x]=='O') cnt[1]++ ;
                 else if(map[y][x]=='T')
                 {
                     cnt[0]++ ;
                     cnt[1]++ ;
                 }
                 else isempty = true ;
             }
 
             if(cnt[0]==4)
             {
                 printf("Case #%d: X won\n",cas) ;
             }
             else if(cnt[1]==4)
             {
                 printf("Case #%d: O won\n",cas) ;
             }
 
             if(cnt[0]==4||cnt[1]==4)
             {
                 x = -1 ;
                 break ;
             }
         }
 
         if(x==-1) continue ;
 
         int cnt[2] = {0,0} ;
         for(x=0;x<4;x++)
         {
             if(map[x][x]=='X') cnt[0]++ ;
             else if(map[x][x]=='O') cnt[1]++ ;
             else if(map[x][x]=='T')
             {
                 cnt[0]++ ;
                 cnt[1]++ ;
             }
             else isempty = true ;
         }
 
         if(cnt[0]==4)
         {
             printf("Case #%d: X won\n",cas) ;
         }
         else if(cnt[1]==4)
         {
             printf("Case #%d: O won\n",cas) ;
         }
 
         if(cnt[0]==4||cnt[1]==4) continue ;
 
         cnt[0] = 0 ;
         cnt[1] = 0 ;
         
         for(x=0;x<4;x++)
         {
             if(map[3-x][x]=='X') cnt[0]++ ;
             else if(map[3-x][x]=='O') cnt[1]++ ;
             else if(map[3-x][x]=='T')
             {
                 cnt[0]++ ;
                 cnt[1]++ ;
             }
             else isempty = true ;
         }
 
         if(cnt[0]==4)
         {
             printf("Case #%d: X won\n",cas) ;
         }
         else if(cnt[1]==4)
         {
             printf("Case #%d: O won\n",cas) ;
         }
 
         if(cnt[0]==4||cnt[1]==4) continue ;
         
         if(isempty==true)
         {
             printf("Case #%d: Game has not completed\n",cas) ;
         }
         else
         {
             printf("Case #%d: Draw\n",cas) ;
         }
     }
     
     return 0;
 }
