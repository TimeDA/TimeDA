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
 
 int in[128][128];
 int rowMax[128];
 
 int makeIt[128][128];
 int n , m;
 
 char same()
 {
 	for(int i = 0 ; i < n; ++i)
 		for(int j = 0 ; j < m; ++j)
 			if( in[i][j] != makeIt[i][j] ) return 0;
 	return 1;
 }
 
 char sameCol(int c)
 {
 	for(int i = 0 ; i < n; ++i)
 		if( in[i][c] != makeIt[i][c] ) return 0;
 	return 1;
 }
 
 char makeSameCol(int c)
 {
 	int maxC = 0;
 	for(int i = 0 ; i < n; ++i)
 		maxC = max(maxC, in[i][c]);
 
 	for(int i = 0 ; i < n; ++i)
 		makeIt[i][c] = maxC;
 
 	return sameCol(c);
 }
 
 int main()
 {	
 	//aaa(); return 0;
 	scanf("%d" , &cases);	
 	while( cases-- )
 	//while(1)
 	{
 		printf("Case #%d: " , Case++);   
 
 		cin >> n >> m;
 
 		for(int i = 0 ; i < n; ++i)
 		{
 			rowMax[i] = 0;
 			for(int j = 0 ; j < m; ++j)
 			{
 				cin >> in[i][j];
 				rowMax[i] = max(rowMax[i] , in[i][j]);
 			}
 			for(int j = 0 ; j < m; ++j) makeIt[i][j] = rowMax[i];
 		}
 		if(same()) puts("YES");
 		else
 		{
 			for(int j = 0 ; j < m; ++j)
 			{
 				if( !sameCol(j) && !makeSameCol(j) )
 				{
 					puts("NO"); goto next;
 				}
 			}
 			if(same()) puts("YES");
 			else puts("NO");
 			next:;
 
 		}
 	}
 
 
 	return 0;
 }
