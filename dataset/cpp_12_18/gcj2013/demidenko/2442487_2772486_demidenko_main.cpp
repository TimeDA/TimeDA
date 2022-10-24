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
 
 struct st{
 	int l,r,c;
 	st(int L=0,int R=0,int C=0){
 		l=L; r=R; c=C;
 	}
 };
 
 ll mod = 1000002013LL;
 ll i2 = (mod+1)/2;
 const int K=1e6+6 ;
 ll pr[K];
 
 ll calc(vector<st>&v, int n){
 	 ll res=0;
 	 forc(it, v){
 		if(it->l!=it->r){
 			ll d = it->r-it->l;
 			ll s = (n*d%mod - (d-1)*i2%mod*d%mod + mod)%mod*(it->c)%mod;
 			res=(res+s)%mod;
 		}
 	 }
 	 return res;
 }
 
 
 int main(){
 	freopen("input.txt","r",stdin);  freopen("output.txt","w",stdout);
 	
 	
 	int tn,ti;
 	cin>>tn;
 	for(ti=1;ti<=tn;++ti){ cerr<<ti<<"..."<<endl;
 		
 		cin>>n>>m;
 		
 		vector<st> v(m);
 		for(i=0;i<m;++i){
 			st x;
 			cin>>x.l>>x.r>>x.c;
 			v[i]=x;
 		}
 		
 		ll ans1=calc(v,n);
 		
 		for(;;){
 			bool f=0;
 			for(i=0;i<v.size();++i){
 			for(j=0;j<v.size();++j) if(v[i].l<v[j].l && v[j].l<=v[i].r && v[i].r<v[j].r){
 				//if(ti==4) cout<<"swap"<<' '<< v[i].l<<' '<<v[i].r<<' '<<v[i].c<<"  "<<v[j].l<<' '<<v[j].r<<' '<<v[j].c<<"  "<<v.size()<<endl;
 				st x = v[i].c>v[j].c ? 
 					st(v[i].l, v[i].r, v[i].c-v[j].c) : 
 					st(v[j].l, v[j].r, v[j].c-v[i].c);
 					
 				if(x.c!=0) v.push_back(x);
 				swap(v[i].r, v[j].r);
 				v[i].c = v[j].c = min(v[i].c, v[j].c);
 				f = 1;
 			}
 			}
 			if(!f) break;
 		}
 		
 		ll ans2 = calc(v,n);
 		
 		cout<<"Case #"<<ti<<": "<<((ans1-ans2)%mod+mod)%mod<<endl;
 	}
 	
 	return 0;
 }
