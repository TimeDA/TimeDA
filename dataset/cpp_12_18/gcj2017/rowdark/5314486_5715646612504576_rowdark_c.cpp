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
 
 char s[101][101];
 int id[101][101];
 int T,N,M;
 
 vector<int> V[20010];
 int belong[20010];
 int dfn[20010];
 int low[20010];
 int last[20010];
 bool vis[20010];
 bool in[20010];
 int flag=0;
 int totbelong;
 int cntnodes;
 stack<int> S;
 
 const char anss[]="|-";
 
 vector<int> cross[101][101];
 
 const int dx[]={0,1,0,-1}; // \ ^ 1 /^ 3
 const int dy[]={1,0,-1,0};
 const char res[2][20]={"POSSIBLE","IMPOSSIBLE"};
 struct node{
 	int x,y,d;
 	node(){}
 	node(int x,int y,int d):x(x),y(y),d(d){}
 }Q[50101];
 
 inline void build(int x,int y,int id){
 	int QH=-1,QT=-1;
 	if(~id&1){
 		if(y+1<M&&s[x][y+1]!='#') Q[++QT]=node(x,y+1,0);
 		if(y-1>=0&&s[x][y-1]!='#') Q[++QT]=node(x,y-1,2);
 	}
 	else{
 		if(x+1<N&&s[x+1][y]!='#') Q[++QT]=node(x+1,y,1);
 		if(x-1>=0&&s[x-1][y]!='#') Q[++QT]=node(x-1,y,3);
 	}
 	while(QH++!=QT){
 		int nx=Q[QH].x;
 		int ny=Q[QH].y;
 		int nd=Q[QH].d;
 		if(s[nx][ny]=='-'||s[nx][ny]=='|'){
 			V[id].push_back(id^1);
 			return;
 		}
 		else{
 			if(s[nx][ny]=='/'){
 				nd^=3;
 			}
 			else if(s[nx][ny]=='\\'){
 				nd^=1;
 			}
 			nx+=dx[nd],ny+=dy[nd];
 			if(0<=nx&&nx<N&&0<=ny&&ny<M&&s[nx][ny]!='#'){
 				Q[++QT]=node(nx,ny,nd);
 			}
 		}
 	}
 	for(int i=0;i<=QT;++i) if(s[Q[i].x][Q[i].y]=='.'){
 		cross[Q[i].x][Q[i].y].push_back(id);
 	}
 }
 
 void tarjan(int x){
 	dfn[x]=low[x]=++flag;
 	in[x]=vis[x]=1;
 	S.push(x);
 	REP_0(i,(int)V[x].size()){
 		int y=V[x][i];
 		if(!vis[y]){
 			tarjan(y);
 			low[x]=min(low[x],low[y]);
 		}
 		else if(in[y]){
 			low[x]=min(low[x],dfn[y]);
 		}
 	}
 	if(low[x]==dfn[x]){
 		int lasttop=-1;
 		++totbelong;
 		do{
 			lasttop=S.top();
 			S.pop();
 			belong[lasttop]=totbelong;
 			in[lasttop]=0;
 		}while(lasttop!=x);
 	}
 }
 
 void solve(){
 	REP_0(i,N) REP_0(j,M) if(s[i][j]=='.'){
 		vector<int> &C = cross[i][j];
 		sort(C.begin(),C.end());
 		C.resize(unique(C.begin(),C.end())-C.begin());
 		if(!C.size()){
 			cout<<res[1]<<endl;
 			return;
 		}
 		else if(C.size()==1){
 			V[C[0]^1].push_back(C[0]);
 		}
 		else{
 			V[C[0]^1].push_back(C[1]);
 			V[C[1]^1].push_back(C[0]);
 		}
 	}
 	memset(vis,0,sizeof(vis));
 	totbelong=0,flag=0;
 	REP_0(i,cntnodes) if(!vis[i]) tarjan(i);
 	REP_0(i,N) REP_0(j,M) if(s[i][j]=='-'||s[i][j]=='|'){
 		if(belong[id[i][j]]==belong[id[i][j]^1]){
 			cout<<res[1]<<endl;
 			return;
 		}
 		s[i][j]=belong[id[i][j]]<belong[id[i][j]^1]?'-':'|';
 	}
 	cout<<res[0]<<endl;
 	REP_0(i,N) cout<<s[i]<<endl;
 }
 
 int main(){
 	freopen("C-small-attempt0.in","r",stdin);
 	freopen("C.out","w",stdout);
 	scanf("%d",&T);
 	REP_1(tt,T){
 		cin>>N>>M;
 		REP_0(i,N){
 			scanf("%s",s[i]);
 		}
 		cntnodes=0;
 		REP_0(i,N){
 			REP_0(j,M){
 				if(s[i][j]=='|'||s[i][j]=='-'){
 					id[i][j]=cntnodes;
 					cntnodes+=2;
 					build(i,j,id[i][j]);
 					build(i,j,id[i][j]|1);
 				}
 			}
 		}
 		cout<<"Case #"<<tt<<": ";
 		solve();
 		for(int i=0;i<cntnodes;++i) V[i].clear();
 		REP_0(i,N) REP_0(j,M) cross[i][j].clear();
 	}
 	return 0;
 }
