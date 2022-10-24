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
 typedef pair<int,int> pii;
 typedef vector<pii> vpii;
 typedef vector<string> vstr;
 int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
 #define MAXN 100000
 
 vector<pii> vines;
 int last[1000];
 
 void solve(){
   vines.clear();
   int N=in();
   int i;
   int d,l,j;
   for(i=0;i<N;i++){
     d=in();
     l=in();
     vines.push_back(pii(d,l));
   }
   int D=in();
   
   memset(last,0,sizeof last);
   
   last[0]=vines[0].first*2;
   
   for(i=1;i<N;i++){
    last[i]=vines[i].first;
    
    for(j=0;j<i;j++){
      
      if(last[j]>=vines[i].first)
       last[i]=max(last[i], vines[i].first+ min(vines[i].second,vines[i].first-vines[j].first));
    }
   }
   
   int vale=0;
   //for(i=0;i<N;i++) cerr << last[i] << endl;
   for(i=0;i<N;i++) vale=max(vale,last[i]);
   
   if(vale>=D) puts("YES");
   else puts("NO");
 
 }
 
 int main(){
 	//freopen("A.in","r",stdin);
 	//freopen("A-small-attempt0.in","r",stdin); 
 	//freopen("A-small-attempt1.in","r",stdin); 
 	freopen("A-small-attempt2.in","r",stdin); 
 	//freopen("A-large.in","r",stdin);
   freopen("Aout","w",stdout);
   
   int C=in();
   for(int caso=1;caso<=C;caso++){
     printf("Case #%d: ",caso);
     solve();
   }
   
   return 0;
 }
 
 
