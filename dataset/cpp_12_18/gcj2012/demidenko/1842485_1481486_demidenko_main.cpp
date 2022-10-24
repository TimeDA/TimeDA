#include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cmath>
 #include<ctime>
 #include<memory.h>
 #include<algorithm>
 #include<string>
 #define sqr(x) ((x)*(x))
 #define sqrt(x) sqrt((x)*1.)
 #define min(a,b) ((a)<(b)?(a):(b))
 #define max(a,b) ((a)>(b)?(a):(b))
 #define abs(x) ((x)>0?(x):-(x))
 #define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
 #define fill(m,v) memset(m,v,sizeof(m))
 #define flush {cout.flush();fflush(stdout);}
 #define random(x) (((rand()<<15)+rand())%(x))
 #define pi 3.1415926535897932
 #define y1 stupid_cmath
 #define y0 stupid_cmath_make_me_cry
 #define tm stupid_ctime
 #define long long long
 #include<map>
 #include<set>
 #define foreach(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
 using namespace std;
 
 int n,m;
 int i,j,k;
 
 long D, d[11111], l[11111];
 long a[11111];
 
 string solve(){
 	cin>>n;
 	for(i=0;i<n;++i){
 		cin>>d[i]>>l[i];
 	}
 	cin>>d[n];
 	
 	long inf  = 4e16;
 	l[n] = inf;
 	
 	for(i=0;i<=n;++i) a[i] = -inf;
 	
 	if(l[0]>=d[0]) a[0] = d[0];
 	
 	for(i=0;i<n;++i) if(a[i]>=0)
 	for(j=i+1;j<=n;++j) if(d[i]+a[i]>=d[j]){
 		a[j] = max(a[j], min(l[j],d[j]-d[i]));
 	}
 	//for(i=0;i<=n;++i) cout<<a[i]<<' '; cout<<endl;
 	
 	
 	string r = (a[n]<0)?"NO":"YES";
 	
 	return r;
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 	
 	int tn,ti;
 	scanf("%d",&tn);
 	for(ti=1;ti<=tn;++ti){
 		
 		cout<<"Case #"<<ti<<": "<<solve()<<endl;
 		
 	}
 	
 	return 0;
 }
