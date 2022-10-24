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
 	int T;EDGE *Nxt;
 };
 
 vector<int> V1[1001],V2[1001];
 vector<int> L1,L2;
 int stamp[1001];
 int flag;
 bool ban[1001];
 int match[1001];
 int graph[101][101];
 int ans[101][101];
 int N,M,T;
 inline bool inrange(int x,int y){
 	return 0<=x&&x<N&&0<=y&&y<N;
 }
 inline int ch(int c){
 	if(c=='.') return 0;
 	else if(c=='+') return 1;
 	else if(c=='x') return 2;
 	else if(c=='o') return 3;
 	while(1);
 	return -1;
 }
 const char ss[10]=".+xo";
 bool dfs(int x,const vector<int> V[]){
 	for(int i=0;i<int(V[x].size());++i){
 		int y=V[x][i];
 		if(!ban[y]&&stamp[y]!=flag){
 			stamp[y]=flag;
 			if(match[y]==-1||dfs(match[y],V)){
 				return match[y]=x,match[x]=y,1;
 			}
 		}
 	}
 	return 0;
 }
 inline vector<pair<int,int> > solve(const vector<int> V[],const vector<int> &L){
 	for(int i=0;i<(int)L.size();++i){
 		if(!ban[L[i]]){
 			++flag;
 			dfs(L[i],V);
 		}
 	}
 	vector<pair<int,int> > ret;
 	for(int i=0;i<(int)L.size();++i){
 		if(!ban[L[i]]&&match[L[i]]!=-1){
 			ret.push_back(make_pair(L[i],match[L[i]]));
 		}
 	}
 	return ret;
 }
 inline int solve_plus(){ // &1 +/o 4~7 
 	memset(ban,0,sizeof(ban));
 	memset(match,-1,sizeof(match));
 	int ret=0;
 	for(int i=0;i<5*N;++i) V1[i].clear();
 	for(int i=0;i<N;++i){
 		for(int j=0;j<N;++j){
 			V1[i+j].push_back(i-j+6*N);
 		}
 	}
 	L1.clear();
 	for(int i=0;i<2*N-1;++i){
 		L1.push_back(i);
 	}
 	for(int i=0;i<N;++i) for(int j=0;j<N;++j){
 		if(graph[i][j]&&graph[i][j]!=2){// !=x
 			ban[i+j]=1;
 			ban[i-j+6*N]=1;
 			++ret;
 		}
 	}
 	vector<pair<int,int> > res=solve(V1,L1);
 	ret+=res.size();
 	for(int i=0;i<(int)res.size();++i){
 		ans[(res[i].X+res[i].Y-6*N)/2][(res[i].X-res[i].Y+6*N)/2]|=1;
 	}
 	return ret;
 }
 inline int solve_mul(){ // &2 x/o 0~3 
 	memset(ban,0,sizeof(ban));
 	memset(match,-1,sizeof(match));
 	int ret=0;
 	for(int i=0;i<N;++i){
 		V2[i].clear();
 		for(int j=0;j<N;++j){
 			V2[i].push_back(j+N);
 		}
 	}
 	L2.clear();
 	for(int i=0;i<N;++i){
 		L2.push_back(i);
 	}
 	for(int i=0;i<N;++i) for(int j=0;j<N;++j){
 		if(graph[i][j]&&graph[i][j]!=1){// !=+
 			ban[i]=1;
 			ban[j+N]=1;
 			++ret;
 		}
 	}
 	vector<pair<int,int> > res=solve(V2,L2);
 	ret+=res.size();
 	for(int i=0;i<(int)res.size();++i){
 		ans[res[i].X][res[i].Y-N]|=2;
 	}
 	return ret;
 }
 int main(){
 	freopen("D-small-attempt0.in","r",stdin);
 	freopen("d.out","w",stdout);
 	cin>>T;
 	REP_1(tt,T){
 		cin>>N>>M;
 		memset(graph,0,sizeof(graph));
 		memset(ans,0,sizeof(ans));
 		REP_0(i,M){
 			string S;
 			int x,y;
 			cin>>S>>x>>y;
 			ans[x-1][y-1]=graph[x-1][y-1]=ch(S[0]);
 		}
 		int totsc=0;
 		totsc+=solve_plus();
 		totsc+=solve_mul();
 		int f=0;
 		for(int i=0;i<N;++i){
 			for(int j=0;j<N;++j){
 				f+=ans[i][j]!=graph[i][j];
 			}
 		}
 		cout<<"Case #"<<tt<<": "<<totsc<<" "<<f<<endl;
 		for(int i=0;i<N;++i){
 			for(int j=0;j<N;++j){
 				if(ans[i][j]!=graph[i][j]){
 					cout<<ss[ans[i][j]]<<" "<<(i+1)<<" "<<(j+1)<<endl;
 				}
 			}
 		}
 	}
 	return 0;
 }
