#include <cstdio>
 #include <cstring>
 using namespace std;
 int t,cnt=0,x,y,cnt2;
 bool done,solved;
 char grid[5][5];
 int main(){
     scanf("%d\n",&t);
     while(t--){
         cnt++;
         done=1;
         for(x=0;x<4;x++){
             scanf("%s",grid[x]);
             if(strlen(grid[x])<4) scanf("%s",grid[x]);
             for(y=0;y<4;y++) if(grid[x][y]=='.') done=0;
         }
         solved=0;
         for(x=0;x<4;x++){
             if(grid[x][0]!='.'){
                 if(grid[x][0]=='T'){
                     cnt2=2;
                     if(grid[x][1]=='.') cnt2=-100;
                     for(y=2;y<4;y++){
                         if(grid[x][y]==grid[x][1]) cnt2++;
                         else break;
                     }
                     if(cnt2==4){
                         solved=1;
                         printf("Case #%d: %c won\n",cnt,grid[x][1]);
                         break;
                     }
                 }
                 else{
                     cnt2=1;
                     for(y=1;y<4;y++){
                         if(grid[x][y]==grid[x][0]||grid[x][y]=='T') cnt2++;
                         else break;
                     }
                     if(cnt2==4){
                         solved=1;
                         printf("Case #%d: %c won\n",cnt,grid[x][0]);
                         break;
                     }
                 }
             }
             if(grid[0][x]!='.'){
                 if(grid[0][x]=='T'){
                     cnt2=2;
                     if(grid[1][x]=='.') cnt2=-100;
                     for(y=2;y<4;y++){
                         if(grid[y][x]==grid[1][x]) cnt2++;
                         else break;
                     }
                     if(cnt2==4){
                         solved=1;
                         printf("Case #%d: %c won\n",cnt,grid[1][x]);
                         break;
                     }
                 }
                 else{
                     cnt2=1;
                     for(y=1;y<4;y++){
                         if(grid[y][x]==grid[0][x]||grid[y][x]=='T') cnt2++;
                         else break;
                     }
                     if(cnt2==4){
                         solved=1;
                         printf("Case #%d: %c won\n",cnt,grid[0][x]);
                         break;
                     }
                 }
             }
         }
         if(!solved){
             if(grid[0][0]!='.'){
                 if(grid[0][0]=='T'){
                     cnt2=2;
                     if(grid[1][1]=='.') cnt2=-100;
                     for(y=2;y<4;y++){
                         if(grid[y][y]==grid[1][1]) cnt2++;
                         else break;
                     }
                     if(cnt2==4){
                         solved=1;
                         printf("Case #%d: %c won\n",cnt,grid[1][1]);
                     }
                 }
                 else{
                     cnt2=1;
                     for(y=1;y<4;y++){
                         if(grid[y][y]==grid[0][0]||grid[y][y]=='T') cnt2++;
                         else break;
                     }
                     if(cnt2==4){
                         solved=1;
                         printf("Case #%d: %c won\n",cnt,grid[0][0]);
                     }
                 }
             }
         }
         if(!solved){
             if(grid[0][3]!='.'){
                 if(grid[0][3]=='T'){
                     cnt2=2;
                     if(grid[1][2]=='.') cnt2=-100;
                     for(y=2;y<4;y++){
                         if(grid[y][3-y]==grid[1][2]) cnt2++;
                         else break;
                     }
                     if(cnt2==4){
                         solved=1;
                         printf("Case #%d: %c won\n",cnt,grid[1][2]);
                     }
                 }
                 else{
                     cnt2=1;
                     for(y=1;y<4;y++){
                         if(grid[y][3-y]==grid[0][3]||grid[y][3-y]=='T') cnt2++;
                         else break;
                     }
                     if(cnt2==4){
                         solved=1;
                         printf("Case #%d: %c won\n",cnt,grid[0][3]);
                     }
                 }
             }
         }
         if(!solved){
             if(!done) printf("Case #%d: Game has not completed\n",cnt);
             else printf("Case #%d: Draw\n",cnt);
         }
     }
     return 0;
 }
                     
                     
                 
         
