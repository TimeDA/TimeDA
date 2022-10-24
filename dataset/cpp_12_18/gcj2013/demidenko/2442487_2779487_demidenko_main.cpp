#include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<memory.h>
 #include<cmath>
 #include<ctime>
 #include<algorithm>
 #include<string>
 #include<vector>
 #include<map>
 #include<set>
 #define abs(x) ((x)<0?-(x):(x))
 #define _max(x,y) ((x)<(y)?(y):(x))
 #define _min(x,y) ((x)<(y)?(x):(y))
 #define sqr(x) ((x)*(x))
 #define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
 #define forc(it,c) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
 #define fill(m,v) memset(m,v,sizeof(m))
 #define y1 stupid_cmath
 #define y0 stupid_cmath_make_me_cry
 #define tm stupid_ctime
 inline int random(int x){ if(RAND_MAX==32767) return (rand()<<15^rand())%x; else return rand()%x; }
 typedef long long ll;
 using namespace std;
 
 const int N = 2222 ;
 int x[N];
 int a[N];
 int b[N];
 int n;
 int a2[N], b2[N];
 bool u[N];
 bool f;
 void g(int i){
 	if(i==n){
 		for(i=n-1;i>=0;--i){
 			b2[i]=0;
 			for(int j=n-1;j>i;--j) if(x[j]<x[i]) b2[i]=max(b2[i], b2[j]);
 			++b2[i];
 			if(b2[i]!=b[i]) return;
 		}
 		f=1;
 		return ;
 	}
 	
 	for(int k=0;k<n;++k) if(!u[k]){
 		x[i]=k;
 		u[k]=1;
 		int d = 0;
 		for(int j=0;j<i;++j) if(x[j]<x[i]) d=max(d,a[j]);
 		++d;
 		if(d==a[i]){
 			g(i+1);
 			if(f) return;
 		}
 		x[i]=0;
 		u[k]=0;
 	}
 }
 
 int main(){
 	freopen("input.txt","r",stdin);  freopen("output.txt","w",stdout);
 	
 	int tn,ti,i;
 	cin>>tn;
 	for(ti=1;ti<=tn;++ti){
 		
 		cin>>n;
 		getar(a,n);
 		getar(b,n);
 		
 		fill(u,0);
 		f=0;
 		g(0); cerr<<ti<<' '<<f<<endl;
 		if(f){
 			cout<<"Case #"<<ti<<": ";
 			for(i=0;i<n;++i) cout<<x[i]+1<<' '; cout<<endl;
 		}
 	}
 	
 	return 0;
 }
