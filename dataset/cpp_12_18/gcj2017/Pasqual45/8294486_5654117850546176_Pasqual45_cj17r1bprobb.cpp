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
 
 //int main17R1B_B()
 int main()
 {
 	const static char v[] = { 'R', 'O', 'Y', 'G', 'B', 'V' };
 
 	ifstream fin("B-small-attempt0.in");
 	ofstream fout("B-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		int n, a, b, c, d, e, f;
 		fin >> n >> a >> b >> c >> d >> e >> f;
 
 		int big = max(a, max(c, e));
 		if (big * 2 > n)
 		{
 			fout << "Case #" << zz << ": " << "IMPOSSIBLE" << endl;
 		}
 		else
 		{
 			string s;
 			if (big == a)
 				s += v[0], --a;
 			else if (big == c)
 				s += v[2], --c;
 			else
 				s += v[4], --e;
 
 			while (a + c + e > 0)
 			{
 				if (s.back() == v[0])
 				{
 					if (c > e || (c == e && s[0] == v[2]))
 						s += v[2], --c;
 					else
 						s += v[4], --e;
 				}
 				else if (s.back() == v[2])
 				{
 					if (a > e || (a == e && s[0] == v[0]))
 						s += v[0], --a;
 					else
 						s += v[4], --e;
 				}
 				else if(s.back() == v[4])
 				{
 					if (a > c || (a == c && s[0] == v[0]))
 						s += v[0], --a;
 					else
 						s += v[2], --c;
 				}
 			}
 
 			fout << "Case #" << zz << ": " << s << endl;
 		}
 	}
 
 	return 0;
 }
