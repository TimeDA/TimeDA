#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 int B;
 long long M[1010];
 
 vector<int> vec;
 long long get(long long t){
 	vec.clear();
 	long long res=0;
 	for(int i=0;i<B;i++){
 		long long tmp=t/M[i];
 		if(t%M[i]==0){
 			vec.push_back(i);
 		}else{
 			tmp++;
 		}
 		res+=tmp;
 	}
 	return res;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		int N;
 		scanf("%d%d",&B,&N);
 		for(int i=0;i<B;i++) scanf("%lld",M+i);
 		long long lb=-1,ub=1e10;
 		int ans=-1;
 		while(ub-lb>1){
 			long long mid=(ub+lb)/2;
 			long long num=get(mid);
 			if(num+vec.size()<N){
 				lb=mid;
 				continue;
 			}else if(num>=N){
 				ub=mid;
 				continue;
 			}
 			int id=N-num-1;
 			ans=vec[id];
 			break;
 		}
 		printf("Case #%d: %d\n",datano,ans+1);
 	}
 	return 0;
 }
