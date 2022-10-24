#include<fstream>
 #include<iostream>
 #include<sstream>
 #include<iomanip>
 #include<string>
 #include<vector>
 #include<list>
 #include<set>
 #include<map>
 #include<queue>
 #include<algorithm>
 #include<functional>
 #include<numeric>
 #include<bitset>
 using namespace std;
 typedef pair<int, int> pii;
 typedef long long ll;
 #define mp make_pair
 
 namespace
 {
 	int n;
 	string s;
 
 	int dp[51][51];
 
 	int go(int a, int b)
 	{
 		if (a == b) return 0;
 		int& ret = dp[a][b];
 		if (ret >= 0)
 			return ret;
 
 		ret = 0;
 		for (int c = a + 1; c < b; c+=2)
 		{
 			int thisRet = (s[a] == s[c] ? 10 : 5);
 			thisRet += go(a + 1, c);
 			thisRet += go(c+1, b);
 			ret = max(ret, thisRet);
 		}
 
 		return ret;
 	}
 }
 
 //int main16R3_A()
 int main()
 {
 	ifstream fin("A-small-attempt0.in");
 	ofstream fout("A-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		fin >> s;
 		n = s.size();
 		memset(dp, -1, sizeof(dp));
 
 
 		int result = go(0, n);
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
