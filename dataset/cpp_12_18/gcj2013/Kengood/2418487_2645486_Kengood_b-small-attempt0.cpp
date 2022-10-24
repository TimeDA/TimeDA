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
 
 
 long long act[10000+10];
 
 
 long long brute[100][100];
 
 int main()
 {	
 	scanf("%d" , &cases);	
 	while( cases-- )
 	{
 		printf("Case #%d: " , Case++);   
 
 
 		long long E , R;
 		cin >> E >> R;
 
 		int n;
 		cin >> n;
 		for(int i = 0 ; i < n; ++i)
 		{
 			cin >> act[i];
 		}
 
 		long long ans = 0;
 
 		if( R >=E )
 		{
 			for(int i = 0 ; i < n; ++i)
 				ans += act[i]*E;
 		}
 		else
 		{
 			memset(brute,0,sizeof(brute));
 			for(int i = 0 ; i < n; ++i)
 			{
 				for(int j = 0; j <=E; ++j)
 				{
 					for(int k = 1; k <=R; ++k)
 					{
 						int next = j+k; if( next > E ) next = E;
 						brute[i+1][E-next] =  max(brute[i+1][E-next], act[i]*next + brute[i][j]);
 						ans = max(brute[i+1][E-next],ans);
 					}
 				}
 
 				
 			}
 
 		}
 
 
 		cout << ans << endl;
 	}
 
 
 	return 0;
 }
