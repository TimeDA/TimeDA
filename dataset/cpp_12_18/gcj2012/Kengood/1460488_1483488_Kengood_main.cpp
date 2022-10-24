//compiled in vc
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
 // C++
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <cstring>
 #include <climits>
 #include <ctime>
 using namespace std;
 
 
 int cases , Case = 1;
 
 
 int seq[128];
 int main()
 {	
 	scanf("%d" , &cases);
 
 	int n , s, p;
 
 	while( cases-- )
 	{
 		printf("Case #%d: " , Case++);   
 
 		cin >> n >> s >> p;
 		for(int i = 0 ; i < n; ++i)
 			cin >> seq[i];
 		sort(seq, seq+n);
 		reverse(seq,seq+n);
 		int ans = 0;
 		for(int i = 0 ; i < n; ++i)
 		{
 			if( seq[i] < 3 )
 			{
 				if(  seq[i] < 2 && seq[i] >= p )
 					++ans;
 				else if( s && seq[i] == 2 && seq[i] >= p )
 				{
 					--s;
 					++ans;
 				}
 			}
 			else
 			{
 				int t = seq[i] / 3;
 				int mod = seq[i] % 3;
 				if( t >= p ) ++ans;
 				else
 				{
 					if( mod == 0 )
 					{
 						if( s && t+1 >= p ){ --s; ++ans;}
 						continue;
 					}
 					if( t+1 >= p ) ++ans;
 					else if( s && mod == 2 && t+2 >= p )
 					{
 						--s;
 						++ans;
 					}
 
 				}
 			}
 		}
 
 		cout << ans << endl;
 	}
 
 
 	return 0;
 }
