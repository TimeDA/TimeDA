#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 using namespace std;
 #define mod 1000002013
 map <int, long long> m, v, vv;
 map <int, long long>::iterator it, jt;
 vector <int> d;
 long long cost(long long b, long long l, long long p)
 {
 	return (2*b-1-l)*l/2%mod*(p%mod)%mod;
 }
 int main()
 {
 	int i, j, k, l, n;
 	long long r, t, g;
 	int ts, tst;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		m.clear();
 		v.clear();
 		for(g=0, scanf("%d%d", &n, &k); k--; scanf("%d%d%d", &i, &j, &l), g=(g+cost(n, j-i, l))%mod, m[i]+=l, m[j]-=l);
 		for(r=0, k=0, it=m.begin(); it!=m.end(); it++)
 		{
 			vv.clear();
 			k=it->first-k;
 			for(jt=v.begin(); jt!=v.end(); jt++)
 			{
 				r=(r+cost(jt->first, k, jt->second))%mod;
 				vv[jt->first-k]=jt->second;
 			}
 			v=vv;
 			k=it->first;
 			if(it->second>0) v[n]+=it->second;
 			if(it->second<0)
 			{
 				d.clear();
 				t=-it->second;
 				for(jt=v.end(); jt!=v.begin(); )
 				{
 					jt--;
 					if(jt->second<=t) { d.push_back(jt->first); t-=jt->second; }
 					else { jt->second-=t; break; }
 				}
 				for(i=0; i<d.size(); v.erase(d[i]), i++);
 			}
 		}
 		printf("%lld\n", ((g-r)%mod+mod)%mod);
 	}
 	return 0;
 }