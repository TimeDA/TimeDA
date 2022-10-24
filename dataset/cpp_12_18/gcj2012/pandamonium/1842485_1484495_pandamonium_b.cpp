#include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 struct circle{
     int r,n;
 };
 typedef struct circle circle;
 circle circ[15];
 bool cmp(circle a, circle b){
     return a.r>b.r;
 }
 int t,n,w,l,x,y,z;
 int dcnt,xc[15],yc[15],cnt;
 bool done[15];
 int main(){
     scanf("%d",&t);
     for(x=1;x<=t;x++){
         scanf("%d %d %d",&n,&w,&l);
         for(y=0;y<n;y++){
             scanf("%d",&circ[y].r);
             circ[y].n=y;
         }
         if(n==1){
             printf("Case #%d: 0 0\n",x);
             continue;
         }
         if(n==2){
             printf("Case #%d: 0 0 %d %d\n",x,w,l);
             continue;
         }
         sort(circ,circ+n,cmp);
         xc[circ[0].n]=0;
         yc[circ[0].n]=0;
         cnt=circ[0].r;
         memset(done,0,sizeof(done));
         done[0]=1;
         dcnt=1;
         if(w>=l){
             for(y=1;y<n;y++){
                 if(circ[0].r+circ[y].r<=l){
                     xc[circ[y].n]=0;
                     yc[circ[y].n]=l;
                     done[y]=1;
                     dcnt++;
                     break;
                 }
             }
             if(!done[y]){
                 xc[circ[1].n]=w;
                 yc[circ[1].n]=0;
             for(y=2;y<n;y++){
                 if(done[y]) continue;
                 if(circ[1].r+circ[y].r<=l){
                     xc[circ[y].n]=w;
                     yc[circ[y].n]=l;
                     done[y]=1;
                     dcnt++;
                     break;
                 }
             }
             }
             else{
                 xc[circ[2].n]=w;
                 yc[circ[2].n]=0;
             for(y=3;y<n;y++){
                 if(done[y]) continue;
                 if(circ[2].r+circ[y].r<=l){
                     xc[circ[y].n]=w;
                     yc[circ[y].n]=l;
                     done[y]=1;
                     dcnt++;
                     break;
                 }
             }
             }
                 while(dcnt<n){
                     for(y=1;y<n;y++){
                         if(!done[y]){
                             xc[circ[y].n]=cnt+circ[y].r;
                             yc[circ[y].n]=0;
                             for(z=y+1;z<n;z++){
                                 if(done[z]) continue;
                                 if(circ[y].r+circ[z].r<=l){
                                     xc[circ[z].n]=cnt+circ[y].r;
                                     yc[circ[z].n]=l;
                                     done[z]=1;
                                     dcnt++;
                                     break;
                                 }
                             }
                             cnt+=2*circ[y].r;
                             done[y]=1;
                             dcnt++;
                         }
                     }
                 }
         }
         else{
             for(y=1;y<n;y++){
                 if(circ[0].r+circ[y].r<=l){
                     xc[circ[y].n]=w;
                     yc[circ[y].n]=0;
                     done[y]=1;
                     dcnt++;
                     break;
                 }
             }
             if(y>1){
                 xc[circ[1].n]=0;
                 yc[circ[1].n]=l;
             for(y=2;y<n;y++){
                 if(done[y]) continue;
                 if(circ[1].r+circ[y].r<=l){
                     xc[circ[y].n]=w;
                     yc[circ[y].n]=l;
                     done[y]=1;
                     dcnt++;
                     break;
                 }
             }
             }
             else{
                 xc[circ[2].n]=0;
                 yc[circ[2].n]=l;
             for(y=3;y<n;y++){
                 if(done[y]) continue;
                 if(circ[2].r+circ[y].r<=l){
                     xc[circ[y].n]=w;
                     yc[circ[y].n]=l;
                     done[y]=1;
                     dcnt++;
                     break;
                 }
             }
             }
                 while(dcnt<n){
                     for(y=1;y<n;y++){
                         if(!done[y]){
                             xc[circ[y].n]=0;
                             yc[circ[y].n]=cnt+circ[y].r;
                             for(z=y+1;z<n;z++){
                                 if(done[z]) continue;
                                 if(circ[y].r+circ[z].r<=l){
                                     xc[circ[z].n]=w;
                                     yc[circ[z].n]=cnt+circ[y].r;
                                     done[z]=1;
                                     dcnt++;
                                     break;
                                 }
                             }
                             cnt+=2*circ[y].r;
                             done[y]=1;
                             dcnt++;
                         }
                     }
                 }
         }
         printf("Case #%d:",x);
         for(y=0;y<n;y++){
             printf(" %d %d",xc[y],yc[y]);
         }
         printf("\n");
     }
     return 0;
 }
