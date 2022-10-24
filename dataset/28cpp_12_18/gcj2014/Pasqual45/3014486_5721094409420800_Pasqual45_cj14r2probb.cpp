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
 
 //int main14R2_B()
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
 		int N;
 		fin >> N;
 
 		vector<int> v(N);
 		for (int i = 0; i < N; ++i)
 			fin >> v[i];
 
 		int result = 0;
 		while (v.size() > 1)
 		{
 			int idx = min_element(v.begin(), v.end()) - v.begin();
 			int len = min<int>(idx, v.size() - idx - 1);
 			result += len;
 			v.erase(v.begin() + idx);
 		}
 
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
