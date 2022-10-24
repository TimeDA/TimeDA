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
 string s;
 
 int main()
 {
 #ifndef _DEBUG
 	freopen("A.in", "r", stdin);
 	freopen("A.out", "w", stdout);
 #endif
 	cin >> cases;
 	for(int num = 1; num <= cases; ++num)
 	{
 		cin >> n;
 		cin >> s;
 		int res = 0;
 		int sum = 0;
 		for(int i = 0; i < n; ++i)
 		{
 			sum += s[i] - '0';
 			if (s[i + 1] != '0')
 				res = max(res, max(0, i + 1 - sum));
 		}
 		cout << "Case #" << num << ": " << res << endl;
 	}
 	return 0;
 }