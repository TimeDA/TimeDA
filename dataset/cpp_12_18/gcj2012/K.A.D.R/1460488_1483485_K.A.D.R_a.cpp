#define _CRT_SECURE_NO_DEPRECATE
 #include <algorithm>
 #include <string>
 #include <set>
 #include <map>
 #include <vector>
 #include <queue>
 #include <iostream>
 #include <iterator>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <sstream>
 #include <fstream>
 #include <ctime>
 #include <cstring>
 #pragma comment(linker, "/STACK:66777216")
 using namespace std;
 #define pb push_back
 #define ppb pop_back
 #define pi 3.1415926535897932384626433832795028841971
 #define mp make_pair
 #define x first
 #define y second
 #define pii pair<int,int>
 #define pdd pair<double,double>
 #define INF 1000000000
 #define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
 #define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
 #define all(c) (c).begin(), (c).end()
 #define SORT(c) sort(all(c))
 #define rep(i,n) FOR(i,1,(n))
 #define rept(i,n) FOR(i,0,(n)-1)
 #define L(s) (int)((s).size())
 #define C(a) memset((a),0,sizeof(a))
 #define VI vector <int>
 #define ll long long
 
 int a,b,c,d,i,j,n,m,k,kolt;
 /*int p[26];
 vector<string> in, out;*/
 char str[1001];
 const int mapping[] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
 int main() {
 	/*memset(p, -1, sizeof(p));
 	p['y' - 'a'] = 'a' - 'a';
 	p['e' - 'a'] = 'o' - 'a';
 	p['q' - 'a'] = 'z' - 'a';
 	
 	rept(i, 3) {
 		gets(str);
 		in.pb(str);
 	}
 	rept(i, 3) {
 		gets(str);
 		out.pb(str);
 	}
 
 	rept(h, 3) {
 		string s1 = in[h], s2 = out[h];
 		rept(i, L(s1)) {
 			if (s1[i] < 'a' || s1[i] > 'z') continue;
 			p[s1[i] - 'a'] = s2[i] - 'a';
 		}
 	}
 
 	rept(i, 26) {
 		bool ok = 1;
 		rept(j, 25) {
 			if (p[j] == i) {
 				ok = 0;
 				break;
 			}
 		}
 		if (ok) {
 			p[25] = i;
 			break;
 		}
 	}
 
 	printf("const int mapping[] = {");
 	rept(i, 26) {
 		printf("%d", p[i]);
 		if (i < 25) printf(","); else
 		printf("};\n");
 	}*/
 
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("output.txt","w",stdout);
 	
 	gets(str);
 	sscanf(str, "%d", &kolt);
 	rep(hod, kolt) {
 		gets(str);
 		n = (int)strlen(str);
 		rept(i, n) {
 			if (str[i] < 'a' || str[i] > 'z') continue;
 			str[i] = mapping[str[i] - 'a'] + 'a';
 		}
 		printf("Case #%d: %s\n", hod, str);
 	}
 }
