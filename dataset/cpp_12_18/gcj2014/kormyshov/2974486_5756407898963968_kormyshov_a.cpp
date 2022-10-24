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
 
 void solve(){
 	int m[17];
 	memset(m, 0, sizeof(m));
 	int a;
 	cin>>a;
 	--a;
 	for(int i=0;i<4;++i)
 		for(int j=0;j<4;++j){
 			int t;
 			cin>>t;
 			if(a==i) m[t]++;
 		}
 	cin>>a;
 	--a;
 	for(int i=0;i<4;++i)
 		for(int j=0;j<4;++j){
 			int t;
 			cin>>t;
 			if(a==i) m[t]++;
 		}
 	int c=0;
 	for(int i=1;i<17;++i) c += (m[i]==2);
 	if(!c){
 		printf("Volunteer cheated!\n");
 		return ;
 	}
 	if(c>1){
 		printf("Bad magician!\n");
 		return ;
 	}
 	for(int i=1;i<17;++i)
 		if(m[i]==2) c=i;
 	printf("%d\n", c);
 }
 int main()
 {
 	//ios_base::sync_with_stdio(0);
 
 	freopen("A.in", "r", stdin);
 	freopen("A.out", "w", stdout);
 
 	int t;
 	cin>>t;
 	for(int i=1; i<=t; ++i){
 		printf("Case #%d: ", i);
 		solve();
 	}
 	return 0;
 }
 
 int cpp4cf_main()
 {
 	freopen("A.cpp","r",stdin);
 
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
 
