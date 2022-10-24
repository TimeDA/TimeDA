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
 typedef pair<ll, ll> pll;
 #define mp make_pair
 
 //int main17R1B_A()
 int main()
 {
 	ifstream fin("A-small-attempt0.in");
 	ofstream fout("A-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 	fout << fixed << setprecision(9);
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		ll D, N;
 		fin >> D >> N;
 		vector<pll> v(N);
 		for (int i = 0; i < N; ++i)
 			fin >> v[i].first >> v[i].second;
 
 		double maxT(0.0);
 		for (int i = 0; i < N; ++i)
 		{
 			double d = D - v[i].first;
 			double t = d / v[i].second;
 			maxT = max(t, maxT);
 		}
 
 		double ret = D / maxT;
 		
 		fout << "Case #" << zz << ": " << ret << endl;
 	}
 
 	return 0;
 }
