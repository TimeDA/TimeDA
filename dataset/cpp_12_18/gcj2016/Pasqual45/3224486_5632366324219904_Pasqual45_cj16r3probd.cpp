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
 
 //int main16R3_D()
 int main()
 {
 	ifstream fin("D-small-attempt2.in");
 	ofstream fout("D-small-attempt2.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		int N, L;
 		fin >> N >> L;
 		vector<string> v(N);
 		for (int i = 0; i < N; ++i)
 			fin >> v[i];
 
 		string B;
 		fin >> B;
 
 		string result;
 		if (find(v.begin(), v.end(), B) != v.end())
 		{
 			result = "IMPOSSIBLE";
 		}
 		else
 		{
 			result.append("0");
 			for (int i = 1; i < L; ++i)
 				result.append("1");
 
 			result.append(" ");
 			for (int i = 0; i < L; ++i)
 				result.append("0?");
 		}
 
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
