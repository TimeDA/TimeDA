#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

int calc()
{
	int N;
	cin >> N;
	vector<int> v[2];
	for (int i=0; i<N; ++i)
	{
		int x;
		cin >> x;
		v[i&1].push_back(x);
	}


	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	for (int i=0; i<v[1].size(); ++i)
	{
		if (v[1][i] < v[0][i])
			return i*2;

		if (i+1 < v[0].size() && v[0][i+1] < v[1][i])
			return i*2 + 1;

	}

	return -1;
}

int main()
{
	unsigned int numberOfCases;
	cin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int ret = calc();
		if (ret < 0)
		{
			cout << "Case #" << zz << ": " << "OK" << endl;
		}
		else
		{
			cout << "Case #" << zz << ": " << ret << endl;
		}
		
	}

	return 0;
}
