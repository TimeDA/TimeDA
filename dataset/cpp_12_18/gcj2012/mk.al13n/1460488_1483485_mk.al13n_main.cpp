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
 
 char line1[200];
 char line2[200];
 char conv[27] = "yhesocvxduiglbkrztnwjpfmaq";
 
 int main(){
 #ifdef __ASD__
 	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 #endif
 	//ios_base::sync_with_stdio(false);
 
 	int tc;
 	cin>>tc;
 	gets(line1);
 //	forn(i,26){
 //		conv[i]='?';
 //	}
 //	forn(qqq,tc){
 //		gets(line1);
 //		gets(line2);
 //		int n=strlen(line1);
 //		forn(i,n){
 //			if (line1[i]!=' ')
 //				conv[line1[i]-'a']=line2[i];
 //		}
 //	}
 //	cout<<conv;
 	forn(qqq,tc){
 		gets(line1);
 		int n=strlen(line1);
 		forn(i,n){
 			if(line1[i]!=' ')
 				line1[i] = conv[line1[i]-'a'];
 		}
 		cout<<"Case #" << qqq + 1 << ": " << line1 << '\n';
 	}
 
 	return 0;
 }
