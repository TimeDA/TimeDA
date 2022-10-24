#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 int a[1010];
 int N;
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++){
 		scanf("%d",&N);
 		for(int i=0;i<N;i++){
 			scanf("%d",a+i);
 		}
 		int ans=0;
 		for(int i=0;i<N;i++){
 			int cnt0=0,cnt1=0;
 			for(int j=0;j<i;j++) if(a[j]>a[i]) cnt0++;
 			for(int j=i+1;j<N;j++) if(a[j]>a[i]) cnt1++;
 			ans+=min(cnt0,cnt1);
 		}
 		printf("Case #%d: %d\n",datano+1,ans);
 	}
 	return 0;
 }
