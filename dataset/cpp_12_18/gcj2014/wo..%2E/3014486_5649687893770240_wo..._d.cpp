#include<cstdio>
 #include<string>
 #include<set>
 #include<vector>
 #include<iostream>
 #include<algorithm>
 
 using namespace std;
 
 string str[1010];
 
 set<string> se;
 int cnt[1<<8];
 
 int pos[8];
 int N,M;
 
 int numStr;
 int numArr;
 
 void dfs(int id){
 	if(id==M){
 		int stat[4];
 		for(int i=0;i<4;i++) stat[i]=0;
 		for(int i=0;i<M;i++){
 			stat[pos[i]]|=(1<<i);
 		}
 		int tmp=0;
 		for(int i=0;i<N;i++){
 			tmp+=cnt[stat[i]];
 		}
 		if(numStr==-1||numStr<tmp){
 			numStr=tmp;
 			numArr=1;
 		}else if(numStr==tmp){
 			numArr++;
 		}
 		return;
 	}else{
 		for(int i=0;i<N;i++){
 			pos[id]=i;
 			dfs(id+1);
 		}
 	}
 }
 
 int main(){
 	int T;
 	cin>>T;
 	for(int datano=0;datano<T;datano++){
 		cin>>M>>N;
 		for(int i=0;i<M;i++) cin>>str[i];
 		for(int stat=0;stat<(1<<M);stat++){
 			se.clear();
 			for(int i=0;i<M;i++){
 				if((stat>>i)&1){
 					string s=str[i];
 					int n=s.size();
 					for(int j=0;j<=n;j++){
 						se.insert(s.substr(0,j));
 					}
 				}
 			}
 			cnt[stat]=se.size();
 		}
 		numStr=-1;
 		numArr=0;
 		dfs(0);
 		printf("Case #%d: %d %d\n",datano+1,numStr,numArr);
 	}
 	return 0;
 }
