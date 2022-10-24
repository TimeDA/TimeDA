#include <algorithm>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cctype>
 #include <cmath>
 #include <numeric>
 #include <cstring>
 
 typedef long long i64d;
 
 using namespace std;
 
 int main()
 {
 	freopen("C-small-attempt1.in" , "r" , stdin);
 	//freopen("input.txt" , "r" , stdin);
 	freopen("C-small-attempt1.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d:" , ca);
 		int n;
 		int a[2010];
 		scanf("%d" , &n);
 		for (int i = 0; i < n-1; i ++) scanf("%d" , &a[i]);
 		a[n-1] = n+1;
 		int imp = 0;
 		int h[2010];
 		int li[2010];
 		for (int i = 0; i < n; i ++)
 		{
 			for (int j = i + 1; j < n; j ++)
 				if (j < a[i]-1 && a[j] > a[i]) {imp = 1; break;}
 			if (imp) break;
 		}
 		if (imp) {printf(" Impossible\n"); continue;}
 		h[0] = 10000;
 		h[n-1] = 1;
 		int far = a[0];
 		li[1] = h[0] + 2000;
 		for (int i = 2; i < far; i ++) li[i] = li[i-1] + 2000;
 		for (int i = 1; i < n; i ++)
 		{
 			if (i == far-1)
 			{
 				h[i] = li[i];
 				far = a[i];
 				li[i+1] = h[i] + 2000;
 				for (int j = i+2; j < far; j ++) li[j] = li[j-1] + 2000;
 			}
 			else
 			{
 				if (a[i] == far) h[i] = li[i]-1;
 				else
 				{
 					h[i] = h[i-1] - 10;
 					int x = (li[a[i]-1] - h[i]) / a[i]-1-i;
 					li[i+1] = h[i] + x;
 					for (int j = i+2; j < a[i]; j ++) li[j] = li[j-1] + x;;
 				}
 			}
 		}
 		for (int i = 0; i < n; i ++) printf(" %d" , h[i]);
 		printf("\n");
 	}
 	return 0;
 }