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
 	double p[202];
 	double g[202];
 }
 
 //int main16R2_B()
 int main()
 {
 	ifstream fin("B-small-attempt0.in");
 	ofstream fout("B-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	fout << std::setprecision(12);
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		int n, k;
 		fin >> n >> k;
 		for (int i = 0; i < n; ++i)
 		{
 			fin >> p[i];
 		}
 
 		sort(p, p + n);
 
 		double ret(0.0);
 		for (int m = 0; m < (1 << n); ++m)
 		{
 			if (bitset<32>(m).count() != k) continue;
 			memset(g, 0, sizeof(g));
 			g[0] = 1.0;
 			
 			for (int i = 0; i < n; ++i)
 			{
 				if (m & (1 << i))
 				{
 					for (int j = k; j >= 0; --j)
 					{
 						g[j + 1] += g[j] * p[i];
 						g[j] *= (1 - p[i]);
 					}
 				}
 			}
 
 			ret = max(ret, g[k/2]);
 		}
 
 		fout << "Case #" << zz << ": " << ret << endl;
 	}
 
 	return 0;
 }
