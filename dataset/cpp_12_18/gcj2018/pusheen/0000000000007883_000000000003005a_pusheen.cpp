#include<stdio.h>
#include<algorithm>
char s[101][101];
int p[102],q[102];
bool solve(){
	int n,m,a,b;
	int c=0;
	int i,j;
	int h[102],hn=0;
	int v[102],vn=0;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
		for(j=0;j<m;j++){
			if(s[i][j]=='@'){
				c++;
			}
		}
	}
	if(!c&&a<n&&b<m) return true;
	for(i=0;i<n;i++){
		p[i]=0;
	}
	for(j=0;j<m;j++){
		q[j]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(s[i][j]=='@'){
				p[i]++;
				q[j]++;
			}
		}
	}
	if(c%((a+1)*(b+1))) return false;
	int d=c/(a+1);
	for(i=0;i<n;i=j){
		int x=0;
		for(j=i;j<n&&x<d;j++){
			x+=p[j];
		}
		if(!x&&hn>=a+1) break;
		if(x!=d) return false;
		h[hn++]=j; //[0, j)
	}
	if(hn!=a+1) return false;
	int e=c/(b+1);
	for(i=0;i<m;i=j){
		int x=0;
		for(j=i;j<m&&x<e;j++){
			x+=q[j];
		}
		if(!x&&vn>=b+1) break;
		if(x!=e) return false;
		v[vn++]=j; //[0, j)
	}
	if(vn!=b+1) return false;
	int f=c/(a+1)/(b+1);
	for(i=0;i<hn;i++){
		for(j=0;j<vn;j++){
			int ii,jj,kk=0;
			for(ii=!i?0:h[i-1];ii<h[i];ii++){
				for(jj=!j?0:v[j-1];jj<v[j];jj++){
					if(s[ii][jj]=='@'){
						kk++;
					}
				}
			}
			if(kk!=f) return false;
		}
	}
	return true;
}
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		puts(solve()?"POSSIBLE":"IMPOSSIBLE");
	}
}