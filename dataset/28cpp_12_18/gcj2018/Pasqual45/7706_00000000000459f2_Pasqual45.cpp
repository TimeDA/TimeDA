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

//int main18R2_A()
int main()
{
	//ifstream fin("test.in");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int c;
		fin >> c;
		vector<int> v(c);
		for (int i = 0; i < c; ++i)
			fin >> v[i];

		if (v[0] == 0 || v.back() == 0)
		{
			cout << "Case #" << zz << ": " << "IMPOSSIBLE" << endl;
		}
		else
		{
			int result = 1;

			int idx(0);
			vector<int> to(c);
			for (int i = 0; i < c; ++i)
			{
				result = max(result, abs(i - idx) + 1);

				while (v[i]-- > 0)
				{
					to[idx] = i;
					++idx;
				}
			}

			vector<string> v(result, string(c, '.'));
			for (int i = 0; i < c; ++i)
			{
				int dist = abs(i - to[i]);
				for (int j = 0; j < dist; ++j)
				{
					if (to[i] > i)
						v[j][i+j] = '\\';
					else
						v[j][i-j] = '/';
				}
			}

			cout << "Case #" << zz << ": " << v.size() << endl;
			for (int i = 0; i < result; ++i)
			{
				cout << v[i] << endl;
			}
		}
	}

	return 0;
}
