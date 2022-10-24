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

int cal(string &in)
{
	int res = 0;
	int cur = 1;

	for (char c : in)
	{
		if (c == 'S')
			res += cur;
		else
			cur <<= 1;
	}

	return res;
}

int main(int __an, char **__ag)
{
	int Case, cases = 0;
	scanf("%d", &Case);
	while (Case--)
	{
		printf("Case #%d: ", ++cases);
		int d;
		string in;
		cin >> d >> in;

		if (count(in.begin(), in.end(), 'S') > d)
		{
			puts("IMPOSSIBLE");
		}
		else
		{

			int ans = 0;
			while (cal(in) > d)
			{
				string ll = in;
				char ok = 0;
				for (int i = in.size()-1; i--;)
				{
					if (in[i] == 'C' && in[i + 1] == 'S')
					{
						swap(in[i], in[i + 1]);
						break;
					}
				}
				++ans;
			}

			printf("%d\n", ans);
		}


	}

	return 0;
}

