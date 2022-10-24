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
 T By(T x,T y,T P){
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
 T Mul(T x,T y,T P){
 	T F1=1;x%=P;
 	while(y)
 	{
 		if(y&1)
 		{
 			F1=By(F1,x,P);
 		}
 		x=By(x,x,P);
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
 
 int a[21];
 int c;
 int d;
 
 LD E[401][401];
 LD way[401][401];
 int Op[401][401];
 LD C[501][501];
 
 char s[1001];
 int len;
 
 void dfs(int i,int j){
 	if(j<i) return;
 	if(E[i][j]!=-1) return;
 	E[i][j]=0;
 	for(int k=i;k<=j;++k)
 	{
 		if(s[k]!='X')
 		{
 			dfs(i,k-1),dfs(k+1,j);
 			LD fway=way[i][k-1]*way[k+1][j]*C[Op[i][j]-1][Op[i][k-1]]*(k-i+1);
 			way[i][j]+=fway;
 			E[i][j]+=C[Op[i][j]-1][Op[i][k-1]]*(k-i+1)*(E[i][k-1]+E[k+1][j])+fway*(len-(k-i)/2.0);
 		}
 	}
 }
 
 int t;
 LD totalway;
 LD totalE;
 int main(){
 	freopen("D-small-attempt1.in","r",stdin);
 	freopen("d.out","w",stdout);
 	C[0][0]=1;
 	REP_1(i,500)
 	{
 		C[i][0]=1;
 		REP_1(j,i)
 		{
 			C[i][j]=C[i-1][j]+C[i-1][j-1];
 		}
 	}
 	cin>>t;
 	REP_1(tt,t)
 	{
 		cin>>(s+1);
 		len=strlen(s+1);
 		REP_1(i,len) s[i+len]=s[i];
 		s[2*len+1]=0;
 		REP_1(i,2*len)
 		{
 			way[i][i-1]=1;
 			E[i][i-1]=0;
 			REP_3(j,i,2*len)
 			{
 				if(j==i)
 				{
 					Op[i][i]=s[i]=='.';
 				}
 				else Op[i][j]=Op[i][j-1]+(s[j]=='.');
 				if(!Op[i][j]) E[i][j]=0,way[i][j]=1;
 				else E[i][j]=-1,way[i][j]=0;
 			}
 		}
 		totalway=0,totalE=0;
 		REP_1(i,len)
 		{
 			if(s[i]!='X')
 			{
 				dfs(i+1,i+len-1);
 				totalway+=len*way[i+1][i+len-1];
 				totalE+=E[i+1][i+len-1]*len+way[i+1][i+len-1]*len*((len+1)/2.0);
 			}
 		}
 		if(Op[1][len]==0) totalway=1,totalE=0;
 		cout<<"Case #"<<tt<<": "<<fixed<<setprecision(10)<<totalE/totalway<<endl;
 	}
 	return 0;
 }
