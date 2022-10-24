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
 using namespace std;
 typedef pair<int, int> pii;
 typedef pair<pii, int> trip;
 typedef long long ll;
 #define mp make_pair
 
 namespace
 {
 	struct lessPair
 	{
 		bool operator()(const trip& l, const trip& r) const
 		{
 			return l.first.first * r.first.second < l.first.second * r.first.first;
 		}
 	};
 }
 
 //int main12R3A()
 int main()
 {
 	ifstream fin("A-small-attempt0.in");
 	ofstream fout("A-small-attempt0.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	int N;
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		fin >> N;
 		vector<trip> v(N);
 		for (int i=0; i<N; ++i)
 			fin >> v[i].first.first;
 
 		for (int i=0; i<N; ++i)
 		{
 			fin >> v[i].first.second;
 		}
 
 		for (int i=0; i<N; ++i)
 			v[i].second = i;
 
 		stable_sort(v.begin(), v.end(), lessPair());
 		fout << "Case #" << zz << ": ";
 		for (int i=0; i<N; ++i)
 		{
 			fout << v[i].second;
 			if (i+1==N)
 				fout << endl;
 			else
 				fout << " ";
 		}
 	}
 
 	return 0;
 }