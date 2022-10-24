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
 	int M, N;
 	string s[8];
 	int assignment[8];
 
 	bool ok()
 	{
 		for (int i = 0; i < N; ++i)
 			if (find(assignment, assignment + M, i) == assignment + M)
 				return false;
 		return true;
 	}
 
 	bool inc()
 	{
 		int loc = 0;
 		while (loc < M && assignment[loc] == N - 1)
 			assignment[loc++] = 0;
 
 		if (loc == M) return false;
 		++assignment[loc];
 		return true;
 	}
 
 	int count()
 	{
 		int ret = 0;
 
 		for (int i = 0; i < N; ++i)
 		{
 			set<string> trie;
 			trie.insert("");
 			for (int j = 0; j < M; ++j)
 			{
 				if (assignment[j] == i)
 				{
 					const string& ss = s[j];
 					for (int k = 1; k <= ss.size(); ++k)
 						trie.insert(ss.substr(0, k));
 				}
 			}
 
 			ret += trie.size();
 		}
 
 		return ret;
 	}
 }
 
 //int main14R2_D()
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
 		memset(assignment, 0, sizeof(assignment));
 		fin >> M >> N;
 		for (int i = 0; i < M; ++i)
 			fin >> s[i];
 
 		int result = 0;
 		int worst = 0;
 		do
 		{
 			if (!ok()) continue;
 			int next = count();
 			if (next > worst)
 				worst = next, result = 0;
 
 			if (next == worst)
 				++result;
 		} while (inc());
 
 		fout << "Case #" << zz << ": " << worst << " " << result << endl;
 	}
 
 	return 0;
 }
