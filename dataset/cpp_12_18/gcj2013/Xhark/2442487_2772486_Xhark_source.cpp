#include <algorithm>
 #include <vector>
 #include <string>
 #include <map>
 
 using namespace std;
 
 #include <stdio.h>
 const long long MOD = 1000002013LL;
 
 class sep {
 public:
 	long long s, e, p;
 } dat[1001];
 class EVENT {
 public:
 	long long x, p;
 	const bool operator < (EVENT &e) {
 		return x < e.x;
 	}
 } ev[2001];
 
 long long pos[1001], nu[1001], head;
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","w",stdout);
 	int T;
 	scanf("%d",&T);
 	while (T-- > 0) {
 		int n,m;
 		scanf("%d %d",&n,&m);
 		long long payA, payB;
 		payA = payB = 0;
 		for (int i=0;i<m;i++) {
 			scanf("%lld %lld %lld", &dat[i].s, &dat[i].e, &dat[i].p);
 			ev[2*i].x = dat[i].s;
 			ev[2*i].p = dat[i].p;
 			ev[2*i+1].x = dat[i].e;
 			ev[2*i+1].p = -dat[i].p;
 
 			long long d = dat[i].e - dat[i].s;
 			long long pay = d * n - d * (d-1) / 2;
 			pay = pay % MOD;
 			pay = (pay * dat[i].p) % MOD;
 			payA += pay;
 			payA %= MOD;
 		}
 		sort(ev, ev+m*2);
 		long long pp = 0;
 		head = 0;
 		for (int i=0;i<m*2;i++) {
 			if (ev[i].p > 0) {
 				pos[head] = ev[i].x;
 				long long bef = 0;
 				if (head > 0) bef = nu[head - 1];
 				nu[head] = bef + ev[i].p;
 				head ++;
 			}
 			pp += ev[i].p;
 			if (i < m*2-1 && ev[i].x != ev[i+1].x) {
 				long long D = ev[i+1].x - ev[i].x;
 				for (int j=0;j<head;j++) {
 					if (nu[j] >= pp) {
 						nu[j] = pp;
 						head = j+1;
 					}
 					long long bef = 0;
 					if (j > 0) bef = nu[j-1];
 					long long su = nu[j] - bef;
 					long long st = pos[j];
 
 					long long sd = ev[i].x - st;
 					long long U = n - sd;
 					long long pay = D * U - D * (D-1) / 2;
 					pay %= MOD;
 					pay = (pay * su) % MOD;
 					payB = (payB + pay) % MOD;
 				}
 			}
 		}
 		long long sol = (payA - payB + MOD)%MOD;
 		static int cs = 1;
 		printf("Case #%d: %lld\n", cs ++, sol);
 	}
 	return 0;
 }