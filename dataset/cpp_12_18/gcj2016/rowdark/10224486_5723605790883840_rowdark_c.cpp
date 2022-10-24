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
 
 char s[111][111];
 
 int T,N,M;
 bool flag;
 
 vector<int> V;
 
 int P[211];
 
 const int dx[]={0,1,0,-1};
 const int dy[]={1,0,-1,0};
 
 int Q[211],QH,QT;
 void getXY(int &x,int &y,int &d,int id){
 	if(id<=M) x=1,y=id,d=1;
 	else if(id<=N+M) x=id-M,y=M,d=2;
 	else if(id<=N+M+M) x=N,y=M+1-(id-N-M),d=3;
 	else x=N+1-(id-N-M-M),y=1,d=0;
 }
 
 bool tryMark(int x,int y,char c){
 	if(!s[x][y]||s[x][y]==c) return s[x][y]=c,true;
 	else return false;
 }
 bool Better(int a,int b,int c){
 	while(1){
 		if(a==b) return true;
 		if(a==c) return false;
 		a=(a+1)&3;
 	}
 }
 bool Connect(int A,int B){
 	int sx,sy,sd,tx,ty,td;
 	getXY(sx,sy,sd,A);
 	getXY(tx,ty,td,B);
 	if(A+1==B||A==N+M+N+M&&B==1){
 		if(sx==tx&&sy==ty){
 			if(A==M||A==N+M+M){
 				if(!tryMark(sx,sy,'\\')){
 					return false;
 				}
 			}
 			else{
 				if(!tryMark(sx,sy,'/')){
 					return false;
 				}
 			}
 			return true;
 		}
 		else{
 			if(A<=M||(A>N+M&&A<=N+M+M)){
 				if(!tryMark(sx,sy,'\\')||!tryMark(tx,ty,'/')){
 					return false;
 				}
 			}
 			else{
 				if(!tryMark(sx,sy,'/')||!tryMark(tx,ty,'\\')){
 					return false;
 				}
 			}
 			return true;
 		}
 	}
 	while(sx!=tx||sy!=ty){
 		if(sx<1||sx>N||sy<1||sy>M) return false;
 		if(!s[sx][sy]){
 			int ad=sd^3;
 			int ax=sx+dx[ad],ay=sy+dy[ad];
 			int bd=sd^1;
 			int bx=sx+dx[bd],by=sy+dy[bd];
 			if(Better(sd^2,ad,bd)){
 				s[sx][sy]='/';
 				sx=ax,sy=ay,sd=ad;
 			}
 			else{
 				s[sx][sy]='\\';
 				sx=bx,sy=by,sd=bd;
 			}
 		}
 		else{
 			sd^=(s[sx][sy]=='\\'?1:3);
 			sx+=dx[sd],sy+=dy[sd];
 		}
 	}
 	if(s[sx][sy]){
 		sd^=(s[sx][sy]=='\\'?1:3);
 		return (sd^2)==td;
 	}
 	else{
 		if((sd^td^2)==1){
 			s[sx][sy]='\\';
 		}
 		else s[sx][sy]='/';
 		return true;
 	}
 }
 bool build(){
 	QH=0,QT=-1;
 	for(int i=1;i<=2*(N+M);++i){
 		if(QH<=QT&&P[i]==Q[QT]&&i-Q[QT]<=N+M){
 			if(!Connect(Q[QT],i)) return false;
 			--QT;
 		}
 		else{
 			Q[++QT]=i;
 		}
 	}
 	while(QH<QT){
 		if(P[Q[QH]]==Q[QT]){
 			if(!Connect(Q[QT],Q[QH])) return false;
 			--QT,++QH;
 		}
 		else return false;
 	}
 	for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) if(!s[i][j]) s[i][j]='/';
 	return true;
 }
 
 int main(){
 	freopen("C-small-attempt0.in","r",stdin);
 	freopen("C.out","w",stdout);
 	scanf("%d",&T);
 	REP_1(tt,T){
 		scanf("%d%d",&N,&M);
 		memset(s,0,sizeof(s));
 		flag=true;
 		for(int i=1;i<=N+M;++i){
 			int x,y;
 			scanf("%d%d",&x,&y);
 			P[P[y]=x]=y;
 		}
 		printf("Case #%d:\n",tt);
 		if(!build()) printf("IMPOSSIBLE\n");
 		else{
 			REP_1(i,N) printf("%s\n",s[i]+1);
 		}
 	}
 	return 0;
 }
