#pragma comment(linker,"/STACK:256000000")
 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <cmath>
 #include <memory.h>
 #include <string>
 #include <set>
 #include <queue>
 #include <map>
 #include <iomanip>
 #include <sstream>
 #include <stack>
 #include <ctime>
 #include <cstdlib>
 using namespace std;
 #define forn(i,n) for(int i=0;i<(n);++i)
 #define forv(i,v) forn(i,(int)(v).size())
 #define iinf 1000000000
 #define linf 1000000000000000000LL
 #define dinf 1e200
 #define all(v) (v).begin(),(v).end()
 #define pb push_back
 #define mp make_pair
 #define lng long long
 #define eps 1e-5
 #define EQ(a,b) (fabs((a)-(b))<eps)
 #define SQ(a) ((a)*(a))
 #define PI 3.14159265359
 #define index asdindex
 #define FI first
 #define SE second
 #define prev asdprev
 #define PII pair<int,int> 
 #define PLL pair<lng,lng> 
 #define PDD pair<double,double> 
 #define X first
 #define Y second
 #define unlink asdunlink
 #define div asddiv
 #define divides asddivides
 typedef unsigned char uchar;
 typedef unsigned int uint;
 inline int mymax(int a,int b){return a<b?b:a;}
 inline int mymin(int a,int b){return a>b?b:a;}
 inline lng mymax(lng a,lng b){return a<b?b:a;}
 inline lng mymin(lng a,lng b){return a>b?b:a;}
 inline lng abs(lng a){return a<0?-a:a;}
 #ifdef __ASD__
 #define LOG(x) cerr<<x<<endl
 #else
 #define LOG(x)
 #endif
 
 int cnt1[256];
 int cnt2[256];
 char rep[256];
 bool was[256];
 vector<int> gr[256];
 
 bool dfs(int a){
 	if(was[a])
 		return false;
 	was[a]=true;
 	bool r=cnt1[a]!=cnt2[a];
 	forv(i,gr[a]){
 		r|=dfs(gr[a][i]);
 	}
 	return r;
 }
 
 int main(){
 #ifdef __ASD__
     freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 #endif
     //ios_base::sync_with_stdio(false);
 
 	rep['o']='0';
 	rep['i']='1';
 	rep['e']='3';
 	rep['a']='4';
 	rep['s']='5';
 	rep['t']='7';
 	rep['b']='8';
 	rep['g']='9';
 
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		cout<<"Case #"<<qqq+1<<": ";
 		int k;
 		cin>>k;
 		string s;
 		cin>>s;
 		memset(cnt1,0,sizeof(cnt1));
 		memset(cnt2,0,sizeof(cnt2));
 		memset(was,0,sizeof(was));
 		forn(i,256)
 			gr[i].clear();
 		set<pair<char,char> > st;
 		forn(i,(int)s.length()-1){
 			vector<char> va,vb;
 			char a=s[i];
 			char b=s[i+1];
 			va.pb(a);
 			vb.pb(b);
 			if(rep[a])
 				va.pb(rep[a]);
 			if(rep[b])
 				vb.pb(rep[b]);
 			forv(p,va){
 				forv(q,vb){
 					if(!st.count(mp(va[p],vb[q]))){
 						st.insert(mp(va[p],vb[q]));
 						++cnt1[va[p]];
 						++cnt2[vb[q]];
 						gr[va[p]].pb(vb[q]);
 						gr[vb[q]].pb(va[p]);
 					}
 				}
 			}
 		}
 		int r=0;
 		forn(i,256){
 			r+=max(cnt1[i],cnt2[i]);
 			if(!was[i]&&gr[i].size()&&!dfs(i))
 				++r;
 		}
 		cout<<r;
 		cout<<endl;
 	}
 
     return 0;
 }
