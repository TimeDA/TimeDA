#include <iostream>
 #include <fstream>
 #include <sstream>
 #include <cstdio>
 #include <cstring>
 #include <memory.h>
 #include <cmath>
 #include <iomanip>
 #include <pthread.h>
 #include <semaphore.h>
 
 #include <vector>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <set>
 #include <map>
 #include <list>
 #include <bitset>
 #include <algorithm>
 
 #define ABS(a) ((a)<0?(-(a)):(a))
 #define SIGN(a) (((a)>0)-((a)<0))
 #define SQR(a) ((a)*(a))
 #define MAX(a,b) ((a)>(b)?(a):(b))
 #define MIN(a,b) ((a)<(b)?(a):(b))
 
 #define PI (3.1415926535897932384626433832795)
 #define INF (2147483647)
 #define LLINF (9223372036854775807LL)
 #define INF2 (1073741823)
 #define EPS (0.00000001)
 
 #define MOD (1000000007)
 
 #define y1 stupid_cmath
 #define y0 stupid_cmath_too
 
 using namespace std;
 
 typedef long long LL;
 template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> &t) {return O<<"("<<t.first<<","<<t.second<<")";}
 template<typename T> ostream& operator<<(ostream &O,vector<T> &t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }
 void dout(){cout<<endl;} template<typename Head, typename... Tail> void dout(Head H, Tail... T){cout<<H<<" "; dout(T...);}
 
 char mm[19][19];
 bool check(int n, int m, int c){
 	int i, j;
 	memset(mm, 0, sizeof(mm));
 	if(c+1==n*m){
 		for(int i=0;i<n;++i) for(int j=0;j<m;++j) mm[i][j]='*';
 		mm[0][0]='c';
 		return true;
 	}
 	if(n==4 && m==4 && c==3){
 		for(int i=0;i<n;++i) for(int j=0;j<m;++j) mm[i][j]='.';
 		mm[0][0]=mm[1][0]=mm[0][1]='*';
 		mm[3][3]='c';
 		return true;
 	}
 	if(n==5 && m==5 && c==4){
 		for(int i=0;i<n;++i) for(int j=0;j<m;++j) mm[i][j]='.';
 		mm[0][0]=mm[1][0]=mm[2][0]=mm[0][1]='*';
 		mm[4][4]='c';
 		return true;
 	}
 	if(m==1){
 		for(i=0;i<c;++i) mm[i][0]='*';
 		for(;i<n;++i) mm[i][0]='.';
 		if(c<n) mm[n-1][0]='c';
 	}else
 	if(m==2){
 		if(c&1) return false;
 		c>>=1;
 		if(c==n-1) return false;
 		for(i=0;i<c;++i) mm[i][0]=mm[i][1]='*';
 		for(;i<n;++i) mm[i][0]=mm[i][1]='.';
 		if(c<n) mm[n-1][0]='c';
 	}else
 	{
 		int a=n*m-c, b=0;
 		for(i=2;i<=m;i++){
 			int t = a/i + (a%i > 0);
 			if(t>n) continue ;
 			if(a%i==1) continue ;
 			if(t==0 || (t==1 && a>1) || (a/i==1 && a%i>0)) continue ;
 			for(int ii=0;ii<n;++ii) for(int jj=0;jj<m;++jj) mm[ii][jj]='*';
 			for(int ii=0;ii<n;++ii) for(int jj=0;jj<i;++jj)
 				if(b<a) mm[ii][jj]='.', b++;
 			break;
 		}
 		if(i>m) return false;
 		if(a) mm[0][0]='c';
 	}
 	return true;
 }
 void solve(){
 	int n, m, c;
 	cin>>n>>m>>c;
 	if(n*m < c){
 		printf("Impossible\n");
 		return ;
 	}
 	int i, j;
 	if(check(n, m, c))
 		for(i=0;i<n;++i){
 			for(j=0;j<m;++j) printf("%c", mm[i][j]);
 			printf("\n");
 		}
 	else
 		if(check(m, n, c))
 			for(i=0;i<n;++i){
 				for(j=0;j<m;++j)
 					printf("%c", mm[j][i]);
 				printf("\n");
 			}
 		else printf("Impossible\n");
 }
 int main()
 {
 	//ios_base::sync_with_stdio(0);
 
 	freopen("C.in", "r", stdin);
 	freopen("C.out", "w", stdout);
 
 	int t;
 	cin>>t;
 	for(int i=1;i<=t;++i){
 		printf("Case #%d:\n", i);
 		solve();
 	}
 	return 0;
 }
 
 int cpp4cf_main()
 {
 	freopen("C.cpp","r",stdin);
 
 	char s[99];
 	bool f;
 
 	while(true) {
 		cin>>s;
 		if(cin.eof()) break;
 		if(strstr(s,"/*")) {
 			cin>>s;
 			if(strstr(s,"Test")) {
 				cin>>s;
 				if(strstr(s,"on")) {
 					cout<<"Output: ";
 					cpp4cf_main();
 					cout<<"\nAnswer: ";
 					f = false;
 					while(true) {
 						cin>>s;
 						if(strstr(s,"*/")) break;
 						if(strstr(s,"//")) {
 							if(f) cout<<endl;
 							else f = true;
 						}else cout<<s<<" ";
 					}
 					cout<<"\n\n";
 				}
 			}
 		}
 	}
 
 	return 0;
 }
 
