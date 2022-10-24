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
 
 
 
 vector<string> path;
 set<string> vis;
 vector<string> bbb;
 
 char dfs(const string& in)
 {
 	char ok = 1;
 	for (int i = 0 ; i < in.size(); ++i)
 	{
 		if (in[i] != '+')
 		{
 			ok = 0; break;
 		}
 	}
 
 	if (ok)
 	{
 		path.push_back(in);
 		if (bbb.empty() || bbb.size() > path.size())
 			bbb = path;
 		path.pop_back();
 		return 1;
 	}
 	vis.insert(in);
 	path.push_back(in);
 	for (int n = 1 ; n <= in.size(); ++n)
 	{
 		string nextS = in;
 		reverse(nextS.begin(), nextS.begin() +n);
 		for (int i = 0 ; i < n; ++i)
 		{
 			nextS[i] = nextS[i]=='+' ? '-' : '+' ;
 		}
 
 		if ( vis.find(nextS) == vis.end())
 		{
 			
 			dfs(nextS);
 		}
 
 	}
 	vis.erase(vis.find(in));
 	path.pop_back();
 
 	return 0;
 }
 
 int main(int a, char **ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		string in;
 		cin >> in;
 
 	/*	path.clear();
 		vis.clear();
 		bbb.clear();
 		dfs(in);
 		for (int i = 0 ; i < bbb.size(); ++i)
 			cout << bbb[i] << endl;
 		*/
 
 		int ans = 0;
 		char prev = in.back();
 		for (int i = in.size()-1; i--;)
 		{
 			if (prev != in[i])
 			{
 				if (prev == '-')
 					ans += 2;
 			}
 			prev = in[i];
 		}
 		if ( prev == '-')
 			ans++;
 		
 		printf("Case #%d: " , ++cases );
 
 		printf("%d\n" , ans);
 
 	}
 
 	return 0;
 }
 
