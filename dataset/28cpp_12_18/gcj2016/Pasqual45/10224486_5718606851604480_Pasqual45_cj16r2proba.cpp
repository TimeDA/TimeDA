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
 	char target[256] = { 0 };
 	
 	string gens(string input, int n)
 	{
 		string ret = input;
 		while (n > 0)
 		{
 			ret.clear();
 
 			string s1, s2;
 			
 			for (int i = 0; i < input.size(); ++i)
 			{
 				char c = input[i];
 				char d = target[c];
 				ret += min(c, d);
 				ret += max(c, d);
 			}
 
 			input = ret;
 			--n;
 		}
 
 		return ret;
 	}
 
 	void check(const string& str, int p, int r, int s, string& result)
 	{
 		if (count(str.begin(), str.end(), 'P') == p && count(str.begin(), str.end(), 'R') == r && count(str.begin(), str.end(), 'S') == s)
 			result = str;
 	}
 
 	void tidy(string& s)
 	{
 		string s1, s2;
 		for (int len = 2; len < s.size(); len *= 2)
 		{
 			for (int i = 0; i < s.size(); i += len * 2)
 			{
 				s1 = s.substr(i, len);
 				s2 = s.substr(i + len, len);
 
 				if (s2 < s1)
 				{
 					copy(s2.begin(), s2.end(), s.begin() + i);
 					copy(s1.begin(), s1.end(), s.begin() + i + len);
 				}
 			}
 		}
 	}
 }
 
 //int main16R2_A()
 int main()
 {
 	ifstream fin("A-small-attempt0.in");
 	ofstream fout("A-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	target['P'] = 'R';
 	target['R'] = 'S';
 	target['S'] = 'P';
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		int n, r, p, s;
 		fin >> n >> r >> p >> s;
 
 		string result = "IMPOSSIBLE";
 		string sp = gens("P", n);
 		string sr = gens("R", n);
 		string ss = gens("S", n );
 
 		check(sp, p, r, s, result);
 		check(sr, p, r, s, result);
 		check(ss, p, r, s, result);
 
 		if (result != "IMPOSSIBLE")
 		{
 			tidy(result);
 		}
 			
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
