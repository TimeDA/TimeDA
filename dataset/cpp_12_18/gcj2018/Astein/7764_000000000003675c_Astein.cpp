#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int M;
vector<pair<int, int>> vp;
vector<long long> GG;
vector<int> cycle;

bool can_make(int key, long long v)
{
	long long vv = min(GG[key], v);
	GG[key] -= vv;
	v -= vv;

	if (v == 0)
	{
		cycle[key] = 0;
		return true;
	}

	if (cycle[key] == 1)
	{
		return false;
	}

	cycle[key] = 1;

	bool left = can_make(vp[key].first, v);
	bool right = can_make(vp[key].second, v);

	if (left && right)
	{
		cycle[key] = 0;
		return true;
	}

	return false;
}

int main()
{
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn)
	{
		cin >> M;
		vp.resize(M);
		for (int i = 0; i < M; ++i)
		{
			cin >> vp[i].first >> vp[i].second;
			vp[i].first--;
			vp[i].second--;
		}

		long long left = 0, right = 0;

		vector<long long> G(M);
		for (int i = 0; i < M; ++i)
		{
			cin >> G[i];
			right += G[i];
		}
		left = G[0];

		long long ret = left;
		while (left <= right)
		{
			long long mid = (left + right) / 2;
			GG = G;
			cycle.assign(M, 0);
			
			if (can_make(0, mid))
			{
				ret = mid;
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		cout << "Case #" << cn << ": " << ret << endl;
	}
}