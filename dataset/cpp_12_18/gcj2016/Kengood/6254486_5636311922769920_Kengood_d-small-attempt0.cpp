#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <complex>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <cstring>
 #include <climits>
 #include <ctime>
 
 #include<unordered_map>
 #include<unordered_set>
 using namespace std;
 
 
 void foo(int K = 3, int C = 3)
 {
 	vector<string> all;	
 	for (int i = 0 ; i < (1<<K); ++i)
 	{
 		string a, GGG;
 		for (int b = 0 ; b < K; ++b)
 		{
 			if ( i&(1<<b) )
 				a.push_back('L');
 			else
 				a.push_back('G');
 			GGG.push_back('G');
 		}
 
 		string b = a;
 		
 		for (int n = 1; n < C; ++n)
 		{
 			string t;
 			for (int j = 0; j < b.size(); ++j)
 			{
 				if (b[j] == 'L')
 					t += a;
 				else
 					t += GGG;
 			}
 
 			b = t;
 		}
 
 	//	cout << b << endl;
 		all.push_back(b);
 	}
 
 	for (int c = 0; c < all[0].size(); ++c)
 	{
 		int LL = 0;
 		for (int i = 0; i < all.size(); ++i)
 		{		
 			if (all[i][c] == 'L')
 				++LL;
 		}
 		if (LL == 1 )
 		{
 			cout << c+1 << endl;
 			break;
 		}
 	}
 }
 
 long long randM()
 {
 	long long ans = 
 		(rand()%32768)<<30 &  (rand()%32768);
 
 	return ans;
 }
 
 long long pp(long long a, long long b)
 {
 	long long aaa = 1;
 	while (b--)
 	{
 		aaa *=a;
 	}
 	return aaa;
 }
 
 // 16^16 max K^C = 1000000000000000000 > 15^15
 
 long long mustWin[] = 
 {0,1,2,6,28,195,1866,22876,342392,6053445,123456790,2853116706,73686780564,2103299351335,
 65751519677858,2234152501943160,81985529216486896};
 
 int main(int a, char **ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		long long k, c , s;
 		cin >> k >> c >> s;
 	//	foo(k, c);
 
 		printf("Case #%d: " , ++cases );
 
 		if (c >= k && k < 16)
 		{
 			printf("%lld" , mustWin[k]);
 		}
 		else if ( k == s )
 		{
 			for (int i = 0; i < s; ++i)
 				printf(" %d" , i+1);
 		}
 		else 
 		{
 			printf("IMPOSSIBLE");
 		}
 
 		puts("");
 	}
 
 	return 0;
 }
 
