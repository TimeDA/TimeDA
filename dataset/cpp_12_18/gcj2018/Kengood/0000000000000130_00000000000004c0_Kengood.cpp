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

		int n; cin >> n;
		vector<pair<int,char>> a(n);
		int total = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i].first;
			total += a[i].first;
			a[i].second = 'A' + i;
		}

		while (total)
		{
			sort(a.begin(), a.end());
			if (a.back().first == 0) break;
			if (a[n - 2].first == 0)
			{
				while (a[n - 1].first >= 2)
				{
					a[n - 1].first -= 2;
					cout << " " << a[n - 1].second << a[n - 1].second;
				}
				if (a[n - 1].first >= 1)
					cout << " " << a[n - 1].second;
				break;
			}
			else
			{
				int tt = min(2, a[n - 1].first);
				if (a[n - 2].first > (total- tt) / 2)
				{
					total -= 2;
					--a[n - 2].first;
					--a[n - 1].first;
					cout << " " << a[n - 1].second << a[n - 2].second;
				}
				else
				{
					a[n - 1].first -= tt;
					total -= tt;

					cout << " ";
					while(tt--)
						cout << a[n - 1].second;
				}
			}
		}

		puts("");
	}

	return 0;
}

