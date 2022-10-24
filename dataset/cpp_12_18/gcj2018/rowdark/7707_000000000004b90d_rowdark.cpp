#include<stdio.h>
#include<algorithm>
using namespace std;
inline int Sign(long long x){
	return x<0?-1:x>0;
}
struct point{
	long long x,y,z;
	void read(){
		scanf("%lld%lld%lld",&x,&y,&z);
	}
	point(){}
	point(long long x,long long y,long long z):x(x),y(y),z(z){}
	point operator +(point const &a)const{
		return point(x+a.x,y+a.y,z+a.z);
	}
	point operator -(point const &a)const{
		return point(x-a.x,y-a.y,z-a.z);
	}
	void show()const{
		printf("%lld %lld %lld\n",x,y,z);
	}
}P[2011];
point det(point const &a,point const &b){
	return point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
long long dot(point const &a,point const &b){
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
bool V[2011];
int N,T;
int ans[2011];
bool dfs(int num,int x,int y,int z){
//	printf("!!!%d: ",num);
//	for(int i=0;i<num;++i) printf("%d ",ans[i]);
//	printf("\n");
	if(x!=-1){
		point O(P[x].x,P[x].y,0);
		point S=det(P[y]-P[x],P[z]-P[x]);
		int Fsig=Sign(dot(S,O-P[x]));
		for(int i=0;i<N;++i){
			if(V[i]&&i!=x&&i!=y&&i!=z&&Sign(dot(S,P[i]-P[x]))!=Fsig){
//				S.show();
//				P[i].show();
//				printf("Error %d: %d %lld\n",i,Fsig,dot(S,P[i]-P[x]));
				return false;
			}
		}
	}
	if(num==N) return true;
	for(int i=0;i<N;++i) if(!V[i]){
		V[i]=1;
		ans[num]=i;
		if(dfs(num+1,y,z,i)) return true;;
		V[i]=0;
	}
	return false;
}
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d",&N);
		for(int i=0;i<N;++i) P[i].read(),V[i]=0;;
		printf("Case #%d: ",tt);
		if(dfs(0,-1,-1,-1)){
			for(int i=0;i<N;++i) printf("%d%c",ans[i]+1,i==N-1?'\n':' ');
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}
