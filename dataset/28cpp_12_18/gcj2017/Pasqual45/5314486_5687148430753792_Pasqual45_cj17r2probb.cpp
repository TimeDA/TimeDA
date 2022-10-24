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
 
 //int main17R2_B()
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
 		int N, C, M;
 		fin >> N >> C >> M;
 		vector<vector<int> > vv(C);
 		for (int i = 0; i < M; ++i)
 		{
 			int P, B;
 			fin >> P >> B;
 			vv[B-1].push_back(P-1);
 		}
 
 		for (auto& v : vv)
 		{
 			sort(v.begin(), v.end());
 		}
 
 		const vector<int>& v = vv[0];
 		const vector<int>& w = vv[1];
 		int result = max(v.size(), w.size());
 		result = max(result, count(v.begin(), v.end(), 0) + count(w.begin(), w.end(), 0));
 
 		int highest(0);
 		for (int i = 0; i < N; ++i)
 		{
 			int next = count(v.begin(), v.end(), i) + count(w.begin(), w.end(), i);
 			highest = max(highest, next);
 		}
 
 		int promos = max(0, highest - result);
 
 		fout << "Case #" << zz << ": " << result << " " << promos << endl;
 	}
 
 	return 0;
 }
