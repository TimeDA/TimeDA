#include <cstdio>
 #include <numeric>
 #include <iostream>
 #include <vector>
 #include <set>
 #include <cstring>
 #include <string>
 #include <map>
 #include <cmath>
 #include <ctime>
 #include <algorithm>
 #include <bitset>
 #include <queue>
 #include <sstream>
 #include <deque>
 
 using namespace std;
 
 #define mp make_pair
 #define pb push_back
 #define rep(i,n) for(int i = 0; i < (n); i++)
 #define re return
 #define fi first
 #define se second
 #define sz(x) ((int) (x).size())
 #define all(x) (x).begin(), (x).end()
 #define sqr(x) ((x) * (x))
 #define sqrt(x) sqrt(abs(x))
 #define y0 y3487465
 #define y1 y8687969
 #define fill(x,y) memset(x,y,sizeof(x))
                          
 typedef vector<int> vi;
 typedef long long ll;
 typedef long double ld;
 typedef double D;
 typedef pair<int, int> ii;
 typedef vector<ii> vii;
 typedef vector<string> vs;
 typedef vector<vi> vvi;
 
 template<class T> T abs(T x) { re x > 0 ? x : -x; }
 
 int n;
 int m;
 int x[10000], d[10000], res[10000];
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		scanf ("%d", &n);
 		for (int i = 0; i < n; i++) {
 			scanf ("%d%d", &x[i], &d[i]);
 			res[i] = 0;
 		}	
 		int f;
 		scanf ("%d", &f);
 		int ok = 0;	
 		res[0] = x[0];
 		for (int i = 0; i < n; i++) {
 			if (x[i] + res[i] >= f) ok = 1;
 			for (int j = i + 1; j < n; j++)
 				if (x[j] <= x[i] + res[i])
 					res[j] = max (res[j], min (d[j], x[j] - x[i]));
 		}
 
 		cout << "Case #" << it << ": ";
 		if (ok) printf ("YES"); else printf ("NO");
 
 		cout << endl;
 	}
 	return 0;
 }