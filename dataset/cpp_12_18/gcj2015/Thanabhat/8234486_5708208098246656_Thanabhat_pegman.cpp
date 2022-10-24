/*
 AUTHOR: THANABHAT KOOMSUBHA
 LANG: C++
 */
 
 #include<cstdio>
 #include<cstdlib>
 #include<algorithm>
 #include<cmath>
 #include<functional>
 #include<vector>
 #include<list>
 #include<set>
 #include<queue>
 #include<map>
 #include<cctype>
 #include<cstring>
 #include<string>
 #include<sstream>
 #include<iostream>
 #include<ctime>
 
 using namespace std;
 
 int R,C;
 char str[105][105];
 int m[105][105];
 
 int solve(int cc){
     int sol=0;
     scanf("%d %d",&R,&C);
     for(int i=0;i<R;i++){
         scanf("%s",str[i]);
     }
     for(int i=0;i<R;i++){
         for(int j=0;j<C;j++){
             m[i][j]=0;
         }
     }
     for(int i=0;i<R;i++){
         for(int j=0;j<C;j++){
             if(str[i][j]!='.'){
                 m[i][j]=1;
                 break;
             }
         }
     }
     for(int i=0;i<R;i++){
         for(int j=C-1;j>=0;j--){
             if(str[i][j]!='.'){
                 m[i][j]=1;
                 break;
             }
         }
     }
     for(int j=0;j<C;j++){
         for(int i=0;i<R;i++){
             if(str[i][j]!='.'){
                 m[i][j]=1;
                 break;
             }
         }
     }
     for(int j=0;j<C;j++){
         for(int i=R-1;i>=0;i--){
             if(str[i][j]!='.'){
                 m[i][j]=1;
                 break;
             }
         }
     }
 //    for(int i=0;i<R;i++){
 //        for(int j=0;j<C;j++){
 //            printf("%d",m[i][j]);
 //        }
 //        printf("\n");
 //    }
 
     for(int i=0;i<R;i++){
         for(int j=0;j<C;j++){
             if(m[i][j]){
                 int d0=0,d1=0,d2=0,d3=0;
                 for(int k=i-1;k>=0;k--){
                     if(str[k][j]!='.'){
                         d0=1;
                     }
                 }
                 for(int k=j+1;k<C;k++){
                     if(str[i][k]!='.'){
                         d1=1;
                     }
                 }
                 for(int k=i+1;k<R;k++){
                     if(str[k][j]!='.'){
                         d2=1;
                     }
                 }
                 for(int k=j-1;k>=0;k--){
                     if(str[i][k]!='.'){
                         d3=1;
                     }
                 }
                 if(d0==0&&d1==0&&d2==0&&d3==0){
                     sol=1000000;
                 }else{
                     if(str[i][j]=='^'&&d0==0){
                         sol++;
                     }else if(str[i][j]=='>'&&d1==0){
                         sol++;
                     }else if(str[i][j]=='v'&&d2==0){
                         sol++;
                     }else if(str[i][j]=='<'&&d3==0){
                         sol++;
                     }
                 }
             }
         }
     }
     if(sol<1000000){
         printf("Case #%d: %d\n",cc,sol);
     }else{
         printf("Case #%d: IMPOSSIBLE\n",cc,sol);
     }
 
 
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int T;
     scanf("%d",&T);
     for(int i=1;i<=T;i++){
         solve(i);
     }
 
 	return 0;
 }
