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
	int T, a, b, n;
	char s[30];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &a, &b);
		++a;
		scanf("%d", &n);
		while (true)
		{
			printf("%d\n", (a + b) / 2);
			fflush(stdout);
			scanf("%s", &s);
			if (s[0] == 'C')
				break;
			if (s[4] == 'B')
				b = (a + b) / 2 - 1;
			else
				a = (a + b) / 2 + 1;
		}
	}
	return 0;
}