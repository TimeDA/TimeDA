#include<cstdio>
 #include<cstring>
 
 char map[2056][2056];
 int count[2]; // 0 == 'X' , 1 == 'O'
 int n , m;
 inline char getMap(int i, int j )
 {
         if( i < 0 || j < 0 || j>=n || i>=n )
                 return '.';
         return map[i][j];
 }
 
 //right , right bottom , bottom , left bottom
 int dx[] = { 1 , 1 , 0 , -1 };
 int dy[]  = { 0 , 1 , 1 , 1 };
 char error;
 
 int cntMap[2][2056][2056];
 int detect2(int p, char ch) {
         int i ,j,k,l;
         int cnt = 0;
         int r , c;
         int len;
         char isOK = 1;
 
         if( error ) return 0;
 
         for(i=0;i<n ;i++) for(j=0;j<n;j++)
         {
                 for(k=0;k<4;k++)
                 {
                         r = i , c = j;
                         if (getMap(r-dy[k],c-dx[k]) != ch ||
 							getMap(r-dy[k],c-dx[k]) != 'T' ) // avoid count again
                         {
                                 len=0; //continuous match
                                 while (getMap(r+len*dy[k],c+len*dx[k]) == ch||
 									getMap(r+len*dy[k],c+len*dx[k]) == 'T') ++len;
                                 if (len >= m)
                                 {
                                         cnt++;
                                         //len-m == the first position that not in "consecutive m"
                                         if( len-m >= m )  // still have another "consecutive m"
                                         {
                                                 error = 1; return 0;
                                         }
 
                                         isOK = 0;
                                         for(l=len-m ; l<len && l < m ;l++)
                                         {
 											cntMap[p][r+l*dy[k]][c+l*dx[k]]++; //count the "double win position"
                                                 if(cntMap[p][r+l*dy[k]][c+l*dx[k]] == cnt )
                                                         isOK = 1;
                                         }
                                         if( !isOK ){ error = 1; return 0;}
                                 }
                         }
                 }
         }
         if(!error)
         error = !isOK;
 
         return cnt;
 }
 int main()
 {
         int cases , Case=0;
         int i,j,k;
         int turn;
         char isFull ,t;
         int xWinCnt , oWinCnt;
 
 
         scanf("%d" , &cases);
         while(cases--)
         {
         //scanf("%d%d " , &n,&m);
 			n = 4; m =4;
         //gets(map[0]);
 			printf("Case #%d: " , ++Case);
 
         count[0] = count[1] = 0;
         isFull = 1;
 
         for(i=0;i<n;i++)
         {
                 scanf("%s" , map[i]);
                 //gets(map[i]);
                 for(j=0;j<n;j++)
                 {
                         t = map[i][j];
                         if( t == 'X' ) count[0]++;
                         else if( t == 'O' ) count[1]++;
                         else if( t != 'T' )isFull = 0; //have '.'
 
                         
                         for(k=0;k<2;k++)
                         cntMap[k][i][j] = 0; //..............
                 }
                 
         }
 
         turn = -1;
         if( count[0] == count[1] ) turn = 1; // now = O just written
         else if( count[0] == count[1]+1 ) turn = 0; // now = X justwritten
 
 
         if( turn == -1 )
         {
                 puts("ERROR"); goto next;
         }
 
         error = 0;
         xWinCnt = detect2(0,'X');
         oWinCnt = detect2(1,'O');
 
         if( turn == 1 && xWinCnt ) error = 1;
         else if( turn == 0 && oWinCnt ) error = 1;
         else if ( xWinCnt && oWinCnt ) error = 1;
 
         if( error )
         {
                 puts("ERROR"); goto next;
         }
 
         if( xWinCnt )
                 puts("X won");
         else if( oWinCnt )
                 puts("O won");
         else
         {
                 if( isFull  )
                         puts("Draw");
                 else
                         puts("Game has not completed");
         }
 
 next:;
         }
 
 
         return 0;
 }