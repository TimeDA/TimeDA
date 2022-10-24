#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <string>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 int n, m;
 vector<int> a[22];
 map<string, int> D;
 char s[20005], ss[20];
 int v[20005][2];
 
 int mapto(char s[]){
 	string ss = (string)s;
 	if (D[s] != 0) return D[s];
 	D[s] = ++m;
 	return m;
 }
 
 void solve(int tc){
 	m = 0;
 	scanf("%d", &n); gets(s);
 	D.clear();
 	FOR(i,0,n){
 		a[i].clear();
 		gets(s);
 		for (char *c = strtok(s, " "); c != NULL; c = strtok(NULL, " ")){
 			sscanf(c, "%s", &ss);
 			a[i].push_back(mapto(ss));
 		}
 	}
 	
 	int ret = m;
 	CLR(v, 0);
 	FOR(i,0,2){
 		FOR(k,0,a[i].size()) v[a[i][k]][i] = 1;
 	}
 	int B = 0;
 	FOE(i,1,m){
 		if (v[i][0] && v[i][1]) ++B;
 	}
 	
 	FOR(i,0,1<<n) if ((i & 3) == 2){
 		int S = 0;
 		FOR(j,2,n){
 			int id = !!(i & (1<<j));
 			FOR(k,0,a[j].size()){
 				v[a[j][k]][id] ++;
 				if (v[a[j][k]][id^1] && v[a[j][k]][id] == 1) ++S;
 			}
 		}
 		FOR(j,2,n){
 			int id = !!(i & (1<<j));
 			FOR(k,0,a[j].size()){
 				v[a[j][k]][id] --;
 			}
 		}
 		ret = min(ret, B + S);
 	}
 	
 	
 	printf("Case #%d: %d\n", tc, ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
