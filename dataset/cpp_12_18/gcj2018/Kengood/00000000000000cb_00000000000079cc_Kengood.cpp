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
		double in;
		cin >> in;
		double sq2 = 1.414213; //sqrt(2.0);
		double deg90 = acos(0.0);
		double f5 = acos(0.0) / 2.0;

		double t = in -1.0;
		double deg = f5 / (sq2 -1.0) * t;

		double as = sin(deg90 * 4 - deg) *.5;
		if (abs(as) < 1e-7)
			as = 0.0;

		printf("%0.10lf %0.10lf %0.10lf\n", sin(deg90 - deg)*.5, cos(deg90 - deg) *.5,0.0);
		printf("%0.10lf %0.10lf %0.10lf\n",  as, cos(deg90*4 - deg) *.5,0.0);
		printf("%0.10lf %0.10lf %0.10lf\n", 0.0,0.0,0.5);

		
	}

	return 0;
}

