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
 	bool g[32][32];
 	bool h[32][32];
 
 	int order[32];
 	int used[32];
 
 	bool can(int cur)
 	{
 		if (cur == n) return true;
 
 		int idx = order[cur];
 		bool anyOK = false;
 		for (int j = 0; j < n; ++j)
 		{
 			if (h[idx][j] && !used[j])
 			{
 				anyOK = true;
 				used[j] = true;
 				bool stillOK = can(cur + 1);
 				used[j] = false;
 
 				if (!stillOK) return false;
 			}
 		}
 
 		return anyOK;
 	}
 }
 
 //int main16R2_D()
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
 		fin >> n;
 
 		vector<pii> v;
 		for (int i = 0; i < n; ++i)
 		{
 			string s;
 			fin >> s;
 			for (int j = 0; j < n; ++j)
 			{
 				g[i][j] = s[j] == '1';
 				if (!g[i][j])
 					v.push_back(make_pair(i, j));
 			}
 		}
 
 		int z = v.size();
 		int result = z;
 		for (int m = 0; m < (1 << z); ++m)
 		{
 			if (bitset<32>(m).count() >= result) continue;
 			memcpy(h, g, sizeof(h));
 			for (int i = 0; i < z; ++i)
 			{
 				if (m & (1 << i))
 				{
 					h[v[i].first][v[i].second] = true;
 				}
 			}
 
 			bool ok = true;
 			for (int i = 0; i < n; ++i)
 				order[i] = i;
 
 			do
 			{
 				memset(used, 0, sizeof(used));
 
 				ok = ok && can(0);
 			} while (next_permutation(order, order + n));
 
 			if (ok)
 				result = min<int>(result, bitset<32>(m).count());
 		}
 
 
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
