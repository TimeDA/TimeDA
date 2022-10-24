#pragma comment(linker, "/STACK:134217728")
 
 #include <cstdio>
 #include <iostream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <string>
 #include <algorithm>
 #include <numeric>
 #include <functional>
 #include <cmath>
 #include <complex>
 #include <memory.h>
 #include <time.h>
 
 using namespace std;
 
 typedef long long LL;
 
 int cases, n;
 int a[1 << 10];
 
 int main()
 {
 #ifndef _DEBUG
 	freopen("B.in", "r", stdin);
 	freopen("B.out", "w", stdout);
 #endif
 	cin >> cases;
 	for(int num = 1; num <= cases; ++num)
 	{
 		cin >> n;
 		for(int i = 0; i < n; ++i)
 			cin >> a[i];
 		sort(a, a + n, greater<int>());
 		int res = (int)1e9;
 		for(int i = 1; i <= a[0]; ++i)
 		{
 			int now = i;
 			for(int j = 0; j < n; ++j)
 				now += (a[j] + i - 1) / i - 1;
 			res = min(res, now);
 		}
 		cout << "Case #" << num << ": " << res << endl;
 	}
 	return 0;
 }