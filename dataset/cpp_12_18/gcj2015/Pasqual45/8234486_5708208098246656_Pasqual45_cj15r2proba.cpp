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
 	int R, C;
 	int loX[101], hiX[101], loY[101], hiY[101];
 	string g[101];
 
 	int solve()
 	{
 		fill(loX, loX + 101, 999);
 		fill(loY, loY + 101, 999);
 		fill(hiX, hiX + 101, -1);
 		fill(hiY, hiY + 101, -1);
 
 		for (int i = 0; i < R; ++i)
 		{
 			for (int j = 0; j < C; ++j)
 			{
 				if (g[i][j] != '.')
 				{
 					loX[i] = min(loX[i], j);
 					hiX[i] = max(hiX[i], j);
 					loY[j] = min(loY[j], i);
 					hiY[j] = max(hiY[j], i);
 				}
 			}
 		}
 
 		int ret = 0;
 		for (int i = 0; i < R; ++i)
 		{
 			for (int j = 0; j < C; ++j)
 			{
 				if (g[i][j] != '.')
 				{
 					if (loX[i] == hiX[i] && loY[j] == hiY[j])
 						return -1;
 
 					bool add = false;
 					char c = g[i][j];
 					if (loX[i] == j && c == '<')
 						add = true;
 					if (hiX[i] == j && c == '>')
 						add = true;
 					if (loY[j] == i && c == '^')
 						add = true;
 					if (hiY[j] == i && c == 'v')
 						add = true;
 
 					if (add)
 						++ret;
 				}
 			}
 		}
 
 		return ret;
 	}
 }
 //int main15R2_A()
 int main()
 {
 	ifstream fin("A-small-attempt0.in");
 	ofstream fout("A-small-attempt0.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		fin >> R >> C;
 		fill(g, g + 101, "");
 		for (int i = 0; i < R; ++i)
 		{
 			fin >> g[i];
 		}
 
 		int result = solve();
 		fout << "Case #" << zz << ": ";
 		if (result < 0)
 			fout << "IMPOSSIBLE";
 		else
 			fout << result;
 		fout << endl;
 	}
 
 	return 0;
 }
