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
 
 //int main17RQ_A()
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
 		string s;
 		fin >> s;
 
 		int k;
 		fin >> k;
 		
 		int result(0);
 		for (int i = 0; i + k <= s.size(); ++i)
 		{
 			if (s[i] == '-')
 			{
 				++result;
 				for_each(s.begin() + i, s.begin() + i + k, [](char& c){c = (c == '+' ? '-' : '+'); });
 			}
 		}
 
 		if (count(s.begin(), s.end(), '-'))
 		{
 			fout << "Case #" << zz << ": " << "IMPOSSIBLE" << endl;
 		}
 		else
 		{
 			fout << "Case #" << zz << ": " << result << endl;
 		}
 		
 	}
 
 	return 0;
 }
