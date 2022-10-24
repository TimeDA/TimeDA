#include<stdio.h>
 int n,m,r;
 int t[10001],v[10001];
 void input(){
 	int i,j,k;
 	scanf("%d%d%d",&n,&m,&r);
 	for(i=0;i<n;i++){
 		t[i]=0;
 	}
 	for(i=0;i<m;i++){
 		v[i]=0;
 	}
 	for(i=0;i<r;i++){
 		int a,b;
 		scanf("%d%d",&a,&b);
 		a--;
 		b--;
 		t[a]++;
 		v[b]++;
 	}
 }
 void solve(int T){
 	int i,j,k=0;
 	int ans=0;
 	for(i=0;i<m;i++){
 		if(ans<v[i]) ans=v[i];
 	}
 	for(i=0;i<n;i++){
 		k+=t[i];
 		if(ans<(k+i)/(i+1)){
 			ans=(k+i)/(i+1);
 		}
 	}
 	int ans2=0;
 	for(i=0;i<n;i++){
 		if(t[i]>ans) ans2+=t[i]-ans;
 	}
 	printf("Case #%d: %d %d\n", T,ans,ans2);
 }
 int main(int argc, char *argv[]){
 	int T,TN;
 	scanf("%d",&TN);
 	int w;
 	if(argc>1&&sscanf(argv[1],"%d",&w)==1);
 	else w=-1;
 	for(T=1;T<=TN;T++){
 		input();
 		if(w==-1||T==w) solve(T);
 	}
 }
