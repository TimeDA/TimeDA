#include <iostream>
 #include <cstdio>
 #include <memory.h>
 #include <cstring>
 #include <cmath>
 
 #include <vector>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <algorithm>
 
 #define ABS(a) ((a)<0?-(a):(a))
 #define SIGN(a) ((a)<0?-1:((a)>0?1:0))
 #define SQR(a) ((a)*(a))
 #define MAX(a,b) (((a)>(b))?(a):(b))
 #define MIN(a,b) (((a)<(b))?(a):(b))
 
 #define REP(i, n) for(int i=0; i<(n); ++i)
 #define FOR(i, a, b) for(int i=(a); i<(b); ++i)
 
 #define in ({int x;scanf("%d", &x);x;})
 
 #define PI   (3.1415926)
 #define INF  (2147483647)
 #define INF2 (1073741823)
 #define EPS  (0.000001)
 #define y1 stupid_cmath
 
 typedef long long LL;
 
 using namespace std;
 
 char f(char c){
     if(c=='q')return 'z';
     if(c=='w')return 'f';
     if(c=='e')return 'o';
     if(c=='r')return 't';
     if(c=='t')return 'w';
     if(c=='y')return 'a';
     if(c=='u')return 'j';
     if(c=='i')return 'd';
     if(c=='o')return 'k';
     if(c=='p')return 'r';
     if(c=='a')return 'y';
     if(c=='s')return 'n';
     if(c=='d')return 's';
     if(c=='f')return 'c';
     if(c=='g')return 'v';
     if(c=='h')return 'x';
     if(c=='j')return 'u';
     if(c=='k')return 'i';
     if(c=='l')return 'g';
     if(c=='z')return 'q';
     if(c=='x')return 'm';
     if(c=='c')return 'e';
     if(c=='v')return 'p';
     if(c=='b')return 'h';
     if(c=='n')return 'b';
     if(c=='m')return 'l';
     return ' ';
 }
 char str[1000];
 void st(){
     cin.getline(str, 999);
     for(int i=0;str[i];++i) cout<<f(str[i]);
     cout<<endl;
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 	int T;
 	cin>>T;
 	cin.getline(str, 999);
 	for(int i=1;i<=T;++i){
         cout<<"Case #"<<i<<": ";
         st();
 	}
 	return 0;
 }
