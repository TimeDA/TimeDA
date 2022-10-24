#include <cstdio>
 #include <vector>
 #include <string>
 #include <sstream>
 #include <set>
 #include <iostream>
 
 using namespace std;
 
 typedef long long LL;
 
 int t;
 int A, B;
 stringstream ss;
 
 int c(string & a, int x)
 {
 	set<int> S;
 	for(int i = 1; i < a.size(); ++i)
 	{
 		string b = a.substr(i, a.size() - i) + a.substr(0, i);
 		if (b[0] == '0')
 			continue;
 		int y;
 		sscanf(b.c_str(), "%d", &y);
 		if (!(A <= y && y <= B))
 			continue;
 		if (y < x)
 			S.insert(y);
 	}
 	return (int)S.size();
 }
 
 int main()
 {
 	freopen("C.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	cin >> t;
 	for(int test = 1; test <= t; ++test)
 	{
 		cin >> A >> B;
 		int res = 0;
 		for(int i = A; i <= B; ++i)
 		{
 			string S;
 			ss.clear();
 			ss << i;
 			ss >> S;
 			res += c(S, i);
 		}
 		cout << "Case #" << test << ": " << res << endl;
 	}
 	return 0;
 }