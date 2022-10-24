#include <algorithm>
 #include <bitset>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <ctime>
 #include <deque>
 #include <functional>
 #include <iomanip>
 #include <iostream>
 #include <iterator>
 #include <list>
 #include <map>
 #include <numeric>
 #include <queue>
 #include <set>
 #include <sstream>
 #include <stack>
 #include <string>
 #include <utility>
 #include <vector>
 
 using namespace std;
 
 #define PB push_back
 #define SZ(X) ((int)(X.size()))
 #define ALL(X) (X).begin(), (X).end()
 #define FE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 #define MOD 1000000007ll
 
 const double PI=acos(-1.0);
 const double EPS=1e-10;
 
 typedef long long ll;
 typedef vector<int> vint;
 typedef vector<vint> vvint;
 typedef pair<double,int> pii;
 typedef vector<pii> vpii;
 typedef vector<string> vstr;
 int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
 #define MAXN 1000
 
 pii r[1010];
 double sol[2020];
 
 void solve(){
   int N=in();
   int W=in();
   int L=in();
   int i;
   for(i=0;i<N;i++) r[i]=pii(in(),i);
   
   sort(r,r+N);
   
   double top=0.0;
   double next=0.0;
   
   double posx=0.0;
   
   sol[r[0].second]=top;
   sol[r[0].second+1]=posx;
   
   next=r[0].first;
   posx=r[0].first;
   
   for(i=1;i<N;i++){
     
     if(posx+r[i].first>W){
       top=next;
       posx=-r[i].first;
     }
     
     sol[2*r[i].second]=posx+r[i].first;
     sol[2*r[i].second+1]=top;
     
     next=top+r[i].first;
     posx=posx+2*r[i].first;
     
     
   }
   
   for(i=0;i<2*N;i++) printf(" %lf",sol[i]);
   puts("");
 
 }
 
 int main(){
 	//freopen("B.in","r",stdin);
 	freopen("B-small-attempt0.in","r",stdin); 
 	//freopen("B-small-attempt1.in","r",stdin); 
 	//freopen("B-small-attempt2.in","r",stdin); 
 	//freopen("B-large.in","r",stdin);
   freopen("Bout","w",stdout);
   
   int C=in();
   for(int caso=1;caso<=C;caso++){
     printf("Case #%d:",caso);
     solve();
   }
   
   return 0;
 }
 
 
