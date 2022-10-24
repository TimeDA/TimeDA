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
 using namespace std;
 
 #define IN_THE_SET(_set,_val) (_set.find(_val) != _set.end())
 
 int cases , Case = 1;
 ////////////
 
 char check(long long a)
 {
 	stringstream ss;
 	ss << a;
 	string as = ss.str();
 	int n = as.size();
 	for(int i = 0 ; i < n/2; ++i)
 	{
 		if( as[i] != as[n-i-1])
 			return 0;
 	}
 	return 1;
 }
 
 void aaa()
 {
 	int cnt = 0;
 	for(long long i = 1 ; i <= 32; ++i)
 	{
 		if( check(i) && check(i*i) )
 		{
 			//cout << i << " " << i*i << endl;
 			printf("%lld," , i*i);
 			++cnt;
 		}
 	}
 	cout << cnt;
 }
 
 const int n = 5;
 long long all[]={1,4,9,121,484};
 
 int main()
 {	
 	//aaa(); return 0;
 	scanf("%d" , &cases);	
 	while( cases-- )
 	{
 		printf("Case #%d: " , Case++);   
 		long long a , b;
 		cin >> a >> b;
 		int ans=0;
 		for(int i = 0 ; i < n; ++i)
 		{
 			if( all[i] <= b && all[i] >= a )
 				++ans;
 		}
 		
 		cout << ans << endl;
 	}
 
 
 	return 0;
 }
