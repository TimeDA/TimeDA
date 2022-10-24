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


//int main18R3_A()
int main()
{


	unsigned int numberOfCases;
	cin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int n;
		cin >> n;

		ll minX = 999999999999LL;
		ll minY = minX, maxX = -minX, maxY = -minX;

		for (int i = 0; i < n; ++i)
		{
			ll x, y;
			cin >> x >> y;
			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, x);
			maxY = max(maxY, y);
		}

		ll rx = (maxX-minX+1)/2;
		ll ry = (maxY - minY + 1) / 2;
		ll result = max(rx, ry);
		cout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
