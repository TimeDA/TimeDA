#include <algorithm>
 #include <vector>
 #include <string>
 #include <map>
 
 using namespace std;
 
 #include <stdio.h>
 
 long long bestrank(long long p, long long n) {
 	if (n == 1) return 0;
 
 	long long res = 0;
 	if (p < n-1) {
 		p ++;
 	}
 	else {
 		res += n/2;
 	}
 	return res + bestrank(p/2, n/2);
 }
 
 long long worstrank(long long p,long long n) {
 	if (n == 1) return 0;
 	long long res = 0;
 	if (p > 0) {
 		res += n/2;
 		p --;
 	} else {
 	}
 	return res + worstrank(p/2, n/2);
 }
 
 long long worstsol(long long n, long long p) {
 	long long s = 0, e = (1LL << n) - 1;
 	long long m;
 	while(s<=e) {
 		m = (s+e) / 2;
 		if (worstrank(m, (1LL << n)) < p) s = m+1;
 		else e = m-1;
 	}
 	return s-1;
 }
 long long bestsol( long long n, long long p) {
 	long long s = 0, e = (1LL << n) - 1;
 	long long m;
 	while(s<=e) {
 		m = (s+e) / 2;
 		if (bestrank(m, (1LL << n)) < p) s = m+1;
 		else e = m-1;
 	}
 	return s-1;
 }
 int main() {
 	freopen("B-small-attempt0.in","r",stdin);
 	freopen("B-small-attempt0.out","w",stdout);
 	int T;
 	scanf("%d",&T);
 	while (T-- > 0) {
 		long long n, p;
 		scanf("%lld %lld",&n,&p);
 
 		static int cs = 1;
 		printf("Case #%d: %lld %lld\n", cs ++, worstsol(n, p), bestsol(n, p));
 
 	}
 	return 0;
 }