#include<stdio.h>
#include<algorithm>
using std::max;
int T,R,C;
char s[31][31];
int vis[21][21],last;
int G[21][21];
int const dx[4]={0,1,0,-1};
int const dy[4]={1,0,-1,0};
int msk;
inline bool inrange(int x,int y){
	return 0<=x&&x<R&&0<=y&&y<C;
}
int dfs(int x,int y){
	vis[x][y]=last;
	int ret=1;
	for(int i=0;i<4;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(inrange(nx,ny)&&G[nx][ny]&&vis[nx][ny]!=last){
			ret+=dfs(nx,ny);
		}
	}
	return ret;
}
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d%d",&R,&C);
		for(int i=0;i<R;++i){
			scanf("%s",s[i]);
			for(int j=0;j<C;++j) s[i][j]=(s[i][j]=='W');
		}
		msk=0;
		for(int i=0;i<R;++i) for(int j=0;j<C;++j){
			int c=0;
			if(i<R-1&&j<C-1){
				c=s[i+1][j+1]*8+s[i+1][j]*4+s[i][j+1]*2+s[i][j];
				msk|=1<<c;
			}
			if(i<R-1){
				c=s[i+1][j]*8+s[i+1][j]*4+s[i][j]*2+s[i][j];
				msk|=1<<c;
			}
			if(j<C-1){
				c=s[i][j+1]*8+s[i][j]*4+s[i][j+1]*2+s[i][j];
				msk|=1<<c;
			}
			c=s[i][j]*8+s[i][j]*4+s[i][j]*2+s[i][j];
			msk|=1<<c;
		}
		int ans=0;
		for(int p=0;p<16;++p) if((msk>>p)&1){
			for(int i=0;i<=R;++i) for(int j=0;j<=C;++j){
				for(int k=0;k<R;++k) for(int l=0;l<C;++l){
					int f=(k<i?0:2)+(l<j?0:1);
					G[k][l]=(s[k][l]==((p>>f)&1));
				}
				++last;
				for(int k=0;k<R;++k) for(int l=0;l<C;++l) if(G[k][l]&&vis[k][l]!=last){
					ans=max(ans,dfs(k,l));
				}
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
