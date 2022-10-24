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
 
 //int main17RQ_B()
 int main()
 {
 	ifstream fin("B-small-attempt0.in");
 	ofstream fout("B-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		string s;
 		fin >> s;
 
 		if (!is_sorted(s.begin(), s.end()))
 		{
 			int i(0);
 			while (s[i+1] >= s[i])
 				++i;
 
 			while (i > 0 && s[i] == s[i - 1])
 				--i;
 
 			if (i == 0 && s[i] == '1')
 			{
 				s.assign(s.size() - 1, '9');
 			}
 			else
 			{
 				--s[i];
 				fill(s.begin() + i + 1, s.end(), '9');
 			}
 		}
 
 		fout << "Case #" << zz << ": " << s << endl;
 	}
 
 	return 0;
 }
