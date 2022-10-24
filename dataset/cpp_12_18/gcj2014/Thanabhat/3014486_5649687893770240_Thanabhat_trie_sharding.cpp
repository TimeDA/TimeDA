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
 
 int M,N;
 char str[16][16];
 int g[16];
 int len[16];
 int sol_max;
 int sol_count;
 
 int rec(int ind){
     if(ind==M){
         vector<int> v[4];
         for(int i=0;i<M;i++){
             v[g[i]].push_back(i);
         }
         for(int i=0;i<N;i++){
             if(v[i].size()==0){
                 return 1;
             }
         }
 //        for(int i=0;i<N;i++){
 //            printf("%d: ");
 //            for(int j=0;j<v[i].size();j++){
 //                printf("%d ",v[i][j]);
 //            }
 //            printf("\n");
 //        }
 //        printf("\n");
 
         int tmp_max=0;
         for(int i=0;i<N;i++){
             set<string> s;
             for(int j=0;j<v[i].size();j++){
                 int s_ind=v[i][j];
                 char tmp[16];
                 for(int k=0;k<len[s_ind];k++){
                     tmp[k]=str[s_ind][k];
                     tmp[k+1]=0;
                     stringstream ss;
                     string sss;
                     ss<<tmp;
                     ss>>sss;
                     s.insert(sss);
                 }
             }
             tmp_max+=s.size()+1;
         }
         if(tmp_max==sol_max){
             sol_count++;
         }else if(tmp_max>sol_max){
             sol_count=1;
             sol_max=tmp_max;
         }
         return 1;
     }
     for(int i=0;i<N;i++){
         g[ind]=i;
         rec(ind+1);
     }
     return 1;
 }
 
 int solve(int cc){
     scanf("%d %d",&M,&N);
     for(int i=0;i<M;i++){
         scanf("%s",str[i]);
         len[i]=strlen(str[i]);
     }
     sol_max=0;
     sol_count=0;
     rec(0);
 
     printf("Case #%d: %d %d\n",cc,sol_max,sol_count);
 
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int t;
     scanf("%d",&t);
     for(int i=0;i<t;i++){
         solve(i+1);
     }
 
 	return 0;
 }
