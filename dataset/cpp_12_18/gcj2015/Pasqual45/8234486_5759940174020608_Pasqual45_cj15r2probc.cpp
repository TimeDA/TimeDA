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
 	map<string, int> msi;
 
 	vector<int> getvs(string s)
 	{
 		vector<int> ret;
 		int pos = s.find(' ');
 
 		string ss = s.substr(0, pos);
 		auto a = msi.insert(make_pair(ss, msi.size()));
 		ret.push_back(a.first->second);
 
 		while (pos != (int)string::npos)
 		{
 			s.erase(s.begin(), s.begin() + pos + 1);
 			pos = s.find(' ');
 			ss = s.substr(0, pos);
 			a = msi.insert(make_pair(ss, msi.size()));
 			ret.push_back(a.first->second);
 		}
 
 		return ret;
 	}
 
 	bool test[2][1500];
 	void add(const vector<int>& v, int idx)
 	{
 		for (int i = 0; i < v.size(); ++i)
 		{
 			test[idx][v[i]] = true;
 		}
 	}
 
 	int res()
 	{
 		int ret = 0;
 		for (int i = 0; i < 1500; ++i)
 		{
 			if (test[0][i] && test[1][i])
 				++ret;
 		}
 
 		return ret;
 	}
 }
 //int main15R2_C()
 int main()
 {
 	ifstream fin("C-small-attempt0.in");
 	ofstream fout("C-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
 	{
 		msi.clear();
 
 		int n;
 		fin >> n;
 		string s;
 		getline(fin, s);
 		getline(fin, s);
 		vector<int> v1 = getvs(s);
 		getline(fin, s);
 		vector<int> v2 = getvs(s);
 
 		vector<vector<int> > vv(n - 2);
 		for (int i = 0; i < n - 2; ++i)
 		{
 			getline(fin, s);
 			vv[i] = getvs(s);
 		}
 
 		int result = 999999999;
 		for (int mask = 0; mask == 0 || (n > 2 && (mask < (1 << (n - 2)))); ++mask)
 		{
 			memset(test, 0, sizeof(test));
 			add(v1, 0);
 			add(v2, 1);
 			for (int i = 0; i < n - 2; ++i)
 			{
 				int x = ((1 << i)&mask) ? 1 : 0;
 				add(vv[i], x);
 			}
 
 			int next = res();
 			result = min(result, next);
 		}
 
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }
