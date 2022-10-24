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

//int main18R1C_B()
int main()
{
	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int N;
		fin >> N;

		vector<int> cnt(N, 0);
		vector<bool> sold(N, false);
		for (int i = 0; i < N; ++i)
		{
			int which = -1, total = 999;

			int D, x;
			fin >> D;
			for (int j = 0; j < D; ++j)
			{
				fin >> x;
				if (!sold[x] && cnt[x] < total)
				{
					which = x;
					total = cnt[x];
				}

				++cnt[x];
			}

			cout << which << endl;
			if (which >= 0)
			{
				sold[which] = true;
			}
		}
	}

	return 0;
}
