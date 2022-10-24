#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 const long long mod=1000000007;
 
 long long dp[110][2];
 
 int R,C;
 
 long long solve(int R,int C){
 	
 	if(C%3!=0){
 		if(R%3==0){
 			return 2;
 		}else{
 			return 1;
 		}
 	}/*
 	dp[1][1]=1;
 	dp[2][1]=*/
 	if(C==3){
 		if(R==2) return 2;
 		if(R==3) return 2;
 		if(R==4) return 3;
 		if(R==5) return 3;
 		if(R==6) return 5;
 	}
 	if(C==6){
 		if(R==2) return 3;
 		if(R==3) return 2;
 		if(R==4) return 5;
 		if(R==5) return 5;
 		if(R==6) return 17;
 	}
 	return -1;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		int R,C;
 		scanf("%d%d",&R,&C);
 		long long ans=solve(R,C);
 		if(C==4){
 			if(R==3) ans++;
 			else if(R==4){
 			}else if(R==5){
 				ans+=2;
 			}else if(R==6){
 				ans+=2;
 			}
 		}
 		printf("Case #%d: %lld\n",datano,ans);
 	}
 	return 0;
 }
