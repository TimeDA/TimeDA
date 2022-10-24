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
 
 bool isPrime[100000000];
 int PP=1000000;
 vector<long long> prime;
 
 int solve(int cc){
 
     for(int i=0;i<PP;i++){
         isPrime[i]=true;
     }
     isPrime[0]=isPrime[1]=false;
     for(int i=0;i<PP;i++){
         if(isPrime[i]){
             for(int j=i*2;j<PP;j+=i){
                 isPrime[j]=false;
             }
         }
     }
     for(int i=0;i<=PP;i++){
         if(isPrime[i]){
             prime.push_back(i);
         }
     }
 
 //    printf("%d\n",prime.size());
 //    for(int i=0;i<20;i++){
 //        printf("%d\n",prime[i]);
 //    }
 
 
     long long m = 32769;
 //    long long m = 2147483649;
 
     int N=16;
 //    int N=32
     int J=50;
 //    int J=500;
 
     printf("Case #%d:\n",cc);
     int cnt = 0;
     while(cnt<J){
         int m2[50];
         {
             long long tmp = m;
             for(int i=0;i<N;i++){
                 m2[i]=tmp%2;
                 tmp/=2;
             }
         }
         m+=2;
         vector<long long> sol;
         for(int i=2;i<=10;i++){
             long long mn=0;
             {
                 long long mul=1;
                 for(int j=0;j<N;j++){
                     mn+=(mul*m2[j]);
                     mul*=i;
                 }
             }
 //            printf("%lld ",mn);
             long long divider = -1;
             for(int i=0;i<prime.size();i++){
                 if(prime[i]*prime[i]>=mn){
                     break;
                 }
                 if(mn%prime[i]==0){
                     divider=prime[i];
                     break;
                 }
             }
             if(divider!=-1){
                 sol.push_back(divider);
             }else{
                 break;
             }
         }
         if(sol.size()!=9){
             continue;
         }
         for(int i=N-1;i>=0;i--){
             printf("%d",m2[i]);
         }
         for(int i=0;i<9;i++){
             printf(" %lld",sol[i]);
         }
         printf("\n");
         cnt++;
     }
 
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     solve(1);
 
 	return 0;
 }
