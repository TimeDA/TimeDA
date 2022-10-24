#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char s[50];

int get_current_power(const string& P)
{
	int current_power = 1;
	int total_damage = 0;

	for (int i = 0; i < P.size(); ++i)
	{
		if (P[i] == 'C')
		{
			current_power *= 2;
		}
		else if (P[i] == 'S')
		{
			total_damage += current_power;
		}
	}
	return total_damage;
}

void solve(int D, string P)
{
	int count_s = 0;
	for (int i = 0; i < P.size(); ++i)
		if (P[i] == 'S') count_s++;

	if (D < count_s)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	int answer = 0;
	while (get_current_power(P) > D)
	{
		for (int i = P.size() - 2; i >= 0; --i)
		{
			if (P[i] == 'C' && P[i + 1] == 'S')
			{
				P[i] = 'S';
				P[i + 1] = 'C';
				answer++;
				break;
			}
		}
	}
	printf("%d\n", answer);
}

int main()
{
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn)
	{
		int D;
		string P;
		cin >> D >> P;
		printf("Case #%d: ", cn);
		solve(D, P);
	}
}