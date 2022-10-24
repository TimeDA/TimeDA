#include<cstdio>
 #include<iostream>
 #include<queue>
 #include<stack>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<map>
 #include<sstream>
 #include<cmath>
 #include<cctype>
 #include<cassert>
 #include<cstring>
 #include<cstdlib>
 
 using namespace std;
 
 #define pf printf
 #define sf scanf
 #define VI vector<int>
 #define pb push_back
 #define fo(a,b) for((a)=0;(a)<(b);a++)
 
 #define debug 0
 const int inf = 1000000000;
 
 long long ncr[305][305] = {0}; void gen_ncr(int n) { int i, j; fo(i, n+1) ncr[i][0] = 1; for(i=1;i<=n;i++) for(j=1;j<=n;j++) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];}
 double dis(double x1, double y1, double x2, double y2) { return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }
 
 char mapping[30];
 
 void init() {
 	string si[3], so[3];
 	si[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
 	si[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
 	si[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
 
 	so[0] = "our language is impossible to understand";
 	so[1] = "there are twenty six factorial possibilities";
 	so[2] = "so it is okay if you want to just give up";
 
 	int i, k;	
 	for(i=0; i<26; i++)
 		mapping[i] = -1;
 	
 	for(k=0;k<3;k++)
 		for(i=0; i<si[k].size(); i++) {
 			if( si[k][i] == ' ' ) continue;
 			int c1 = si[k][i] - 'a';
 			int c2 = so[k][i] - 'a';
 
 			if( mapping[c1] == -1 ) mapping[c1] = c2;
 			else	{
 				//cout << c1 << " " << mapping[c1] << " " << c2 << endl;
 				assert( mapping[c1] == c2 );
 			}
 		}
 	mapping[ 'q' - 'a' ] = 'z' - 'a';
 	mapping[ 'z' - 'a' ] = 'q' - 'a';
 }
 
 void print(string s) {
 	int i;
 	for(i=0; i<s.size(); i++) {
 		cout << (char)(mapping [ s[i] - 'a' ] + 'a');
 	}
 }
 
 int main() {
 	init();
 	int test, cases = 1;
 	char str[1000];
 	gets(str);
 	sscanf(str, "%d", &test);
 	for( cases=1; cases<=test; cases++ ) {
 		vector<string> vs;
 		gets(str);
 		stringstream SS(str);
 		string s;
 		while( SS >> s ) {
 			vs.pb(s);
 		}
 		pf("Case #%d:", cases);
 		int i;
 		for(i=0; i<vs.size(); i++) {
 			cout << " ";
 			print(vs[i]);
 		}
 		cout << endl;
 
 	}
 	return 0;
 }
 
