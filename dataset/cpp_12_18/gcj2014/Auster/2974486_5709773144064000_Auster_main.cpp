#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <memory.h>
 
 using namespace std;
 
 int T;
 
 double c, f, x;
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &T);
 	for(int I = 0; I < T; ++I)
 	{
 		scanf("%lf%lf%lf", &c, &f, &x);
 		double res = x / 2.0;
 		double sum = 0;
 		for(int i = 0; i < (int)1e6; ++i)
 		{
 			sum += 1.0 / (2.0 + i * f);
 			res = min(res, c * sum + x / (2.0 + (i + 1) * f));
 		}
 		printf("Case #%d: %.7lf\n", I + 1, res);
 	}
 	return 0;
 }