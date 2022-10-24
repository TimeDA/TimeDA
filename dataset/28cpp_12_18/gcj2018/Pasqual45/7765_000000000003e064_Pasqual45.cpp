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

#define fin cin

//int main18R1C_A()
int main()
{
	//ifstream fin("test.in");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int N,L;
		fin >> N >> L;
		vector<string> v(N);
		vector<vector<char> > vc(L);
		for (int i = 0; i < N; ++i)
		{
			fin >> v[i];
			for (int j = 0; j < L; ++j)
			{
				vc[j].push_back(v[i][j]);
			}
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		int possible(1);
		for (int i = 0; i < L; ++i)
		{
			sort(vc[i].begin(), vc[i].end());
			vc[i].erase(unique(vc[i].begin(), vc[i].end()), vc[i].end());

			possible = min<int>(5000, possible * vc[i].size());
		}

		string result = "-";
		if (v.size() < possible)
		{
			result.resize(L);
			vector<int> vi(L, 0);
			int idxV(0);
			while (true)
			{
				for (int i = 0; i < L; ++i)
				{
					result[i] = vc[i][vi[i]];
				}

				while (idxV < v.size() && v[idxV] < result)
					++idxV;

				if (idxV == v.size() || v[idxV] != result)
					break;


				for (int i = L - 1; i >= 0; --i)
				{
					if (vi[i] + 1 < vc[i].size())
					{
						++vi[i];
						break;
					}
					else
					{
						vi[i] = 0;
					}
				}
			}
		}

		cout << "Case #" << zz << ": " << result << endl;
	}


	return 0;
}
