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
 int was[2000001];
 int x[20];
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 
 	        scanf ("%d", &n);
 	        for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
 		cout << "Case #" << it << ":" << endl;
 
 	        memset (was, 0, sizeof (was));
 	        int ok = 0;
 	        for (int i = 1; i < (1 << n); i++) {
 	        	int cur = 0;
 	        	for (int j = 0; j < n; j++)
 	        		if ((i >> j) & 1)
 	        			cur += x[j];
 	        	if (was[cur]) {
 	        		int k = was[cur];
 	        		for (int j = 0; j < n; j++)
 	        			if ((i >> j) & 1)
 	        				printf ("%d ", x[j]);
 	        		printf ("\n");
 	        		for (int j = 0; j < n; j++)
 	        			if ((k >> j) & 1)
 	        				printf ("%d ", x[j]);
 	        		printf ("\n");
 	        		ok = 1;
 	        		break;
 	        	} else was[cur] = i;
 	        }
 	        if (!ok) cout << "Impossible" << endl;
 	}
 	return 0;
 }