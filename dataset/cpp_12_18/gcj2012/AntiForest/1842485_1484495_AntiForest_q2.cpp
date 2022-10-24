#include <cstdio>
 #include <algorithm>
 using namespace std;
 struct node{
     long long x,y;
 };
 struct _student{
     int id;
     int width;
 };
 node studPos[1050];
 _student students[1050];
 bool placed[1050];
 long long num,width,leng,numCases;
 long long curWidth,curLeng,otherWidth,sWidth;
 bool studSort(_student x,_student y){
     return x.width>y.width;
 };
 
 int main(){
     freopen("bcd.in","r",stdin);
     freopen("q2.out","w",stdout);
     scanf("%d",&numCases);
     for(int i=1;i<=numCases;i++){
         printf("Case #%d: ",i);
         scanf("%d %d %d",&num,&width,&leng);
         for(int p=1;p<=num;p++){
             scanf("%d",&students[p].width);
             students[p].id=p;
         }
         sort(students+1,students+num+1,studSort);
         curLeng=-1*students[1].width;
         for(int t=1;t<=num;t++){
             if(placed[t]){
                 continue;
             }
             curWidth=students[t].width;
             curLeng+=students[t].width;
             //printf("LENG: %d\n",curLeng);
             if(curLeng>leng){
                 assert(false);
             }
             otherWidth=width-students[t].width;
             placed[t]=true;
             studPos[students[t].id].x=0;
             studPos[students[t].id].y=curLeng;
             for(int p=t+1;p<=num;p++){
                 //printf("%d\n",p);
                 if(otherWidth<=0){
                     break;
                 }
                 if(placed[p]){
                     continue;
                 }
                 //printf("Here\n");
                 if(students[p].width<=otherWidth){
                     //printf("In\n");
                     sWidth=students[p].width;
                     placed[p]=true;
                     studPos[students[p].id].x=curWidth+sWidth;
                     studPos[students[p].id].y=curLeng;
                     otherWidth-=students[p].width*2;
                     curWidth+=students[p].width*2;
                 }
             }
             curLeng+=students[t].width;
         }
         for(int i=1;i<=num;i++){
             if(studPos[i].x<0 || studPos[i].x>width) printf("BAD\n");
             if(studPos[i].y<0 || studPos[i].y>leng) printf("VERY BAD\n");
             printf("%lld.0 %lld.0 ",studPos[i].x,studPos[i].y);
             placed[i]=false;
             students[i].width=0;
         }
         printf("\n");
     }
     return 0;
 }
 
 
