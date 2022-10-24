#include<stdio.h>
 #include<stdlib.h>
 #include<cstring>
 #include<iostream>
 #include<ctype.h>
 #include<algorithm>
 #include<vector>
 #include<string>
 #include<set>
 #include<map>
 #include<stack>
 #include<queue>
 #include<cmath>
 #include<bitset>
 #include<iomanip>
 #include<complex>
 #include<utility>
 
 #define X first
 #define Y second
 #define REP_0(i,n) for(int i=0;i<(n);++i)
 #define REP_1(i,n) for(int i=1;i<=(n);++i)
 #define REP_2(i,a,b) for(int i=(a);i<(b);++i)
 #define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
 #define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
 #define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
 #define DOW_1(i,n) for(int i=(n);0<i;--i)
 #define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
 #define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
 #define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
 #define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
 #define PB push_back
 #define PF push_front
 #define MP make_pair
 #define IS insert
 #define ES erase
 #define IT iterator
 #define RI reserve_iterator
 #define PQ priority_queue
 #define LB lower_bound
 #define UB upper_bound
 #define ALL(x) x.begin(),x.end()
 
 #define PI 3.1415926535897932384626433832795
 #define EXP 2.7182818284590452353602874713527
 
 using namespace std;
 
 typedef long long LL;
 typedef long double LD;
 typedef double DB;
 typedef pair<int,int> PII;
 typedef vector<int> VI;
 typedef pair<int,PII> PIII;
 typedef pair<LD,int> PLDI;
 typedef vector<PII> VII;
 
 template<class T>
 T Mul(T x,T y,T P){
 	T F1=0;
 	while(y)
 	{
 		if(y&1)
 		{
 			F1+=x;
 			if(F1<0||F1>=P)F1-=P;
 		}
 		x<<=1;
 		if(x<0||x>=P)x-=P;
 		y>>=1;
 	}
 	return F1;
 }
 
 template<class T>
 T Pow(T x,T y,T P){
 	T F1=1;x%=P;
 	while(y)
 	{
 		if(y&1)
 		{
 			F1=Mul(F1,x,P);
 		}
 		x=Mul(x,x,P);
 		y>>=1;
 	}
 	return F1;
 }
 
 template<class T>
 T Gcd(T x,T y){
 	if(y==0)return x;
 	T z;
 	while(z=x%y){
 		x=y,y=z;
 	}
 	return y;
 }
 
 template<class T>
 void UpdateMin(T &x,T y){
 	if(y<x)
 	{
 		x=y;
 	}
 }
 
 template<class T>
 void UpdateMax(T &x,T y){
 	if(x<y)
 	{
 		x=y;
 	}
 }
 
 template<class T>
 T Sqr(const T x){
 	return x*x;
 }
 
 template<class T>
 T Abs(const T x){
 	return x<0?-x:x;
 }
 
 #define MaxBuffer 20000000
 class ReadBuffer{
 	private:
 	char buff[MaxBuffer];
 	char *buf;
 	public:
 	void init(int size=MaxBuffer)
 	{
 		fread(buff,1,size,stdin);
 		buf=buff;
 	}
 	template<class T>
 	bool readInteger(T &x)
 	{
 		x=0;
 		while(*buf&&isspace(*buf)) ++buf;
 		if(*buf==0) return false;
 		static bool flag;
 		flag=0;
 		if(*buf=='-') flag=true;
 		else x=*buf-'0';
 		while(isdigit(*++buf)) x=x*10+*buf-'0';
 		if(flag) x=-x;
 		return true;
 	}
 	template<class T>
 	bool readFloat(T &x)
 	{
 		long double nowpos=0.1;
 		x=0;
 		while(*buf&&isspace(*buf)) ++buf;
 		if(*buf==0) return false;
 		static bool flag,decimal;
 		decimal=flag=0;
 		if(*buf=='-') flag=true,++buf;
 		else if(*buf=='.') decimal=true;
 		while(isdigit(*buf)||*buf=='.')
 		{
 			if(*buf=='.') decimal=true;
 			else
 			{
 				if(decimal)
 				{
 					x+=nowpos*(*buf-'0');
 					nowpos*=0.1;
 				}
 				else
 				{
 					x=x*10+*buf-'0';
 				}
 			}
 			++buf;
 		}
 		return true;
 	}
 	bool readChar(char c)
 	{
 		if(*buf==0) return 0;
 		return c=*buf++,1;
 	}
 	bool readString(char *s)
 	{
 		while(*buf&&isspace(*buf)) ++buf;
 		if(!*buf) return false;
 		while(!isspace(*buf)) *s++=*buf++;
 		*s++=0;
 		return true;
 	}
 	int countSpacetonext(){
 		int total=0;
 		while(*buf&&*buf==' ') ++total,++buf;
 		return total;
 	}
 	bool splitBycharactor(char *s,char Split='\n'){
 		while(*buf&&*buf!=Split) *s++=*buf++;
 		*s++=0;
 		return *buf!=0;
 	}
 };
 
 struct EDGE{
 	int T,U;EDGE *Nxt,*Op;
 	void init(int S,int T,int U,EDGE *Op);
 }E[20000],*V[2010],*OV[2010],*PE;
 
 void EDGE::init(int S,int T,int U,EDGE *Op){
 	this->T=T;
 	this->U=U;
 	this->Nxt=V[S];
 	V[S]=this;
 	this->Op=Op;
 }
 
 int dist[2010];
 bool in[2010];
 int Q[2010];
 int QH,QT;
 int Test,S,T;
 int n,m;
 int a[2010],b[2010];
 
 void addedge(int S,int T,int U){
 	PE->init(S,T,U,PE+1),++PE;
 	PE->init(T,S,0,PE-1),++PE;
 }
 
 bool modlabel(){
 	QH=QT=-1;
 	for(int i=S;i<T;++i){
 		dist[i]=2*T;
 		OV[i]=V[i];
 		in[i]=0;
 	}
 	dist[T]=0;
 	Q[++QT]=T;
 	while(QH++!=QT){
 		int x=Q[QH];
 		if(x==S) return true;
 		for(EDGE *ii=V[x];ii;ii=ii->Nxt){
 			if(ii->Op->U){
 				if(dist[ii->T]>dist[x]+1){
 					dist[ii->T]=dist[x]+1;
 					Q[++QT]=ii->T;
 				}
 			}
 		}
 	}
 	return false;
 }
 
 int aug(int x,int limit){
 	if(x==T) return limit;
 	in[x]=1;
 	int kk,ll=limit;
 	for(EDGE* &ii=OV[x];ii;ii=ii->Nxt){
 		if(!in[ii->T]&&ii->U&&dist[ii->T]+1==dist[x]){
 			kk=aug(ii->T,min(ii->U,ll));
 			ll-=kk,ii->U-=kk,ii->Op->U+=kk;
 			if(!ll) return in[x]=0,limit;
 		}
 	}
 	return limit-ll;
 }
 
 vector<int> match[2010];
 bool used[2010];
 int ind[2010],oud[2010];
 bool inv[2010];
 bool vis[2010];
 
 void dfs(int x,int dir){
 	vis[x]=1;
 	for(int i=0;i<int(match[x].size());++i){
 		int y=match[x][i];
 		if(!used[y]){
 			used[y]=1;
 			int z=a[y]^b[y]^x;
 			if(dir){
 				if(x==a[y]){
 					++ind[x];
 					++oud[z];
 					inv[y]=1;
 				}
 				else{
 					++ind[x];
 					++oud[z];
 					inv[y]=0;
 				}
 			}
 			else{
 				if(x==b[y]){
 					++ind[z];
 					++oud[x];
 					inv[y]=1;
 				}
 				else{
 					++ind[z];
 					++oud[x];
 					inv[y]=0;
 				}
 			}
 			dfs(z,dir);
 		}
 	}
 }
 bool predir(){
 	for(int x=1;x<=n;++x) if(!vis[x]){
 		vis[x]=1;
 		for(int i=0;i<int(match[x].size());++i){
 			int y=match[x][i];
 			if(!used[y]){
 				used[y]=1;
 				int z=a[y]^b[y]^x;
 				if(ind[x]!=0&&oud[x]==0){
 					if(x==a[y]){
 						++ind[x];
 						++oud[z];
 						inv[y]=1;
 					}
 					else{
 						++ind[x];
 						++oud[z];
 						inv[y]=0;
 					}
 					dfs(z,1);
 				}
 				else{
 					if(x==b[y]){
 						++ind[z];
 						++oud[x];
 						inv[y]=1;
 					}
 					else{
 						++ind[z];
 						++oud[x];
 						inv[y]=0;
 					}
 					dfs(z,0);
 				}
 			}
 		}
 	}
 	for(int x=1;x<=n;++x){
 		if((ind[x]==0||oud[x]==0)&&(ind[x]+oud[x]!=0)) return false;
 	}
 	for(int i=0;i<m;++i){
 		if(inv[i]){
 			addedge(b[i],a[i],n*n-1);
 		}
 		else{
 			addedge(a[i],b[i],n*n-1);
 		}
 	}
 	return true;
 }
 int main(){
 	freopen("B-small-attempt0.in","r",stdin);
 	freopen("b.out","w",stdout);
 	scanf("%d",&Test);
 	REP_1(tt,Test){
 		scanf("%d%d",&n,&m);
 		PE=E;
 		for(int i=0;i<=n+1;++i) V[i]=0,match[i].clear(),ind[i]=oud[i]=0,vis[i]=0;
 		S=0,T=n+1;
 		for(int i=0;i<m;++i){
 			scanf("%d%d",a+i,b+i);
 			match[a[i]].push_back(i);
 			match[b[i]].push_back(i);
 			used[i]=0;
 		}
 		printf("Case #%d:",tt);
 		if(!predir()){
 			printf(" IMPOSSIBLE\n");
 			continue;
 		}
 		int total=0;
 		for(int i=1;i<=n;++i){
 			if(ind[i]!=oud[i]){
 				if(oud[i]>ind[i]) addedge(i,T,oud[i]-ind[i]);
 				else addedge(S,i,ind[i]-oud[i]),total+=ind[i]-oud[i];
 			}
 		}
 		while(modlabel()){
 			total-=aug(S,total);
 		}
 		if(total!=0){
 			printf(" IMPOSSIBLE\n");
 			continue;
 		}
 		for(int i=0;i<m;++i){
 			printf(" %d",(inv[i]?-1:1)*(n*n-E[2*i].U));
 		}
 		printf("\n");
 	}
 	return 0;
 }
