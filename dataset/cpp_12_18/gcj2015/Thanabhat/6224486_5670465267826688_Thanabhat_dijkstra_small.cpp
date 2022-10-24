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
 
 char STR[10005];
 char TMP[10005];
 /*  0 1 2 3 -4 -3 -2 -1
     1 i j k -1 -i -j -k */
 int MP[4][4]=
 {
     {0,1,2,3},
     {1,-4,3,-2},
     {2,-1,-4,1},
     {3,2,-3,-4}
 };
 int CUM[10005];
 
 int mmmp(int in){
     if(in>=0&&in<4){
         return in;
     }
     if(in<0){
         return in+4;
     }
     return 999;
 }
 
 int calc(int be,int en){
     if(be==0){
         return CUM[0,en];
     }
 
     int bb=CUM[0,be-1];
     int gg=CUM[0,en];
     for(int i=0;i<4;i++){
         if(MP[mmmp(bb)][i]==gg){
             if(bb<0){
                 return i-4;
             }else{
                 return i;
             }
         }
     }
     return 999;
 }
 
 int solve(int cc){
     int L,X;
     scanf("%d %d",&L,&X);
     scanf("%s",TMP);
     for(int i=0;i<X;i++){
         for(int j=0;j<L;j++){
             STR[i*L+j]=TMP[j];
         }
     }
     int LL=L*X;
     STR[LL]=0;
 
     CUM[0]=STR[0]-'i'+1;
     for(int i=1;i<LL;i++){
         if(CUM[i-1]<0){
             int tmp=MP[mmmp(CUM[i-1])][mmmp(STR[i]-'i'+1)];
             if(tmp<0){
                 tmp+=4;
             }else{
                 tmp-=4;
             }
             CUM[i]=tmp;
         }else{
             CUM[i]=MP[mmmp(CUM[i-1])][mmmp(STR[i]-'i'+1)];
         }
     }
 //    for(int i=0;i<LL;i++){
 //        printf("%d ",CUM[i]);
 //    }
 //    printf("\n");
 
     bool sol=false;
     for(int i=1;i<LL-1;i++){
         for(int j=i+1;j<LL;j++){
 //            printf("%d %d:",i,j);
             if(calc(0,i-1)==1&&calc(i,j-1)==2&&calc(j,LL-1)==3){
                 sol=true;
             }
 //            printf("\n");
         }
     }
     if(sol){
         printf("Case #%d: YES\n",cc);
     }else{
         printf("Case #%d: NO\n",cc);
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
