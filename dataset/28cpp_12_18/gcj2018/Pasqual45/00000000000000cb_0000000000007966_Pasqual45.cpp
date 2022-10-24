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

ll eval(const string& s)
{
    ll ret(0), mult(1);
    for (int i=0; i<s.size(); ++i)
    {
        if (s[i] == 'S')
            ret += mult;
        else
            mult *= 2;
    }
    
    return ret;
}

int calc()
{
	ll D;
    string s;
    cin >> D >> s;
    while (!s.empty() & s[s.size() - 1] == 'C')
        s.resize(s.size()-1);
        
    int numS = count(s.begin(), s.end(), 'S');
    if (numS == 0) return 0;
    if (numS > D) return -1;
    
    int ret(0);
    while (eval(s) > D)
    {
        ++ret;
        int idx = s.size()-1;
        while (s[idx] == 'S' && s[idx-1] == 'S') --idx;
        swap(s[idx], s[idx-1]);
        
        while (!s.empty() & s[s.size() - 1] == 'C')
            s.resize(s.size()-1);
    }
    
	return ret;
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
			cout << "Case #" << zz << ": " << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << zz << ": " << ret << endl;
		}
		
	}

	return 0;
}
