#include<iostream>
#include<string>
using namespace std;


int main()
{
	int cases; cin >> cases;
	while (cases--)
	{

		int a, b;
		int n;
		cin >> a >> b;
		cin >> n;
		while (n--)
		{
			cout << (b + a + 1) / 2 << endl;
			string ans;
			cin >> ans;
			if (ans == "TOO_BIG")
				b = (b + a) / 2;
			else if (ans == "TOO_SMALL")
				a = (b + a) / 2;
			else
				break;
		}
	}


	return 0;
}