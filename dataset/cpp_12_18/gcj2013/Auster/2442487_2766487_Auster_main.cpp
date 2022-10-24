#pragma comment(linker, "/STACK:33554432")
 
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
 #include <complex>
 #include <memory.h>
 
 using namespace std;
 
 typedef long long LL;
 typedef vector<int> vint;
 typedef vector<vector<int> > vvint;
 
 int N;
 LL P;
 
 bool canLose(LL x)
 {
 	LL pos = 0;
 
 	LL less = x;
 	LL ALL = 1LL << N;
 
 	while (less)
 	{
 		pos += ALL / 2;
 		less = (less - 1) / 2;
 		ALL >>= 1;
 	}
 
 	return !(P > pos);
 }
 
 bool canWin(LL x)
 {
 	LL pos = 0;
 
 	LL more = (1LL << N) - x - 1;
 	LL ALL = 1LL << N;
 
 	while (more)
 	{
 		more = (more - 1) / 2;
 		ALL >>= 1;
 	}
 	pos += ALL - 1;
 	return P > pos;
 }
 
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	
 	int T;
 	scanf("%d", &T);
 	for(int I = 1; I <= T; ++I)
 	{
 		scanf("%d", &N);
 		scanf("%lld", &P);
 
 		LL L = 0, R = 1LL << N;
 
 		LL x, y;
 
 		while (R - L > 1)
 		{
 			LL M = (L + R) / 2;
 			if (canLose(M))
 				R = M;
 			else
 				L = M;
 		}
 		x = L;
 
 		L = 0, R = 1LL << N;
 
 		while (R - L > 1)
 		{
 			LL M = (L + R) / 2;
 			if (canWin(M))
 				L = M;
 			else
 				R = M;
 		}
 		y = L;
 
 		printf("Case #%d: %lld %lld\n", I, x, y);
 	}
 
 	return 0;
 }
