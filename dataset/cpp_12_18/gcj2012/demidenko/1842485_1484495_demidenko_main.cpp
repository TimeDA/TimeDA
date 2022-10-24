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
 
 struct C{
 	int x,y;
 	int r;
 	int i;
 } c[111111];
 int w,h;
 
 //int d[111111][2], q;
 //int t[111111][2];
 
 int mxh(int x, int r, int n){
 	if(x<0 || x>w) return 2e9;
 	
 	int hh = r;
 	
 	int i,j,k;
 	/*for(i=0;i<q;++i){
 		if(abs(d[i][0]-d[i+1][0])+r*2>abs(x+r-d[i][0])){
 			if(d[i][1]==0) hh = max(hh, r);
 			else hh = max(hh, d[i][1]+r+r);
 		}
 	}
 	*/
 	
 	for(i=0;i<n;++i) if( abs((c[i].x-c[i].r)-(x+r))<c[i].r*2+r*2 ){ //cout<<"Drgergerg"<<endl;
 		hh = max(hh, c[i].y+c[i].r+r+r);
 	}
 	
 	//cout<<"!"<<x<<' '<<r<<' '<<hh<<endl;
 	
 	return hh;
 }
 
 void solve(){
 	cin>>n>>w>>h;
 	for(i=0;i<n;++i){
 		cin>>c[i].r;
 		c[i].i = i;
 	}
 	
 	for(i=0;i<n;++i) for(j=i;j<n;++j) if(c[i].r<c[j].r) swap(c[i],c[j]);
 	
 	
 	
 	//for(i=0;i<=q;++i) cout<<"("<<d[i][0]<<","<<d[i][1]<<") "; cout<<endl; flush;
 	for(i=0;i<n;++i){
 		int l = -1;
 		int hd = 2e9;
 		
 		//cout<<"for "<<c[i].r<<' '<<c[i].i<<' '<<endl;
 		
 		int res;
 		res = mxh(0, c[i].r, i);
 		if(res-c[i].r<=h && res<hd){
 			hd = res;
 			c[i].x = 0;
 			c[i].y = res-c[i].r;
 		}
 		
 		res = mxh(w, c[i].r, i);
 		if(res-c[i].r<=h && res<hd){
 			hd = res;
 			c[i].x = w;
 			c[i].y = res-c[i].r;
 		}
 		
 		for(k=0;k<i;++k){
 			res = mxh(c[k].x-c[k].r+c[i].r, c[i].r, i);
 			if(res-c[i].r<=h && res<hd){
 				hd = res;
 				c[i].x = c[k].x-c[k].r+c[i].r;
 				c[i].y = res-c[i].r;
 			}
 		}
 		for(k=0;k<i;++k){
 			res = mxh(c[k].x-c[k].r-c[i].r, c[i].r, i);
 			if(res-c[i].r<=h && res<hd){
 				hd = res;
 				c[i].x = c[k].x-c[k].r-c[i].r;
 				c[i].y = res-c[i].r;
 			}
 		}
 		
 		for(k=0;k<i;++k){
 			res = mxh(c[k].x+c[k].r-c[i].r, c[i].r, i);
 			if(res-c[i].r<=h && res<hd){
 				hd = res;
 				c[i].x = c[k].x+c[k].r-c[i].r;
 				c[i].y = res-c[i].r;
 			}
 		}
 		for(k=0;k<i;++k){
 			res = mxh(c[k].x+c[k].r+c[i].r, c[i].r, i);
 			if(res-c[i].r<=h && res<hd){
 				hd = res;
 				c[i].x = c[k].x+c[k].r+c[i].r;
 				c[i].y = res-c[i].r;
 			}
 		}
 		
 		
 		
 		
 		//cout<<"- "<<hd<<' '<<c[i].x<<' '<<c[i].y<<endl;
 		if(hd==2e9){
 			cout<<"wtf!!"<<endl; exit(0);
 		}
 		
 	}//cout<<"ok"<<endl; flush;
 	
 	
 	
 	
 	
 	for(i=0;i<n;++i) if(c[i].x<0 || c[i].x>w || c[i].y<0 || c[i].y>h){
 			cout<<"wtf2!!"<<endl;// exit(0);
 		}
 		
 		for(i=0;i<n;++i) for(j=i+1;j<n;++j)
 		if(sqr(c[i].x-c[j].x*1.)+sqr(c[i].y-c[j].y*1.)<sqr(c[i].r+c[j].r*1.)){
 			cout<<"wtf3!!"<<i<<' '<<j<<endl;// exit(0);
 		}
 	
 	for(i=0;i<n;++i) for(j=i;j<n;++j) if(c[i].i>c[j].i) swap(c[i],c[j]);
 	
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 	
 	int tn,ti;
 	cin>>tn;
 	for(ti=1;ti<=tn;++ti){
 		
 		solve();//cout<<"ok "<<ti<<endl; flush;
 		cout<<"Case #"<<ti<<": ";
 		for(i=0;i<n;++i) cout<<c[i].x<<' '<<c[i].y<<' ';
 		cout<<endl;
 		
 	}
 	
 	return 0;
 }
