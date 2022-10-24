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

struct P
{
	P(int a=0, int b=0) : x(a), y(b) {}

	int x, y;
};

static P operator+(const P& lhs, const P& rhs) { return P(lhs.x + rhs.x, lhs.y + rhs.y); }
static P operator-(const P& lhs, const P& rhs) { return P(lhs.x - rhs.x, lhs.y - rhs.y); }

namespace
{
	int N;
	P p[1005];
	double z[1005];
	int ret[1005];

	bool ok()
	{
		for (int ii = 3; ii < N; ++ii)
		{
			int i = ret[ii], a = ret[ii - 2], b = ret[ii - 1];
			P pA = p[a] - p[i];
			P pB = p[b] - p[i];

			double zA = z[a] - z[i], zB = z[b] - z[i];

			double dz_x;
			if (pA.y == 0)
			{
				dz_x = zA / pA.x;
			}
			else if (pB.y == 0)
			{
				dz_x = zB / pB.x;
			}
			else
			{
				double nb = -double(pA.y) / double(pB.y);
				double dx = double(pA.x) + nb * double(pB.x);
				double dz = zA + nb * zB;
				dz_x = dz / dx;
			}

			double dz_y;
			if (pA.y == 0)
			{
				double dz = zB - dz_x * double(pB.x);
				dz_y = dz / double(pB.y);
			}
			else
			{
				double dz = zA - dz_x * double(pA.x);
				dz_y = dz / double(pA.y);
			}

			for (int jj = 0; jj + 3 <= ii; ++jj)
			{
				int j = ret[jj];

				P pJ = p[j] - p[i];
				double zJ = z[j] - z[i];

				double real_dz = dz_x * double(pJ.x) + dz_y * double(pJ.y);
				if (real_dz <= zJ)
					return false;
			}
		}

		return true;
	}
}

//int main18R3_C()
int main()
{
	unsigned int numberOfCases;
	cin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			int x, y;
			cin >> x >> y;
			p[i] = P(x, y);
			cin >> z[i];
		}

		for (int i = 0; i < N; ++i)
			ret[i] = i;

		while (!ok())
		{
			next_permutation(ret, ret + N);
		}

		cout << "Case #" << zz << ":";
		for (int i = 0; i < N; ++i)
		{
			cout << " " << (ret[i] + 1);
		}
		cout << endl;
	}

	return 0;
}
