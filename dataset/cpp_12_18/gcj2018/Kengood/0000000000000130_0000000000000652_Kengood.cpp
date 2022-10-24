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
		printf("Case #%d: ", ++cases);
		long long n, k;
		cin >> n >> k;

		//use binary of k
		bool isEven = false;
		for (long long bit = 0; k >= (1LL << bit); ++bit)
		{
			long long b = k & (1LL << bit);
			b >>= bit;

			isEven = !(n & 1);

			n = (n-1) / 2;

			if (isEven && b == 0)
				++n;

		}

		cout << n + isEven << " " << n << endl;
	}

	return 0;
}

