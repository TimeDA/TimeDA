#include <cstdio>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <sstream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <bitset>
 #include <numeric>
 #include <ctime>
 #include <cmath>
 #include <cassert>
 #include <algorithm>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 //#define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define INF 1000000007
 #define N 15
 int n; bool e[N]; int a[N];
 int mp[2010];
 bool f[16][1<<N];
 
 int main()
 {
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n;
 		memset(mp,-1,sizeof mp);
 		int L = 0;
 		for (int i = 0; i < n; i ++) {
 			string s; cin >> s >> a[i];
 			if (a[i]) {
 				if (mp[a[i]] == -1) mp[a[i]] = L++;
 				a[i] = mp[a[i]];
 			} else {
 				a[i] --;
 			}
 			e[i] = (s[0] == 'E'); 
 		}
 		memset(f,0,sizeof f);
 		for (int i = 0; i < (1<<n); i ++) 
 			f[0][i] = 1;
 		for (int i = 0; i < n; i ++) 
 			for (int j = 0; j < (1<<n); j ++) if (f[i][j]) {
 				if (e[i] == 1) {
 					if (a[i] == -1) {
 						for (int k = 0; k < n; k ++) if (~(j>>k)&1) f[i+1][j|(1<<k)] = 1;
 					} else {
 						if (~(j>>a[i])&1) f[i+1][j|(1<<a[i])] = 1;
 					}
 				} else {
 					if (a[i] == -1) {
 						for (int k = 0; k < n; k ++) if ((j>>k)&1) f[i+1][j^(1<<k)] = 1;
 					} else {
 						if ((j>>a[i])&1) f[i+1][j^(1<<a[i])] = 1;
 					}
 				}
 			}
 		int S = n+1;
 		for (int i = 0; i < (1<<n); i ++) 
 			if (f[n][i]) S = min(S, pct(i));
 		printf ("Case #%d: ",__);
 		if (S == n+1) puts ("CRIME TIME"); else printf ("%d\n",S);
 	}
 	return 0;
 }