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
 
 
 int main()
 {	
 	scanf("%d" , &cases);	
 	while( cases-- )
 	{
 		printf("Case #%d: " , Case++);   
 
 		long long r , t;
 		cin >> r >> t;
 
 
 		long long b = (2*r-1);
 		long long ans = 0;
 
 		
 		if( b < 3037000498)
 			ans = (-b+sqrt( double( (b*b - 4*2*(-t) ) ) ) )/4  ;
 		else
 		{		
 			long long cur = 2*r+1;
 			int aa = 0;
 			while(t > 0 )
 			{
 				t-=cur;
 				if(t<0)break;
 				++ans;
 				++r;++r;
 				cur = 2*r+1;
 			}
 		}
 
 		
 
 		cout << ans << endl;
 	}
 
 
 	return 0;
 }
