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
#include <cassert>

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
#define prev PREV
                         
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

string get (int x) {
    string s = "";
    while (x) {
        s += char (x % 10) + '0';
        x /= 10;
    }
    reverse (all (s));
    s += "\n";
    re s;
}
    
//int p[1000000];
//int ct;

vi ask (int a, int b) {
    vi v;
    string t = get (a);
    string s (sz (t) * b, '\n');
    for (int i = 0; i < sz (t) * b; i++) s[i] = t[i % sz (t)];
    printf ("%s", s.c_str ());
    fflush (stdout);
    for (int i = 0; i < b; i++) {
        int x;
//        printf ("%d\n", a);
//        fflush (stdout);
/*        if (ct == 0) {
            random_shuffle (p, p + n);            
        }*/
        scanf ("%d", &x);
        assert (x != -1);
/*        x = int (p[ct] >= a);
        ct = (ct + 1) % n;*/
        if (x) v.pb (i);
    }
    re v;
}

int main () {
//    for (int i = 0; i < 1000000; i++) p[i] = i + 1;
	int tt;
    scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
        scanf ("%d", &m);
        assert (m != -1);
        //assert (m != );
//        m = 100000;
//        n = rand () % 24 + 2;
//        random_shuffle (p, p + 1000000);
//        ct = 0;
        int l = 0, r = 1000000;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (ask (s, 100).empty ()) l = s; else r = s;
        }
        vi v = ask (r, 50000);
        int t = sz (v);
        int res = (v[t - 1] - v[0]) / (t - 2);
        cout.precision (20);
        printf ("%d\n", -res);
//        printf ("%d %d\n", -res, n);
/*        if (res != n) {
            cout << l << endl;
            for (int i = 0; i < n; i++) printf ("%d ", p[i]);
            printf ("");
        }*/
//        assert (res == n);
        fflush (stdout);
		//fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
