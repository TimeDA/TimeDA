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
		int n;
		cin >> n;
		vector<int> odd, even;
		for (int i = 0; i < n; ++i)
		{
			int t; cin >> t;
			if (i & 1)
				even.push_back(t);
			else
				odd.push_back(t);
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());

		int prev = -1111;
		char ok = 1;
		for (int i = 0; i < n; ++i)
		{
			int t;
			if (i & 1)
				t = even[i / 2];
			else
				t = odd[i / 2];
			//cout << t << " ";
			if (prev > t)
			{
				printf("%d\n", i-1);
				ok = 0;
				break;
			}
			prev = t;
		}

		if (ok)
			puts("OK");



	}

	return 0;
}

