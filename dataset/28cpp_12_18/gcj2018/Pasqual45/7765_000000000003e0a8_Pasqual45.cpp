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
typedef unsigned long long ull;
#define mp make_pair

#define fin cin

const static ull big = 10000000000000000ULL;

//int main18R1C_C()
int main()
{
	//ifstream fin("test.in");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int N;
	vector<ull> w, v;
	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		fin >> N;
		w.resize(N);
		v.assign(N+1, big);
		v[0] = 0;
		for (int i = 0; i < N; ++i)
		{
			fin >> w[i];
		}

		int len(0);
		for (int i = 0; i < N; ++i)
		{
			ull maxWeight = w[i] * 6;

			int firstTry = distance(v.begin(), upper_bound(v.begin(), v.begin() + len + 1, maxWeight)) - 1;
			for (int j = firstTry; j >= 0; --j)
			{
				//if (v[j] <= maxWeight)
				v[j + 1] = min(v[j + 1], v[j] + w[i]);
			}

			if (v[len+1] < big)
				++len;
		}

		cout << "Case #" << zz << ": " << len << endl;
	}

	return 0;
}
