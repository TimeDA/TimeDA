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
 	int solve(int c, int last)
 	{
 		if (c < 0) return 0;
 		if (c == 0) return 1;
 
 		int ret = 0;
 		if (last != 3)
 			ret += solve(c - 2, 3);
 		if (last != 2)
 			ret += solve(c - 1, 2);
 
 		return ret;
 	}
 
 	int solve6(int c, int last, bool fixed)
 	{
 		if (c < 0) return 0;
 		if (c == 0) return 1;
 
 		int ret = 0;
 		if (last != 3)
 			ret += solve6(c - 2, 3, fixed);
 		if (last != 2)
 		{
 			ret += solve6(c - 1, 2, fixed);
 
 			int mult = fixed ? 6 : 1;
 			ret += mult * solve6(c - 2, 2, true);
 		}
 
 		return ret;
 	}
 }
 
 //int main15R2_D()
 int main()
 {
 	ifstream fin("D-small-attempt0.in");
 	ofstream fout("D-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		int result = 0;
 		int r, c;
 		fin >> r >> c;
 		if ((c % 6) == 0)
 		{
 			result = solve6(r, -1, false);
 		}
 		else
 		{
 			result = solve(r, -1);
 		}
 
 		
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
