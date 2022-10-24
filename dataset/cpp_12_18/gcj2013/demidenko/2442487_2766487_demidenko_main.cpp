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
 
 int n,m;
 int i,j,k;
 string a[1111];
 
 void g(vector<int> p, int d){
 	if(p.size()==1) return;
 	vector<int> w1, w2;
 	for(int i=0;i<p.size(); i+=2){
 		w1.push_back(min(p[i], p[i+1]));
 		w2.push_back(max(p[i], p[i+1]));
 		a[max(p[i], p[i+1])]+="1";
 		a[min(p[i], p[i+1])]+="0";
 	}
 	g(w1,d-1);
 	g(w2,d-1);
 }
 
 bool cmp(int i, int j){ return a[i]<a[j]; }
 
 int d1[1111], d2[1111];
 
 int main(){
 	freopen("input.txt","r",stdin);  freopen("output.txt","w",stdout);
 	
 	/*int nn;
 	cin>>nn;
 	n=1<<nn;
 	
 	vector<int> p(n);
 	for(i=0;i<n;++i) p[i]=i;
 	for(i=0;i<n;++i) d2[i]=1e9;
 	do{
 		
 		for(i=0;i<n;++i) a[i]="";
 		g(p,nn-1);
 		
 		vector<int> v = p;
 		sort(v.begin(), v.end(), cmp);
 		
 		///for(i=0;i<n;++i) cout<<p[i]<<' '; cout<<endl;
 		//for(i=0;i<n;++i) cout<<v[i]<<' '; cout<<endl; 
 		//for(i=0;i<n;++i) cout<<a[i]<<' '; cout<<endl; 
 		//cout<<endl;
 	
 		for(i=0;i<n;++i) d1[v[i]] = max(d1[v[i]], i);
 		for(i=0;i<n;++i) d2[v[i]] = min(d2[v[i]], i);
 		
 	}while(next_permutation(p.begin(),p.end()));
 	
 	for(i=0;i<n;++i) cout<<d1[i]<<' '; cout<<endl;
 	for(i=0;i<n;++i) cout<<d2[i]<<' '; cout<<endl; cout<<endl;
 	*/
 	
 	
 	int tn,ti;
 	cin>>tn;
 	for(ti=1;ti<=tn;++ti){
 		
 		cin>>n>>k;
 		
 		m = 1<<n;
 		d1[0] = 0;
 		d1[m-1] = m-1;
 		
 		int x = m-2, y = m/2, z=1;
 		j=m-1;
 		for(;y>1;){
 			for(i=j-y; i<j; ++i) d1[i]=x;
 			j-=y;
 			++z;
 			x-=z;
 			y/=2;
 		}
 		
 		
 		d2[0] = 0;
 		d2[m-1] = m-1;
 		x = 1; y = m/2; z=1;
 		j=0;
 		for(;y>1;){
 			for(i=j+1; i<=j+y; ++i) d2[i]=x;
 			j+=y;
 			++z;
 			x+=z;
 			y/=2;
 		}
 		
 		//for(i=0;i<m;++i) cout<<d1[i]<<' '; cout<<endl;
 		//for(i=0;i<m;++i) cout<<d2[i]<<' '; cout<<endl;
 		
 		
 		
 		for(i=0;i<m && d1[i]<k;++i);
 		for(j=0;j<m && d2[j]<k;++j);
 		cout<<"Case #"<<ti<<": "<<i-1<<' '<<j-1<<endl;
 	}
 	
 	
 
 	
 	
 	return 0;
 }
