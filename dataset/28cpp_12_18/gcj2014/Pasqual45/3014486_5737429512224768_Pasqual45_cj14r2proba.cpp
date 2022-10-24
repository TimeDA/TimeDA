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
 	int s[10001];
 }
 
 
 //int main14R2_A()
 int main()
 {
 	ifstream fin("A-small-attempt0.in");
 	ofstream fout("A-small-attempt0.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		int N, X;
 		fin >> N >> X;
 		for (int i = 0; i < N; ++i)
 			fin >> s[i];
 
 		sort(s, s + N);
 		int result = 0;
 		int a = 0, b = N - 1;
 		while (a < b)
 		{
 			if (s[a] + s[b] <= X)
 				++a;
 			--b;
 			++result;
 		}
 
 		if (a==b)
 			++result;
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
