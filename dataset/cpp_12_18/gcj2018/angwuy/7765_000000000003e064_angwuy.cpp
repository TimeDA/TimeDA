#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

const int MAXN = 2010;
const int MAXM = 20;

int n, l;
string a[MAXN];
int c[MAXN][MAXM];
map<string, int> h;


void init()
{
	cin >> n >> l;
	memset(c, 0, sizeof(c));
	h.clear();
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		h[a[i]] = 1;
		for (int j = 0; j < l; ++j)
			c[a[i][j]][j] = 1;
	}
}

void solve()
{
	for (int i = 1; i <= n; ++i)
	for (int j = 0; j < l; ++j)
	{
		char tmp = a[i][j];
		for (a[i][j] = 'A'; a[i][j] <= 'Z'; ++a[i][j])
		if (c[a[i][j]][j] > 0)
		if (h[a[i]] == 0)
		{
			cout << a[i];
			cout << endl;
			return;
		}
		a[i][j] = tmp;
	}
	cout << "-" << endl;
}


int main()
{
	int tt;
	cin >> tt;
	for (int ii = 1; ii <= tt; ++ii)
	{
		init();
		cout << "Case #" << ii << ": ";
		solve();
	}
	return 0;
}