#include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <cmath>
 #include <memory.h>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
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
 #define eps 1e-11
 #define EQ(a,b) (fabs((a)-(b))<eps)
 #define SQ(a) ((a)*(a))
 #define PI 3.14159265359
 #define index asdindex
 #define FI first
 #define SE second
 #define prev asdprev
 #define ends asdends
 #define PII pair<int,int> 
 #define X first
 #define Y second
 #define mset(a,b) memset(a,b,sizeof(a))
 typedef unsigned short ushort;
 
 
 
 int main(){
 #ifdef __ASD__
 	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 #endif
 	//ios_base::sync_with_stdio(false);
 
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		int n,s,p;
 		cin>>n>>s>>p;
 		set<int> unsurp,surp;
 		for(int a=p;a<=10;++a){
 			for(int b=max(0,a-2);b<=a;++b){
 				for(int c=max(0,a-2);c<=b;++c){
 					if(c==a-2)
 						surp.insert(a+b+c);
 					else
 						unsurp.insert(a+b+c);
 				}
 			}
 		}
 		int r=0;
 		forn(i,n){
 			int a;
 			cin>>a;
 			if(unsurp.count(a))
 				++r;
 			else if(surp.count(a)&&s){
 				++r;
 				--s;
 			}
 		}
 		cout<<"Case #"<<qqq+1<<": "<<r<<'\n';
 	}
 
 	return 0;
 }
