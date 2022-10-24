#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <iostream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int n;
 double V, T;
 
 struct Source
 {
 	double rate, temp;
 	bool operator<(const Source &x) const
 	{
 		return temp < x.temp;
 	}
 };
 
 Source a[100];
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 		
 		scanf("%d %lf %lf", &n, &V, &T);
 
 		for(int i = 0; i < n; i++) scanf("%lf %lf", &a[i].rate, &a[i].temp);
 
 		sort(a, a + n);
 
 		// find max volume of temperature T in 1 second
 		double curV = 0.0;
 		double curTV = 0.0;
 		for(int i = 0; i < n; i++) 
 		{
 			curV += a[i].rate;
 			curTV += a[i].rate * a[i].temp;	
 		}
 
 		// curTV / curV should be equal to T
 		// or: curTV -> curV * T
 
 		if (curTV / curV < T)
 		{
 			// too cold -- switch off cold water
 			for(int i = 0; i < n; i++)
 			if (a[i].temp < T)
 			{
 				double diff = (curV * T - curTV) / (T - a[i].temp);
 				if (diff > a[i].rate) diff = a[i].rate;
 				curV -= diff;
 				curTV -= diff * a[i].temp;
 			}
 		}
 		else
 		{
 			// too hot -- switch off hot water
 			for(int i = 0; i < n; i++)
 			if (a[i].temp > T)
 			{
 				double diff = (curTV - curV * T) / (a[i].temp - T);
 				if (diff > a[i].rate) diff = a[i].rate;
 				curV -= diff;
 				curTV -= diff * a[i].temp;
 			}
 		}
 
 		if (curV < 1e-7)
 		{
 			puts("IMPOSSIBLE");
 			continue;
 		}
 
 		double finalT = curTV / curV;
 		double res = V / curV;
 
 		if (fabs(finalT - T) > 1e-7) puts("IMPOSSIBLE"); else printf("%.10lf\n", res);
 	}
 	return 0;
 }