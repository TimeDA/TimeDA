#include<stdio.h>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
void sample(int N, vector<pair<int,int>> &ret){
	static int D[51];
	while(true){
		for(int i=0;i<N;++i) D[i]=4;
		static int C[4];
		bool flag=false;
		ret.clear();
		for(int i=N-1;i>0;--i) if(D[i]){
			for(int j=0;j<D[i];++j) C[j]=-1;
			int cnt=0;
			int sumD=0;
			for(int j=i-1;j>=0;--j) if(D[j]){
				sumD+=D[j];
				if(cnt!=D[i]){
					C[cnt++]=j;
				}
				else{
					if(rand()%sumD<D[j]){
						C[rand()%D[i]]=j;
					}
				}
			}
			if(cnt!=D[i]){
				flag=true;
				break;
			}
			else{
				for(int j=0;j<D[i];++j) ret.emplace_back(i,C[j]),--D[C[j]];
				D[i]=0;
			}
		}
		if(!D[0]&&!flag) break;
	}
}

struct matrix{
	long long D[51][51];
	long long *operator[](int dn){
		return D[dn];
	}
	void show(int N)const{
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j) fprintf(stderr,"%d ",int(D[i][j]));
			fprintf(stderr,"\n");
		}
	}
}A,B,C,D,E;
const int mod = 1000000007;
void mul(matrix &X,matrix &Y,int N){//X=X*Y
	for(int i=0;i<N;++i) for(int j=0;j<N;++j) for(int k=0;k<N;++k){
		C[i][j]+=X[i][k]*Y[k][j]%mod;
	}
	for(int i=0;i<N;++i) for(int j=0;j<N;++j) X[i][j]=C[i][j]%mod,C[i][j]=0;
}
void buildD(vector<pair<int,int>> const &V,int N){
	for(int i=0;i<N;++i) for(int j=0;j<N;++j) D[i][j]=E[i][j]=0;
	for(int i=0;i<N;++i) E[i][i]=1;
	for(auto &&x: V) D[x.first][x.second]=D[x.second][x.first]=1;
}
void Pow(int N,int S){
	A=E,B=D;
	while(S){
		if(S&1) mul(A,B,N);
		mul(B,B,N);
		S>>=1;
	}
}
map<vector<int>,int> M;
int const step=1000000000;
bool check(vector<pair<int,int>> const &V,int N){
	M.clear();
	buildD(V,N);
	Pow(N,step);
	vector<int> tmp(N,0);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(!A[i][j]) return false;
			tmp[j]=A[i][j];
		}
		sort(tmp.begin(),tmp.end());
		if(M.count(tmp)) return false;
		M[tmp]=i;
	}
	//fprintf(stderr,"PreA:\n");
	//A.show(N);
	return true;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		int N,NN;
		scanf("%d",&N);
		if(N==-1) break;//WA
		scanf("%d",&NN);
		vector<pair<int,int>> ret;
		do{
			sample(N,ret);
		}while(!check(ret,N));
		printf("%d\n",N);
		for(auto &&x:ret) printf("%d %d\n",x.first+1,x.second+1);
		fflush(stdout);
		scanf("%d",&N);
		if(N==-1) break;//WA
		ret.clear();
		for(int i=0;i<2*N;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			ret.emplace_back(x-1,y-1);
		}
		buildD(ret,N);
		Pow(N,step);
		//fprintf(stderr,"After A:\n");
		//A.show(N);
		vector<int> tmp(N,0);
		vector<int> ans(N,0);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j) tmp[j]=A[i][j];
			sort(tmp.begin(),tmp.end());
			ans[M[tmp]]=i;
		}
		for(int i=0;i<N;++i) printf("%d%c",ans[i]+1,i==N-1?'\n':' ');
		fflush(stdout);
	}
	/*for(int NN=10;NN<=50;++NN){
		vector<pair<int,int>> ret;
		printf("Case %d:\n",NN);
		do{
			sample(NN,ret);
		}while(!check(ret,NN));
		for(auto &&x:ret) printf("%d - %d\n",x.first,x.second);
	}*/
	return 0;
}
