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
 	int P;
 	ll e[10001], f[10001];
 }
 
 //int main15R3_D()
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
 		map<ll, ll> target, found;
 
 		fin >> P;
 		for (int i = 0; i < P; ++i)
 			fin >> e[i];
 		for (int i = 0; i < P; ++i)
 		{
 			fin >> f[i];
 			target[e[i]] = f[i];
 		}
 
 		vector<ll> v;
 		int mult = 1;
 		while (mult != target[0])
 		{
 			v.push_back(0);
 			mult *= 2;
 		}
 
 		for (auto& p : target)
 		{
 			p.second /= mult;
 		}
 
 		found[0] = 1;
 		map<ll, ll>::const_iterator it = target.begin();
 		++it;
 		while (it != target.end())
 		{
 			ll number = it->first;
 			ll extra = it->second - (found.count(number) == 0 ? 0 : found[number]);
 			while (extra > 0)
 			{
 				v.push_back(number);
 				for (map<ll, ll>::reverse_iterator it2 = found.rbegin(); it2 != found.rend(); ++it2)
 				{
 					found[it2->first + number] += it2->second;
 				}
 
 				--extra;
 			}
 
 			++it;
 		}
 
 		int result = 999;
 		fout << "Case #" << zz << ": " << v[0];
 		for (int i = 1; i < v.size(); ++i)
 		{
 			fout << " " << v[i];
 		}
 
 		fout << endl;
 	}
 
 	return 0;
 }
