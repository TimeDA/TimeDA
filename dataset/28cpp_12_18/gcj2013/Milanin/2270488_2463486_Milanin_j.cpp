#include <stdio.h>
 long long rev(long long n)
 {
 	long long r;
 	for(r=0; n; r=r*10+n%10, n/=10);
 	return r;
 }
 long long len(long long n)
 {
 	long long r;
 	for(r=1; n; r=r*10, n/=10);
 	return r;
 }
 long long get(long long A, long long B)
 {
 	long long t, a, l, r, s;
 	for(s=0, t=1; ; t++)
 	{
 		l=len(t);
 		r=rev(t);
 		a=t*l+r;
 		a=a*a;
 		if(a>=A && a<=B) s+=a==rev(a);
 		a=t/10*l+r;
 		a=a*a;
 		if(a>=A && a<=B) s+=a==rev(a);
 		if(a>B) break;
 	}
 	return s;
 }
 int main()
 {
 	long long a, b;
 	int ts, t;
 	for(scanf("%d", &ts), t=1; t<=ts; t++)
 	{
 		scanf("%lld%lld", &a, &b);
 		printf("Case #%d: %lld\n", t, get(a, b));
 	}
 	return 0;
 }