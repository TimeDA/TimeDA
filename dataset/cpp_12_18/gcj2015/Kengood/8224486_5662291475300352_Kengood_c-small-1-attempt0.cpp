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
 
 int _SKIP = -1, _START = -1;
 void __aa(int a, char **ag)
 {
 	if (a > 1 )
 	{
 		_SKIP = atoi(ag[2]);
 		_START = atoi(ag[1]);
 	}
 }
 
 
 struct Human
 {
 	long long D , H , M;
 };
 
 int main(int a, char **ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	
 	__aa(a,ag);
 	///////////////
 
 
 	while (Case--)	
 	{
 		int n;
 		vector<Human> in;
 		cin >> n;
 		for (int i = 0 ; i < n; ++i)
 		{
 			Human temp;
 			cin >> temp.D >> temp.H >> temp.M;
 			for (int j = 0; j < temp.H; ++j)
 			{
 				Human temp2 = temp;
 				temp2.M+=j;
 				in.push_back(temp2);
 			}
 		}
 
 		printf("Case #%d: " , ++cases );
 
 		int ans = 0;
 		if ( in.size() < 2)
 			cout << 0 << endl;
 		else
 		{
 			if (in[0].D > in[1].D || (in[0].D == in[1].D && in[0].M < in[1].M) )
 				swap(in[0], in[1]);
 			
 			double backT = (1/(360.0- in[0].D)) * (360.0/in[0].M);
 			double frontDist = (double)in[1].D + 
 				        backT* (360.0*in[1].M);						
 			if ( frontDist <  360.0 - (in[1].D-in[0].D) )
 				cout << 1 << endl;
 			else
 				cout << 0 << endl;
 
 
 		}
 	}
 
 	return 0;
 }
 
