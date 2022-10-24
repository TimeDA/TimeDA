#include <cstdio>
 #include <algorithm>
 using namespace std;
 struct _vine{
     int plc;
     int leng;
 };
 _vine vines[10050];
 bool canReach[10050];
 int bestReach[10050];
 int num,numCases,dist,besSoFar,curVineLeng;
 bool isPossible;
 
 
 int main(){
     freopen("q1-small.in","r",stdin);
     freopen("q1.out","w",stdout);
     scanf("%d",&numCases);
     for(int i=1;i<=numCases;i++){
         printf("Case #%d: ",i);
         scanf("%d",&num);
         for(int p=1;p<=num;p++){
             scanf("%d %d",&vines[p].plc,&vines[p].leng);
         }
         scanf("%d",&dist);
         canReach[1]=true;
         bestReach[1]=min(vines[1].plc,vines[1].leng);
         besSoFar=bestReach[1];
         for(int p=1;p<=num;p++){
             if(besSoFar>=dist){
                 isPossible=true;
                 break;
             }
             if(canReach[p]){
                 if(bestReach[p]+vines[p].plc>besSoFar){
                     besSoFar=bestReach[p]+vines[p].plc;
                 }
                 for(int t=p+1;t<=num;t++){
                     if(vines[t].plc>vines[p].plc+bestReach[p]){
                         break;
                     }
                     curVineLeng=min(vines[t].plc-vines[p].plc,vines[t].leng);
                     if(!canReach[t] || curVineLeng>bestReach[t]){
                         canReach[t]=true;
                         bestReach[t]=curVineLeng;
                     }
                 }
             }
             if(besSoFar>=dist){
                 isPossible=true;
                 break;
             }
         }
         if(isPossible){
             printf("YES\n");
         } else{
             printf("NO\n");
         }
         for(int i=1;i<=num;i++){
             canReach[i]=false;
             bestReach[i]=false;
         }
         isPossible=false;
         besSoFar=0;
         dist=0;
         curVineLeng=0;
     }
     return 0;
 }
 
