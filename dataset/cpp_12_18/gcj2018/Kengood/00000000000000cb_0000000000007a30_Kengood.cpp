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


int allDone(set<pair<int, int >> farm, int x, int y)
{
	int aa = 0;
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			if (farm.find(make_pair(x + i, y + j)) != farm.end())
				++aa;

		}
	}
	return aa;
}

int main(int __an, char **__ag)
{
	int Case, cases = 0;
	scanf("%d", &Case);
	while (Case--)
	{
		int A; cin >> A;
		set<pair<int, int >> farm;
		vector< pair<int, int> > r;
		if (A == 20)
		{						
			r = { make_pair(2,2),make_pair(4,2),make_pair(2,3),make_pair(4,3), };
		}
		else if (A == 200)
		{
			for (int i = 0; i < 16; ++i)
				r.push_back({2+i*3,2});

			r.push_back({ 49,2 });
			for (int i = 0; i < 16; ++i)
				r.push_back({ 2 + i * 3,3 });

			r.push_back({ 49,3 });
		}
		else
		{
			return 1;
		}

		
		int cur = 0;
		char dd = 0; int aa = 0;
		while (!dd)
		{
			//cout << "---" << ++aa << " " << A << endl;

			cout << r[cur].first << " " << r[cur].second << endl;
			int resA, resB;
			//resA = r[cur].first-1 + rand()%3;
			//resB = r[cur].second-1 + rand() % 3;
			 cin >> resA >> resB;

			if (resA == 0)
				dd = 1;
			else if (resA == -1)
				return 1;
			else
			{
				if (farm.find({ resA,resB }) == farm.end())
				{
					farm.insert({ resA,resB });
					--A;
				}
				if (allDone(farm, r[cur].first, r[cur].second) >= 9)
					++cur;
			}
		}
	}

	return 0;
}

