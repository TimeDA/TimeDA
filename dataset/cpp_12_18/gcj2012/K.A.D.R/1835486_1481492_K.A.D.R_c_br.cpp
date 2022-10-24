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
 
 ll m, f;
 int n, on;
 pii mas[201], tmp[201], mem[201];
 inline void readInput() {
 	scanf("%I64d%I64d%d", &m, &f, &n);
 	rept(i, n) {
 		scanf("%I64d%I64d", &mas[i].x, &mas[i].y);
 	}
 
 
 	/*m = rand() % 100 + 1; f = rand() % 100 + 1; n = 3;
 	rept(i, n) {
 		mas[i].x = rand() % 100 + 1; mas[i].y = rand() % 100;
 	}*/
 
 	rept(i, n) mem[i] = mas[i];
 	on = n;
 	rept(i, n) mas[i].y = -mas[i].y;
 }
 	
 inline ll price(ll days) {
 	if (!days) return 0;
 	ll ans = 0;
 	rept(i, n) {
 		ll can = mas[i].y;
 		//if (i) can -= mas[i - 1].y + 1;
 		if (can > days) can = days;
 		if ((double)mas[i].x * can > 5e18) return m + 1;
 		ans += mas[i].x * can;
 		if (ans > m) return m + 1;
 		days -= can;
 		if (!days) break;
 	}
 	ans += f;
 	if (ans > m) return m + 1;
 	if (days) return m + 1; else
 	return ans;
 }
 
 inline bool good_one(ll days) {
 	ll pone = price(days);
 	if (pone > m) return 0;
 	/*ll h1 = days / 2, h2 = days - days / 2;
 	ll ptwo = price(h1) + price(h2);
 	if (pone < ptwo) return 1; else
 	return 0;*/
 	rep(i, days) {
 		ll cur = price(i) + price(days - i);
 		if (cur < pone) return 0;
 	}
 	return 1;
 }
 inline bool check(ll t) {
 	if (price(1) > m) return 0;
 	if (price(t) <= m) return 1;
 	ll cdays = 0;
 	rept(i, n + 1) {
 		if (cdays >= t) break;
 
 		/*ll p = price(cdays);
 		ll l = cdays, r = cdays + mas[i].y;
 		if (!l) l = 1;
 		while (r - l > 3) {
 			ll xx1 = (r + l) / 2, xx2 = xx1 - 1;
 			double v1 = (double)t / (cdays + xx1) * (p + (double)mas[i].x * xx1 + f);
 			double v2 = (double)t / (cdays + xx2) * (p + (double)mas[i].x * xx2 + f);
 			if (v1 < v2) r = xx2; else
 			l = xx1;
 		}
 		cerr << l << " " << r << endl;*/
 		for (ll j = cdays; j <= cdays + 300; ++j) {
 			if (j <= 0 || j > t) continue;
 			ll cnt = t / j;
 			ll p = price(j);
 			if (p > m + 1) break;
 			if ((double)cnt * p > 5e18) continue;
 			ll tot = cnt * p;
 			if (tot > m) continue;
 			tot += price(t % j);
 			if (tot <= m) {
 				i = i;
 				return 1;
 			}
 		}
 		
 
 		/*ll cnt = t / cdays;
 		if ((double)cnt * p > 5e18) continue;
 		ll tot = cnt * p;
 		if (tot > m) continue;
 		tot += price(t % cdays);
 		if (tot <= m) return 1;*/
 
 		cdays += mas[i].y;
 	}
 	return 0;
 }
 
 ll run() {
 	// put an answer into pAns
 	sort(mas, mas + n);
 	int k = 0;
 	rept(i, n) {
 		mas[i].y = -mas[i].y;
 		if (k && mas[i].y <= tmp[k - 1].y) continue;
 		tmp[k++] = mas[i];
 	}
 	n = k;
 	rept(i, n) mas[i] = tmp[i];
 	FORD(i, n - 1, 1) {
 		mas[i].y -= mas[i - 1].y;
 	}
 	++mas[0].y;
 
 	//exit(0);
 	ll l = 0, r = 1000000000000000001LL;
 	while (r - l > 1) {
 		ll xx = (r + l) / 2;
 		if (check(xx)) l = xx; else
 		r = xx;
 	}
 	return l;
 }
 
 ll cpr[2000001], dp[2000001];
 ll brute() {
 	n = on;
 	rept(i, n) mas[i] = mem[i];
 	ll ans = 0;
 	rept(i, n) mas[i].y = -mas[i].y;
 	sort(mas, mas + n);
 	int k = 0;
 	rept(i, n) {
 		mas[i].y = -mas[i].y;
 		if (i && mas[i].y <= mas[i - 1].y) continue;
 		tmp[k++] = mas[i];
 	}
 	n = k;
 	rept(i, n) mas[i] = tmp[i];
 	FORD(i, n - 1, 1) {
 		mas[i].y -= mas[i - 1].y;
 	}
 	++mas[0].y;
 	
 	rep(i, m) cpr[i] = price(i);
 	dp[0] = 0;
 	rep(i, INF) {
 		dp[i] = m + 1;
 		rep(j, i) {
 			ll cur = dp[i - j] + cpr[j];
 			//if (i == 951 && cur <= dp[i]) cerr << j << endl;
 			dp[i] = min(dp[i], dp[i - j] + cpr[j]);
 		}
 		if (dp[i] <= m) ans = i; else
 		break;
 	}
 	return ans;
 }
 int kolt;
 int main() {
 	//freopen("input.txt","r",stdin);
 	freopen("C-small-attempt3.in","r",stdin);
 	freopen("output.txt","w",stdout);
 
 
 	scanf("%d", &kolt);
 	//kolt = 10000;
 	rep(hod, kolt) {
 		cerr << hod << endl;
 		readInput();
 		/*ll ans = run();
 		ll br = brute();
 		if (ans != br) {
 			cerr << "HER " << ans << " " << br << endl;
 			exit(0);
 		} else
 		cerr << "OK " << hod << " " << ans << endl;*/
 		ll ans = run();
 		cout << "Case #" << hod << ": " << ans << endl;
 	}
 }
