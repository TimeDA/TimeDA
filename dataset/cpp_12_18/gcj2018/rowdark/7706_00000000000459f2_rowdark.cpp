#include<stdio.h>
#include<algorithm>
using std::max;
char s[201][201];
int N,T;
int B[201];
int Abs(int x){
	return x<0?-x:x;
}
void FillLeft(int l,int r,int p,int R){
	if(l==p) return;
	for(int i=l;i<=r&&i<p;++i) s[R][i]='\\';
	FillLeft(l+1,r+1,p,R+1);
}
void FillRight(int l,int r,int p,int R){
	if(r==p) return;
	for(int i=r;i>=l&&i>p;--i) s[R][i]='/';
	FillRight(l-1,r-1,p,R+1);
}
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d",&N);
		for(int i=1;i<=N;++i){
			scanf("%d",B+i);
		}
		printf("Case #%d: ",tt);
		if(!B[1]||!B[N]){
			printf("IMPOSSIBLE\n");
			continue;
		}
		int R=0;
		for(int i=1,l=1;i<=N;++i){
			int r=l+B[i]-1;
			R=max(R,max(Abs(l-i),Abs(r-i)));
			l+=B[i];
		}
		printf("%d\n",R+1);
		for(int i=0;i<=R;++i){
			for(int j=1;j<=N;++j) s[i][j]='.';
			s[i][N+1]=0;
		}
		for(int i=1,l=1;i<=N;++i){
			int r=l+B[i]-1;
			if(l<=r){
				if(r<=i){
					FillLeft(l,r,i,0);
				}
				else if(l>=i){
					FillRight(l,r,i,0);
				}
				else{
					FillLeft(l,i,i,0);
					FillRight(i,r,i,0);
				}
			}
			l+=B[i];
		}
		for(int i=0;i<=R;++i) printf("%s\n",s[i]+1);
	}
	return 0;
}
