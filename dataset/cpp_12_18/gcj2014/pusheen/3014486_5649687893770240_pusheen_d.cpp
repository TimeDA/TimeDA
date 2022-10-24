#include<stdio.h>
 #include<string.h>
 #include<algorithm>
 //#define DEBUG
 #ifdef DEBUG
 #define CASET printf("Case #%d: \n",T)
 #define eprintf(...) printf(__VA_ARGS__)
 #else
 #define CASET printf("Case #%d: ",T)
 #define eprintf(...) 
 #endif
 struct S {
 	char s[101];
 	int len;
 	bool operator<(S x)const {
 		return strcmp(s,x.s)<0;
 	}
 }s[1001];
 int cnt[101];
 int in[1001];
 int tt[101][1001];
 int ans[100001];
 void go(int m,int n,int dep){
 	int i,j,k;
 	if(dep==m){
 		for(i=0;i<n;i++){
 			if(!cnt[i])return;
 		}
 		int t=n;
 		for(i=0;i<n;i++){
 			int r=s[tt[i][0]].len;
 			for(j=1;j<cnt[i];j++){
 				for(k=0;k<s[tt[i][j]].len;k++){
 					if(k>=s[tt[i][j-1]].len||s[tt[i][j-1]].s[k]!=s[tt[i][j]].s[k])r++;
 				}
 			}
 			t+=r;
 		}
 		ans[t]++;
 		return;
 	}
 	
 	for(i=0;i<n;i++){
 		in[dep]=i;
 		tt[i][cnt[i]++]=dep;
 		go(m,n,dep+1);
 		cnt[i]--;
 	}
 }
 struct ANS {
 int a,b;
 };
 ANS solve(){
 	int i,j,k;
 	int n,m;
 	scanf("%d%d",&m,&n);
 	int sum=0;
 	for(i=0;i<m;i++){
 		scanf("%s",s[i].s);
 		sum+=s[i].len=strlen(s[i].s);
 	}
 	sum+=n;
 	std::sort(s,s+m);
 	for(i=sum;i>=0;i--){
 		ans[i]=0;
 	}
 	go(m,n,0);
 	for(i=sum;i>=0;i--){
 		if(ans[i])break;
 	}
 	return (ANS){i,ans[i]};
 }
 int main(){
 	int T,TN=1000000;
 #ifndef DEBUG
 	scanf("%d",&TN);
 #endif
 	for(T=1;T<=TN;T++){
 		CASET;
 		ANS k=solve();
 		//if(k==-1){
 		///	puts("NOT POSSIBLE");
 		//} else {
 			printf("%d %d\n",k.a,k.b);
 		//}
 	}
 }
