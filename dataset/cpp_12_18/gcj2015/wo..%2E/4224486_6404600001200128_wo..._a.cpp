#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 int N;
 int a[1010];
 
 int solve1(){
 	int res=0;
 	for(int i=0;i<N-1;i++){
 		res+=max(0,a[i]-a[i+1]);
 	}
 	return res;
 }
 
 int solve2(){
 	int m=0;
 	int res=0;
 	for(int i=0;i<N-1;i++) m=max(m,a[i]-a[i+1]);
 	for(int i=0;i<N-1;i++){
 		if(a[i]<=m) res+=a[i];
 		else res+=m;
 	}
 	return res;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		scanf("%d",&N);
 		for(int i=0;i<N;i++) scanf("%d",a+i);
 		printf("Case #%d: %d %d\n",datano,solve1(),solve2());
 	}
 	return 0;
 }
