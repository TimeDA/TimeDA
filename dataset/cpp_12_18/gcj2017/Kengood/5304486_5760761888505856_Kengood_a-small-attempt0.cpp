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
 
 
 bool aa(vector<string>& input,vector<string>& output,int r, int c)
 {
 			for (int i = 0; i < r; ++i)
 		{
 			for (int j = 0; j < c; ++j)
 			{
 				if (output[i][j] == '?' || (input[i][j] != '?' && input[i][j] != output[i][j]))
 				{
 					//cerr << "wtf";
 					//cerr << cases+1<<endl;
 					/*for (int i = 0; i < r; ++i)
 					{
 						cerr << input[i] << endl;
 					}*/
 					return 0;
 				}
 
 			}
 		}
 			return 1;
 }
 
 int main(int __an, char **__ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		int r, c;
 		cin >> r >> c;
 		vector<string> input(r), output;
 		for (int i = 0; i < r; ++i)
 			cin >> input[i];
 		output = input;
 		for (int i = 0; i < r; ++i)
 		{
 			for (int j = 0; j < c; ++j)
 			{
 				if (input[i][j] != '?')
 				{
 					bool tt = 0, inin = 0;
 					if ( i+1 >= r || output[i+1][j] != '?')
 						inin = 1;
 
 					for (int n = i+1; n < r; ++n)
 					{
 						inin=1;
 						if (output[n][j] == '?')
 						{
 							output[n][j] = input[i][j];
 							tt = 11;
 						}
 						else
 							break;
 					}
 					bool noin = 1;
 					if(tt || inin)
 					{
 						for (int n = i; n--;)
 						{
 							if (output[n][j] == '?')
 							{
 								noin = 0;
 								output[n][j] = input[i][j];
 								tt = 11;
 							}
 							else
 								break;
 						}
 						//if (i==0) noin = 0;
 					}
 					
 					if(r == 1)
 					{
 					//	cout << "wtf";
 						for (int n = j+1; n < c; ++n)
 						{
 							if (output[i][n] == '?')
 								output[i][n] = input[i][j];
 							else
 								break;
 						}
 						for (int n = j; n--;)
 						{
 							if (output[i][n] == '?')
 								output[i][n] = input[i][j];
 							else
 								break;
 						}
 					}
 					
 				
 				}
 			}
 		}
 
 		while(!aa(input,output,r,c))
 		for (int i = 0; i < r; ++i)
 		{
 			for (int j = 0; j < c; ++j)
 			{
 				if (output[i][j] == '?')
 				{
 					int dd = -1;
 					if (j == 0) dd = 1;
 					bool changed = 0;
 
 					if( output[i][j+dd] == '?')
 					{
 						if (j<c-1 && output[i][j+1] !='?')
 							dd = 1;
 					}
 					for (int n = i; n < r; ++n)
 					{
 						if (output[n][j] != '?')
 							break;
 						if (output[n][j+dd] == '?' || output[n][j+dd] !=output[i][j+dd])
 							break;
 						else
 						{
 							changed = 1;
 							output[n][j] = output[n][j+dd];
 						}
 					}
 					for (int n = i; n--;)
 					{
 						if (output[n][j] != '?')
 							break;
 						if (output[n][j+dd] == '?' || output[n][j+dd] !=output[i][j+dd])
 							break;
 						else
 						{
 							changed = 1;
 							output[n][j] = output[n][j+dd];
 						}
 					}
 
 					if (!changed)
 					{
 						int dd = -1;
 						if (i == 0) dd = 1;
 						for (int n = j; n < c; ++n)
 						{
 							if (output[i][n] != '?')
 								break;
 							if (output[i+dd][n] !=output[i+dd][j])
 								break;
 							else
 							{
 								changed = 1;
 								output[i][n] = output[i+dd][j];
 							}
 						}
 
 
 					}
 
 				}
 			}
 		}
 
 
 
 	
 		printf("Case #%d: " , ++cases);
 		puts("");
 		for (int i = 0; i < r; ++i)
 			cout << output[i] << endl;
 
 	}
 
 	return 0;
 }
 
