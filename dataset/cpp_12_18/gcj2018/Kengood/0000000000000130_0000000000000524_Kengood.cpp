#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;

int main(int __an, char **__ag)
{
	int Case, cases = 0;
	scanf("%d", &Case);
	while (Case--)
	{
		printf("Case #%d:", ++cases);
		double distance;
		int n;
		cin >> distance >> n;
		vector< pair<double, double> > hh(n);
		double aa = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> hh[i].first >> hh[i].second;
			double remain = distance - hh[i].first;
			double hour = remain / hh[i].second;
			aa = max(aa, hour);
		}
		printf(" %.8lf\n", distance / aa);

	}

	return 0;
}

