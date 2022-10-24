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
 
 int S,T,N;
 const long double INF=1e10;
 pair<LD,LD> valid[1001][1001];
 int v3[1001][3];
 int x3[1001][3];
 const pair<LD,LD> INVALID=make_pair(2*INF,2*INF);
 vector<pair<pair<LD,LD>,int> > VV[1001];
 int st[1001];
 long double Sqrt(const long double &x){
 	return x<0?0:sqrt(x);
 }
 long double Dist(long double a,long double b,long double c){
 	return Sqrt(Sqr(a)+Sqr(b)+Sqr(c));
 }
 
 inline bool equals(long double x,long double y,const long double eps=1e-8){
 	return x+eps>=y&&y+eps>=x;
 }
 
 inline bool check(long double MaxD){
 	REP_0(i,N) VV[i].clear(),st[i]=0;
 	REP_0(i,N) REP_0(j,N){
 		if(i==j){
 			valid[i][j]=INVALID;
 			continue;
 		}
 		int dv[3]={v3[j][0]-v3[i][0],v3[j][1]-v3[i][1],v3[j][2]-v3[i][2]};
 		int dx[3]={x3[j][0]-x3[i][0],x3[j][1]-x3[i][1],x3[j][2]-x3[i][2]};
 		if(!dv[0]&&!dv[1]&&!dv[2]){
 			if(Dist(dx[0],dx[1],dx[2])>MaxD){
 				valid[i][j]=INVALID;
 			}
 			else{
 				valid[i][j]=make_pair(0,INF);
 				VV[i].push_back(make_pair(valid[i][j],j));
 			}
 		}
 		else{
 			long double f=Dist(dv[0],dv[1],dv[2]);
 			long double udv[3]={dv[0]/f,dv[1]/f,dv[2]/f};
 			long double g=(long double)(udv[0]*dx[0]+udv[1]*dx[1]+udv[2]*dx[2]);
 			long double rdx[3]={dx[0]-g*udv[0],dx[1]-g*udv[1],dx[2]-g*udv[2]};
 			long double h=Dist(rdx[0],rdx[1],rdx[2]);
 			if(h>MaxD){
 				valid[i][j]=INVALID;
 			}
 			else{
 				long double ff=Sqrt(Sqr(MaxD)-Sqr(h));
 				long double l=-ff-g,r=ff-g;
 				if(r<0){
 					valid[i][j]=INVALID;
 				}
 				else{
 					l=max(l,(long double)0);
 					valid[i][j]=make_pair(l/f,r/f);
 					VV[i].push_back(make_pair(valid[i][j],j));
 				}
 			}
 		}
 	}
 	priority_queue<pair<pair<LD,LD>,int>, vector<pair<pair<LD,LD>,int> >, greater<pair<pair<LD,LD>,int> > > PQ;
 	PQ.push(make_pair(make_pair(0,S),0));
 	while(PQ.size()){
 		pair<LD,LD> f=PQ.top().first;
 		int v=PQ.top().second;
 		if(v==1) return true;
 		PQ.pop();
 		while(st[v]<int(VV[v].size())){
 			if(VV[v][st[v]].first.first>f.second) break;
 			if(VV[v][st[v]].first.second<f.first){
 				++st[v];
 				continue;
 			}
 			PQ.push(make_pair(make_pair(max(VV[v][st[v]].first.first,f.first),VV[v][st[v]].first.second+S),VV[v][st[v]].second));
 			f.second=max(f.second,VV[v][st[v]].first.second);
 			++st[v];
 		}
 	}
 	return false;
 }
 
 int main(){
 	freopen("C-small-attempt1.in","r",stdin);
 	freopen("c.out","w",stdout);
 	scanf("%d",&T);
 	REP_1(tt,T){
 		scanf("%d%d",&N,&S);
 		REP_0(i,N) scanf("%d%d%d%d%d%d",x3[i],x3[i]+1,x3[i]+2,v3[i],v3[i]+1,v3[i]+2);
 		long double L=0,R=Sqrt(Sqr(x3[0][0]-x3[1][0])+Sqr(x3[0][1]-x3[1][1])+Sqr(x3[0][2]-x3[1][2]));
 		for(int i=1;i<=60;++i){
 			cerr<<tt<<" "<<i<<endl;
 			long double Mid=(L+R)/2;
 			if(check(Mid)) R=Mid;
 			else L=Mid;
 		}
 		cout<<"Case #"<<tt<<": "<<fixed<<setprecision(10)<<(L+R)/2<<endl;
 	}
 	return 0;
 }
