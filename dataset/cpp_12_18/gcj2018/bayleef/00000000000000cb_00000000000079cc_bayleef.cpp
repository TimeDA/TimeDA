#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		double x;
		scanf("%lf", &x);
		x /= sqrt(2.0);
		if (x > 1)x = 1;
		x = asin(x);
		x -= M_PI / 4;
		if (x < 0)x = 0;
		printf("Case #%d:\n", ts);
		printf("%.12lf %.12lf 0\n", cos(x) / 2, sin(x) / 2);
		printf("%.12lf %.12lf 0\n", -sin(x) / 2, cos(x) / 2);
		puts("0 0 0.5");
	}
	return 0;
}