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

namespace
{
	int lower, total;
	vector<int> v;

	bool can(int _n)
	{
		int n = _n;
		v.assign(1, 0);

		int totalCost(0), lowCost(0);
		for (int cost = 1; n > 0; ++cost)
		{
			int num = min(cost + 1, n);
			n -= num;
			totalCost += num * cost;
			lowCost += (num * (num - 1)) / 2;

			v.push_back(num);
		}

		while (true)
		{
			if (totalCost > total)
				return false;

			if (lowCost <= lower)
				return true;

			// Need to move something
			if (v.back() != 0)
				v.push_back(0);

			int best(-1), bestIdx;
			for (int i = 1; i + 1 < v.size(); ++i)
			{
				int cur = v[i] - v[i + 1];
				if (cur > best || (cur >= best && v[i] > 1))
				{
					bestIdx = i;
					best = cur;
				}
			}

			++totalCost;
			lowCost -= (best - 1);
			--v[bestIdx];
			++v[bestIdx+1];
		}
	}
}

//int main18R2_B()
int main()
{
	//ifstream fin("test.in");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int x, y;
		fin >> x >> y;
		total = x + y;
		lower = min(x, y);

		int hi = 1, lo = 0;
		while (can(hi))
		{
			lo = hi; hi *= 2;
		}

		while (hi - lo > 1)
		{
			int mid = (hi + lo) / 2;
			if (can(mid))
			{
				lo = mid;
			}
			else
			{
				hi = mid;
			}
		}

		cout << "Case #" << zz << ": " << lo << endl;
	}

	return 0;
}
