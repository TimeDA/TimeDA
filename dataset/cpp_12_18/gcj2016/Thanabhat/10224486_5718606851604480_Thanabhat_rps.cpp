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
 
 int cnt[3];
 char indToChar[3]={'P','R','S'};
 int N;
 char sol[10000],soll;
 vector<string> vecsol;
 
 int rec(char win, int rnd, bool all){
 //    if(all){
 //        printf("%c %d %d\n",win,rnd,soll);
 //    }
     if(rnd==N){
         if(win=='P'){
             sol[soll++]='P';
             cnt[0]++;
         }
         if(win=='R'){
             sol[soll++]='R';
             cnt[1]++;
         }
         if(win=='S'){
             sol[soll++]='S';
             cnt[2]++;
         }
 //        if(all)
 //            printf("soll=%d\n",soll);
         if(all&&soll==(1<<N)){
             sol[soll++]=0;
             string aa(sol);
             vecsol.push_back(aa);
             cout<<"---"<<aa<<endl;
         }
     }else{
         if(win=='P'){
             if(all){
                 int tmp=soll;
                 rec('P',rnd+1,true);
                 rec('R',rnd+1,true);
                 soll=tmp;
                 rec('R',rnd+1,true);
                 rec('P',rnd+1,true);
             }else{
                 rec('P',rnd+1,false);
                 rec('R',rnd+1,false);
             }
         }
         if(win=='R'){
             if(all){
                 int tmp=soll;
                 rec('R',rnd+1,true);
                 rec('S',rnd+1,true);
                 soll=tmp;
                 rec('S',rnd+1,true);
                 rec('R',rnd+1,true);
             }else{
                 rec('R',rnd+1,false);
                 rec('S',rnd+1,false);
             }
         }
         if(win=='S'){
             if(all){
                 int tmp=soll;
                 rec('P',rnd+1,true);
                 rec('S',rnd+1,true);
                 soll=tmp;
                 rec('S',rnd+1,true);
                 rec('P',rnd+1,true);
             }else{
                 rec('P',rnd+1,false);
                 rec('S',rnd+1,false);
             }
         }
     }
     return 0;
 }
 
 int swapsol(int b1,int b2,int k){
     if(k>1){
         swapsol(b1,b1+k/2,k/2);
         swapsol(b2,b2+k/2,k/2);
     }
     char tmp1[5000];
     char tmp2[5000];
     for(int j=0;j<k;j++){
         tmp1[j]=sol[b1+j];
         tmp2[j]=sol[b2+j];
     }
     tmp1[k]=0;
     tmp2[k]=0;
     if(strcmp(tmp1,tmp2)>0){
         for(int j=0;j<k;j++){
             sol[b1+j]=tmp2[j];
             sol[b2+j]=tmp1[j];
         }
     }
     return 1;
 }
 
 int solve(int cc){
     int M[3];
     // P R S
     scanf("%d %d %d %d",&N,&M[1],&M[0],&M[2]);
     printf("Case #%d: ",cc);
     vecsol.clear();
     for(int i=0;i<3;i++){
         cnt[0]=cnt[1]=cnt[2]=0;
         soll=0;
         rec(indToChar[i],0,false);
 //        printf("rec %d",i);
 //        printf("%d %d %d\n",cnt[0],cnt[1],cnt[2]);
         if(cnt[0]==M[0]&&cnt[1]==M[1]&&cnt[2]==M[2]){
 //            printf("%s\n",sol);
             sol[soll++]=0;
 //            soll=0;
 //            rec(indToChar[i],0,true);
             swapsol(0,soll/2,soll/2);
             string aa(sol);
             vecsol.push_back(aa);
 //            cout<<"---"<<aa<<endl;
         }
     }
     if(vecsol.size()>0){
         sort(vecsol.begin(),vecsol.end());
         printf("%s\n",vecsol[0].c_str());
     }else{
         printf("IMPOSSIBLE\n",sol);
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
