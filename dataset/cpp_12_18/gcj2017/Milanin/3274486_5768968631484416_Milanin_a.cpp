#define _CRT_SECURE_NO_WARNINGS
 #pragma comment(linker, "/STACK:100000000")
 #include <stdio.h>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 #include <fstream>
 #include <iostream>
 #include <ctime>
 #include <fstream>
 using namespace std;
 const double PI=acos(-1.0);
 const int N=1100;
 pair <double, double> a[N];
 void solve()
 {
 	int n, k;
 	scanf("%d%d", &n, &k);
 	for(int i=0; i<n; i++)
 	{
 		int h, r;
 		scanf("%d%d", &r, &h);
 		a[i].first=2*PI*h*r;
 		a[i].second=PI*r*r;
 	}
 	sort(a, a+n);
 	reverse(a, a+n);
 	double bs=0;
 	for(int i=0; i<n; i++)
 	{
 		double s=a[i].second+a[i].first;
 		int t=1;
 		for(int j=0; j<n && t<k; j++)
 			if(j!=i) { s+=a[j].first; t++; }
 		bs=max(bs, s);
 	}
 	printf("%.10lf\n", bs);
 }
 int main()
 {
 	int ts;
 	scanf("%d", &ts);
 	for(int t=1; t<=ts; t++)
 	{
 		printf("Case #%d: ", t);
 		solve();
 	}
 	return 0;
 }