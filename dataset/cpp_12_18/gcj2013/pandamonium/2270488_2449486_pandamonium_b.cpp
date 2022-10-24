#include <cstdio>
 #include <cstring>
 using namespace std;
 int t,n,m,x,y,z,cnt=0;
 int grid[105][105];
 bool row[105],col[105],fail;
 int main(){
     scanf("%d",&t);
     while(t--){
         cnt++;
         scanf("%d %d",&n,&m);
         for(x=0;x<n;x++){
             for(y=0;y<m;y++){
                 scanf("%d",&grid[x][y]);
             }
         }
         fail=0;
         for(x=1;x<100;x++){
             memset(row,0,sizeof(row));
             memset(col,0,sizeof(col));
             for(y=0;y<n;y++){
                 for(z=0;z<m;z++){
                     if(grid[y][z]!=x) break;
                     if(z==m-1){
                         row[y]=1;
                     }
                 }
             }
             for(y=0;y<m;y++){
                 for(z=0;z<n;z++){
                     if(grid[z][y]!=x) break;
                     if(z==n-1){
                         col[y]=1;
                     }
                 }
             }
             for(y=0;y<n;y++){
                 for(z=0;z<m;z++){
                     if(grid[y][z]==x){
                         if(row[y]||col[z]) grid[y][z]++;
                         else{
                             fail=1;
                             break;
                         }
                     }
                 }
                 if(fail) break;
             }
             if(fail) break;
         }
         printf("Case #%d: ",cnt);
         if(!fail) printf("YES\n");
         else printf("NO\n");
     }
     return 0;
 }
