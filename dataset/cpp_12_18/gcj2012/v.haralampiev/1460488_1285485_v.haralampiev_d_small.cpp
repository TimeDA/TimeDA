#include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <vector>
 #include <deque>
 #include <bitset>
 #include <set>
 #include <map>
 #include <utility>
 #include <string>
 #include <cstring>
 #include <queue>
 #include <algorithm>
 #include <cmath>
 using namespace std;
 #define fi first
 #define se second
 #define pb(a) push_back(a)
 #define sz(a) ((int)(a).size())
 #define all(a) a.begin() , a.end()
 #define mp make_pair
 #define EPS 1E-9
 #define x1 x111
 #define y1 y111
 typedef long long ll;
 typedef unsigned long long ull;
 typedef long double ld;
 typedef pair<int,int> pii;
 // real solution
 #define SQR(a) ((a)*(a))
 int nod(int a,int b){
   a=abs(a); b=abs(b);
   if(a<b)swap(a,b);
   while(b)a%=b , swap(a,b);
   return a; 
 }
 int W,H,D , N,M;
 int sx,sy;
 char buf[50];
 vector<int> ax , ay;
 set<int> fx,fy;
 vector< pii > prs;
 void doit(int CASE){
   scanf("%d%d%d",&H,&W,&D);
   D*=2;
   for(int i=0;i<H;++i){
    scanf("%s",&buf);
    for(int j=0;j<W;++j)
     if(buf[j]=='X')sx=2*(i-1)+1 , sy=2*(j-1)+1;
                       }
   N=2*(H-2); M=2*(W-2);
   ax.clear(); ay.clear();
   fx.clear(); fy.clear();
   ax.pb(sx); ay.pb(sy);
   fx.insert(sx); fy.insert(sy);
   for(int i=0;i<sz(ax);++i){
    int nx;
    nx=-ax[i]; if(abs(nx-sx)<=D && !fx.count(nx))ax.pb(nx), fx.insert(nx);
    nx=2*N-ax[i]; if(abs(nx-sx)<=D && !fx.count(nx))ax.pb(nx), fx.insert(nx);
                            }
   for(int i=0;i<sz(ay);++i){
    int ny;
    ny=-ay[i]; if(abs(ny-sy)<=D && !fy.count(ny))ay.pb(ny), fy.insert(ny);
    ny=2*M-ay[i]; if(abs(ny-sy)<=D && !fy.count(ny))ay.pb(ny), fy.insert(ny);
                            }
   prs.clear();
   for(int i=0;i<sz(ax);++i)
    for(int j=0;j<sz(ay);++j){
     int dst=SQR(ax[i]-sx) + SQR(ay[j]-sy);
     if(dst>0 && dst<=SQR(D)){
      int del=nod(ax[i]-sx , ay[j]-sy);
      prs.pb( mp((ax[i]-sx)/del , (ay[j]-sy)/del) );
                             }
                             }
   sort(prs.begin() , prs.end());
   prs.erase( unique(prs.begin() , prs.end()) , prs.end() );
   printf("Case #%d: %d\n" , CASE , sz(prs));
 }
 int main(){
   int Q; scanf("%d",&Q);
   for(int i=1;i<=Q;++i)doit(i);
   //system("pause");
   return 0;
 }
